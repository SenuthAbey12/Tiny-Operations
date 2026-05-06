/****************************************************************
              Copyright (C) 1986 by Manuel E. Bermudez
              Translated to C - 1991
*****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <header/Open_File.h>
#include <header/CommandLine.h>
#include <header/Table.h>
#include <header/Text.h>
#include <header/Error.h>
#include <header/String_Input.h>
#include <header/Tree.h>
#include <header/Dcln.h>
#include <header/Constrainer.h>

#define ProgramNode 1
#define TypesNode 2
#define TypeNode 3
#define DclnsNode 4
#define DclnNode 5
#define IntegerTNode 6
#define BooleanTNode 7
#define BlockNode 8
#define AssignNode 9
#define OutputNode 10
#define IfNode 11
#define WhileNode 12
#define NullNode 13
#define LENode 14
#define PlusNode 15
#define MinusNode 16
#define ModNode 17
#define NotNode 18
#define ReadNode 19
#define IntegerNode 20
#define IdentifierNode 21
#define EqNode 22
#define NeNode 23
#define GteNode 24
#define LtNode 25
#define GtNode 26
#define OrNode 27
#define MultNode 28
#define DivNode 29
#define AndNode 30
#define ExpNode 31
#define TrueNode 32
#define FalseNode 33
#define EofNode 34
#define ForNode 35
#define DowntoNode 36
#define SwapNode 37
#define RepeatNode 38
#define LoopNode 39
#define ExitNode 40
#define CaseNode 41
#define CaseclNode 42
#define RangeNode 43
#define CharTNode 44
#define ConstsNode 45
#define ConstNode 46
#define CharNode 47
#define StringNode 48
#define EnumNode 49
#define SuccNode 50
#define PredNode 51
#define OrdNode 52
#define ChrNode 53

#define NumberOfNodes 53

#define PrimitiveIntegerType 90001
#define PrimitiveBooleanType 90002
#define PrimitiveCharType 90003
#define EnumLiteralBase 100000

typedef TreeNode UserType;

/****************************************************************
 Add new node names to the end of the array, keeping in strict
  order with the define statements above, then adjust the i loop
  control variable in InitializeConstrainer().
*****************************************************************/
char *node[] = {"program", "types", "type", "dclns",
                "dcln", "integer", "boolean", "block",
                "assign", "output", "if", "while",
                "<null>", "<=", "+", "-", "mod", "not", "read",
                "<integer>", "<identifier>", "=", "<>", ">=",
                "<", ">", "or", "*", "/", "and", "**",
                "true", "false", "eof",
                "for", "downto",
                "swap", "repeat", "loop", "exit",
                "case", "caseclause", "..",
                "char", "consts", "const", "<char>", "<string>",
                "enum", "succ", "pred", "ord", "chr"};

UserType TypeInteger, TypeBoolean, TypeChar;
boolean TraceSpecified;
FILE *TraceFile;
char *TraceFileName;
int NumberTreesRead, index;
int ErrorCount = 0;
TreeNode ActiveLoopControl[200];
int ActiveLoopDepth;
boolean ExitAllowed;
int ForDepth;
int LoopDepth;
boolean ExitSeenInLoop[200];

UserType Expression(TreeNode T);
void ProcessNode(TreeNode T);
void ErrorHeader(TreeNode T);

UserType RememberType(TreeNode T, UserType Type)
{
   Decorate(T, Type);
   return Type;
}

int IsEnumLiteralDeclaration(TreeNode Declaration);

int IsPrimitiveType(UserType Type)
{
   return (Type == TypeInteger || Type == TypeBoolean || Type == TypeChar);
}

int IsEnumType(UserType Type)
{
   return (Type != NullTree && Type != TypeInteger &&
           Type != TypeBoolean && Type != TypeChar);
}

int IsOrdinalType(UserType Type)
{
   return (Type == TypeInteger || Type == TypeChar || Type == TypeBoolean ||
           IsEnumType(Type));
}

int IsVariableDeclaration(TreeNode Declaration)
{
   return (Declaration != NullDeclaration &&
           NodeName(Declaration) == IdentifierNode &&
           !IsEnumLiteralDeclaration(Declaration));
}

int IsEnumLiteralDeclaration(TreeNode Declaration)
{
   return (Declaration != NullDeclaration &&
           NodeName(Declaration) == IdentifierNode &&
           Decoration(Declaration) > EnumLiteralBase);
}

int IsConstDeclaration(TreeNode Declaration)
{
   return (Declaration != NullDeclaration &&
           NodeName(Declaration) == ConstNode);
}

String TypeSpecName(TreeNode T)
{
   if (NodeName(T) == IdentifierNode)
      return NodeName(Child(T, 1));
   return NodeName(T);
}

String TypeDeclarationName(TreeNode T)
{
   return TypeSpecName(Child(T, 1));
}

UserType ResolveTypeSpec(TreeNode T)
{
   TreeNode Declaration;

   switch (NodeName(T))
   {
   case IntegerTNode:
      return TypeInteger;
   case BooleanTNode:
      return TypeBoolean;
   case CharTNode:
      return TypeChar;
   }

   Declaration = Lookup(TypeSpecName(T), T);
   if (Declaration == NullDeclaration)
      return TypeInteger;

   if (NodeName(Declaration) != TypeNode)
   {
      ErrorHeader(T);
      printf("IDENTIFIER IS NOT A TYPE NAME\n\n");
      return TypeInteger;
   }

   if (Decoration(Declaration) != NullTree)
      return Decoration(Declaration);

   return Declaration;
}

UserType IdentifierDeclarationType(TreeNode Declaration)
{
   if (IsConstDeclaration(Declaration))
      return Decoration(Declaration);
   if (IsEnumLiteralDeclaration(Declaration))
      return Decoration(Declaration) - EnumLiteralBase;
   return Decoration(Declaration);
}

UserType ConstantType(TreeNode T)
{
   switch (NodeName(T))
   {
   case IntegerNode:
      return TypeInteger;
   case CharNode:
      return TypeChar;
   case TrueNode:
   case FalseNode:
      return TypeBoolean;
   case IdentifierNode:
   {
      TreeNode Declaration = Lookup(NodeName(Child(T, 1)), T);
      if (Declaration == NullDeclaration)
         return TypeInteger;
      Decorate(T, Declaration);
      if (IsVariableDeclaration(Declaration) || NodeName(Declaration) == TypeNode)
      {
         ErrorHeader(T);
         printf("CASE LABEL OR CONSTANT VALUE MUST BE A CONSTANT\n\n");
         return TypeInteger;
      }
      Decorate(Child(T, 1), IdentifierDeclarationType(Declaration));
      return IdentifierDeclarationType(Declaration);
   }
   default:
      return Expression(T);
   }
}

boolean ActiveLoopContains(TreeNode Declaration)
{
   int i;

   for (i = 1; i <= ActiveLoopDepth; i++)
      if (ActiveLoopControl[i] == Declaration)
         return true;

   return false;
}

void PushActiveLoopControl(TreeNode Declaration)
{
   if (Declaration == NullDeclaration)
      return;

   if (ActiveLoopDepth < 199)
   {
      ActiveLoopDepth++;
      ActiveLoopControl[ActiveLoopDepth] = Declaration;
   }
}

void PopActiveLoopControl(TreeNode Declaration)
{
   if (Declaration == NullDeclaration)
      return;

   if (ActiveLoopDepth > 0)
      ActiveLoopDepth--;
}

TreeNode LoopControlDeclaration(TreeNode T)
{
   if (NodeName(T) == IdentifierNode)
      return Decoration(T);

   return NullDeclaration;
}

UserType CaseValueType(TreeNode T)
{
   switch (NodeName(T))
   {
   case IntegerNode:
      return TypeInteger;

   case CharNode:
      return TypeChar;

   case TrueNode:
   case FalseNode:
   case EofNode:
      return TypeBoolean;

   case IdentifierNode:
      return ConstantType(T);

   case RangeNode:
   {
      UserType Type1 = ConstantType(Child(T, 1));
      UserType Type2 = ConstantType(Child(T, 2));
      if (Type1 != Type2)
      {
         ErrorHeader(T);
         printf("CASE RANGE LIMITS MUST BE SAME TYPE\n\n");
      }
      return Type1;
   }

   default:
      return TypeInteger;
   }
}

void Constrain(void)
{
   int i;
   ActiveLoopDepth = 0;
   ExitAllowed = false;
   ForDepth = 0;
   LoopDepth = 0;
   InitializeDeclarationTable();
   Tree_File = Open_File("_TREE", "r");
   NumberTreesRead = Read_Trees();
   fclose(Tree_File);
   AddIntrinsics();

   ProcessNode(RootOfTree(1));

#if 0
   PrintDclnTable(stdout);
   PrintAllStrings(stdout);
   PrintTree(stdout,RootOfTree(1));
#endif

   if (TraceSpecified)
      fclose(TraceFile);
   if (ErrorCount > 0)
   {
      remove("_TREE"); /* prevent CodeGen from using a type-incorrect tree */
      remove("_CODE"); /* prevent Interpreter from using stale code */
      kill(getppid(), SIGTERM);
      return;
   }
   Tree_File = fopen("_TREE", "w");
   Write_Trees();
   fclose(Tree_File);
}

void InitializeConstrainer(int argc, char *argv[])
{
   int i, j;
   InitializeTextModule();
   InitializeTreeModule();
   for (i = 0, j = 1; i < NumberOfNodes; i++, j++)
      String_Array_To_String_Constant(node[i], j);
   index = System_Flag("-trace", argc, argv);
   if (index)
   {
      TraceSpecified = true;
      TraceFileName = System_Argument("-trace", "_TRACE", argc, argv);
      TraceFile = Open_File(TraceFileName, "w");
   }
   else
      TraceSpecified = false;
}

void AddIntrinsics(void)
{
   TypeInteger = PrimitiveIntegerType;
   TypeBoolean = PrimitiveBooleanType;
   TypeChar = PrimitiveCharType;
}

void ErrorHeader(TreeNode T)
{
   ErrorCount++;
   printf("<<< CONSTRAINER ERROR >>> AT ");
   Write_String(stdout, SourceLocation(T));
   printf(" : ");
   printf("\n");
}

int NKids(TreeNode T)
{
   return (Rank(T));
}

UserType Expression(TreeNode T)
{
   UserType Type1, Type2;
   TreeNode Declaration, Temp1, Temp2;
   int NodeCount;
   if (TraceSpecified)
   {
      fprintf(TraceFile, "<<< CONSTRAINER >>> : Expn Processor Node ");
      Write_String(TraceFile, NodeName(T));
      fprintf(TraceFile, "\n");
   }

   switch (NodeName(T))
   {
   case LENode:
   case EqNode:
   case NeNode:
   case GteNode:
   case LtNode:
   case GtNode:
      Type1 = Expression(Child(T, 1));
      Type2 = Expression(Child(T, 2));
      if (Type1 != Type2)
      {
         ErrorHeader(Child(T, 1));
         printf("ARGUMENTS OF COMPARISON OPERATORS MUST BE SAME TYPE\n");
         printf("\n");
      }
      return RememberType(T, TypeBoolean);

   case PlusNode:
   case MinusNode:
   case ModNode:
   case MultNode:
   case DivNode:
   case ExpNode:
      Type1 = Expression(Child(T, 1));
      if (Rank(T) == 2)
         Type2 = Expression(Child(T, 2));
      else
         Type2 = TypeInteger;
      if (Type1 != TypeInteger || Type2 != TypeInteger)
      {
         ErrorHeader(Child(T, 1));
         printf("ARGUMENTS OF ARITHMETIC OPERATORS ");
         printf("MUST BE TYPE INTEGER\n");
         printf("\n");
      }
      return RememberType(T, TypeInteger);

   case OrNode:
   case AndNode:
      Type1 = Expression(Child(T, 1));
      Type2 = Expression(Child(T, 2));
      if (Type1 != TypeBoolean || Type2 != TypeBoolean)
      {
         ErrorHeader(Child(T, 1));
         printf("ARGUMENTS OF 'and', 'or' MUST BE TYPE BOOLEAN\n");
         printf("\n");
      }
      return RememberType(T, TypeBoolean);

   case NotNode:
      Type1 = Expression(Child(T, 1));
      if (Type1 != TypeBoolean)
      {
         ErrorHeader(Child(T, 1));
         printf("ARGUMENT OF 'not' MUST BE TYPE BOOLEAN\n");
         printf("\n");
      }
      return RememberType(T, TypeBoolean);

   case EofNode:
   case TrueNode:
   case FalseNode:
      return RememberType(T, TypeBoolean);

   case IntegerNode:
      return RememberType(T, TypeInteger);

   case CharNode:
      return RememberType(T, TypeChar);

   case SuccNode:
   case PredNode:
      Type1 = Expression(Child(T, 1));
      if (!IsOrdinalType(Type1))
      {
         ErrorHeader(Child(T, 1));
         printf("ARGUMENT OF 'succ' OR 'pred' MUST BE AN ORDINAL TYPE\n\n");
      }
      return RememberType(T, Type1);

   case OrdNode:
      Type1 = Expression(Child(T, 1));
      if (!IsOrdinalType(Type1))
      {
         ErrorHeader(Child(T, 1));
         printf("ARGUMENT OF 'ord' MUST BE AN ORDINAL TYPE\n\n");
      }
      return RememberType(T, TypeInteger);

   case ChrNode:
      Type1 = Expression(Child(T, 1));
      if (Type1 != TypeInteger)
      {
         ErrorHeader(Child(T, 1));
         printf("ARGUMENT OF 'chr' MUST BE TYPE INTEGER\n\n");
      }
      return RememberType(T, TypeChar);

   case IdentifierNode:
      Declaration = Lookup(NodeName(Child(T, 1)), T);
      if (Declaration != NullDeclaration)
      {
         Decorate(T, Declaration);
         if (NodeName(Declaration) == TypeNode)
         {
            ErrorHeader(T);
            printf("TYPE NAME USED AS AN EXPRESSION\n\n");
            Type1 = Decoration(Declaration);
            Decorate(Child(T, 1), Type1);
            return Type1;
         }
         Type1 = IdentifierDeclarationType(Declaration);
         Decorate(Child(T, 1), Type1);
         return Type1;
      }
      else
      {
         ErrorCount++;
         return RememberType(T, TypeInteger);
      }

   default:
      ErrorHeader(T);
      printf("UNKNOWN NODE NAME ");
      Write_String(stdout, NodeName(T));
      printf("\n");

   } /* end switch */
} /* end Expression */

void ProcessNode(TreeNode T)
{
   int Kid, N;
   String Name1, Name2;
   TreeNode Type1, Type2, Type3;
   if (TraceSpecified)
   {
      fprintf(TraceFile,
              "<<< CONSTRAINER >>> : Stmt Processor Node ");
      Write_String(TraceFile, NodeName(T));
      fprintf(TraceFile, "\n");
   }

   switch (NodeName(T))
   {
   case ProgramNode:
      Name1 = NodeName(Child(Child(T, 1), 1));
      Name2 = NodeName(Child(Child(T, NKids(T)), 1));
      if (Name1 != Name2)
      {
         ErrorHeader(T);
         printf("PROGRAM NAMES DO NOT MATCH\n");
         printf("\n");
      }
      for (Kid = 2; Kid <= NKids(T) - 1; Kid++)
         ProcessNode(Child(T, Kid));
      break;

   case ConstsNode:
      for (Kid = 1; Kid <= NKids(T); Kid++)
         ProcessNode(Child(T, Kid));
      break;

   case ConstNode:
      Type1 = ConstantType(Child(T, 2));
      DTEnter(NodeName(Child(Child(T, 1), 1)), T, T);
      Decorate(T, Type1);
      break;

   case TypesNode:
      for (Kid = 1; Kid <= NKids(T); Kid++)
         ProcessNode(Child(T, Kid));
      break;

   case TypeNode:
      DTEnter(TypeDeclarationName(T), T, T);
      if (NKids(T) == 1)
         Decorate(T, T);
      else if (NodeName(Child(T, 2)) == EnumNode)
      {
         Decorate(T, T);
         for (Kid = 1; Kid <= NKids(Child(T, 2)); Kid++)
         {
            Type1 = Child(Child(T, 2), Kid);
            DTEnter(NodeName(Child(Type1, 1)), Type1, T);
            Decorate(Type1, EnumLiteralBase + T);
         }
      }
      else
         Decorate(T, ResolveTypeSpec(Child(T, 2)));
      break;

   case DclnsNode:
      for (Kid = 1; Kid <= NKids(T); Kid++)
         ProcessNode(Child(T, Kid));
      break;

   case DclnNode:

      Name1 = TypeSpecName(Child(T, NKids(T)));
      Type1 = ResolveTypeSpec(Child(T, NKids(T)));
      for (Kid = 1; Kid < NKids(T); Kid++)
      {
         DTEnter(NodeName(Child(Child(T, Kid), 1)), Child(T, Kid), T);
         Decorate(Child(T, Kid), Type1);
      }
      break;

   case BlockNode:
      for (Kid = 1; Kid <= NKids(T); Kid++)
         ProcessNode(Child(T, Kid));
      break;

   case AssignNode:
      Type1 = Expression(Child(T, 1));
      Type2 = Expression(Child(T, 2));
      if (Type1 != Type2)
      {
         ErrorHeader(T);
         printf("ASSIGNMENT TYPES DO NOT MATCH\n");
         printf("\n");
      }
      if (!IsVariableDeclaration(Decoration(Child(T, 1))))
      {
         ErrorHeader(Child(T, 1));
         printf("LEFT SIDE OF ASSIGNMENT MUST BE A VARIABLE\n\n");
      }
      Type3 = LoopControlDeclaration(Child(T, 1));
      if (Type3 != NullDeclaration && ActiveLoopContains(Type3))
      {
         ErrorHeader(Child(T, 1));
         printf("CAN'T ASSIGN TO LOOP CONTROL VARIABLE\n");
         printf("\n");
      }
      break;

   case OutputNode:
      for (Kid = 1; Kid <= NKids(T); Kid++)
      {
         if (NodeName(Child(T, Kid)) == StringNode)
            continue;
         Type1 = Expression(Child(T, Kid));
         if (Type1 != TypeInteger && Type1 != TypeChar)
         {
            ErrorHeader(T);
            printf("OUTPUT EXPRESSION MUST BE TYPE INTEGER OR CHAR\n");
            printf("\n");
         }
      }
      break;

   case ReadNode:
      for (Kid = 1; Kid <= NKids(T); Kid++)
      {
         Type1 = Expression(Child(T, Kid));
         Type3 = LoopControlDeclaration(Child(T, Kid));
         if (Type3 != NullDeclaration && ActiveLoopContains(Type3))
         {
            ErrorHeader(Child(T, Kid));
            printf("CAN'T READ INTO LOOP CONTROL VARIABLE\n\n");
         }
         if (!IsVariableDeclaration(Decoration(Child(T, Kid))))
         {
            ErrorHeader(Child(T, Kid));
            printf("READ ARGUMENT MUST BE A VARIABLE\n\n");
         }
         if (Type1 != TypeInteger && Type1 != TypeChar)
         {
            ErrorHeader(Child(T, Kid));
            printf("READ VARIABLE MUST BE TYPE INTEGER OR CHAR\n\n");
         }
      }
      break;

   case IfNode:
      if (Expression(Child(T, 1)) != TypeBoolean)
      {
         ErrorHeader(T);
         printf("CONTROL EXPRESSION OF 'IF' STMT");
         printf(" IS NOT TYPE BOOLEAN\n");
         printf("\n");
      }
      ProcessNode(Child(T, 2));
      if (Rank(T) == 3)
         ProcessNode(Child(T, 3));
      break;

   case WhileNode:
      if (Expression(Child(T, 1)) != TypeBoolean)
      {
         ErrorHeader(T);
         printf("WHILE EXPRESSION NOT OF TYPE BOOLEAN\n");
         printf("\n");
      }
      ProcessNode(Child(T, 2));
      break;

   case NullNode:
      break;

   case ForNode:
   case DowntoNode:
   {
      TreeNode ControlDeclaration;
      boolean SavedExitAllowed;
      UserType ControlType, StartType, EndType;

      ControlType = Expression(Child(T, 1));
      StartType = Expression(Child(T, 2));
      if (!IsOrdinalType(ControlType) ||
          ControlType != StartType ||
          !IsVariableDeclaration(Decoration(Child(T, 1))))
      {
         ErrorHeader(T);
         printf("FOR LOOP VARIABLE AND START VALUE MUST BE SAME ORDINAL TYPE\n");
         printf("\n");
      }
      EndType = Expression(Child(T, 3));
      if (ControlType != EndType)
      {
         ErrorHeader(T);
         printf("FOR LOOP END VALUE MUST MATCH LOOP VARIABLE TYPE\n");
         printf("\n");
      }

      ControlDeclaration = Decoration(Child(T, 1));
      if (ControlDeclaration != NullDeclaration &&
          ActiveLoopContains(ControlDeclaration))
      {
         ErrorHeader(Child(T, 1));
         printf("CAN'T RE-USE LOOP CONTROL VARIABLE\n");
         printf("\n");
      }

      PushActiveLoopControl(ControlDeclaration);
      ForDepth++;
      SavedExitAllowed = ExitAllowed;
      ExitAllowed = false;
      ProcessNode(Child(T, 4)); /* loop body */
      ExitAllowed = SavedExitAllowed;
      ForDepth--;
      PopActiveLoopControl(ControlDeclaration);
      break;
   }

   case SwapNode:
      Type1 = Expression(Child(T, 1));
      Type2 = Expression(Child(T, 2));
      if (Type1 != Type2)
      {
         ErrorHeader(T);
         printf("SWAP OPERANDS MUST BE SAME TYPE\n");
         printf("\n");
      }
      Type3 = LoopControlDeclaration(Child(T, 1));
      if (Type3 != NullDeclaration && ActiveLoopContains(Type3))
      {
         ErrorHeader(Child(T, 1));
         printf("CAN'T SWAP WITH LOOP CONTROL VARIABLE\n");
         printf("\n");
      }
      Type3 = LoopControlDeclaration(Child(T, 2));
      if (Type3 != NullDeclaration && ActiveLoopContains(Type3))
      {
         ErrorHeader(Child(T, 2));
         printf("CAN'T SWAP WITH LOOP CONTROL VARIABLE\n");
         printf("\n");
      }
      break;

   case RepeatNode:
      for (Kid = 1; Kid < NKids(T); Kid++)
         ProcessNode(Child(T, Kid));
      if (Expression(Child(T, NKids(T))) != TypeBoolean)
      {
         ErrorHeader(T);
         printf("REPEAT-UNTIL EXPRESSION NOT OF TYPE BOOLEAN\n");
         printf("\n");
      }
      break;

   case LoopNode:
   {
      boolean SavedExitAllowed;

      LoopDepth++;
      ExitSeenInLoop[LoopDepth] = false;
      SavedExitAllowed = ExitAllowed;
      ExitAllowed = true;
      for (Kid = 1; Kid <= NKids(T); Kid++)
         ProcessNode(Child(T, Kid));
      ExitAllowed = SavedExitAllowed;
      if (!ExitSeenInLoop[LoopDepth])
      {
         ErrorHeader(T);
         printf("LOOP STATEMENT HAS NO EXIT\n");
         printf("\n");
      }
      LoopDepth--;
      break;
   }

   case ExitNode:
      if (!ExitAllowed)
      {
         ErrorHeader(T);
         if (ForDepth > 0)
            printf("CAN'T EXIT FROM FOR LOOP\n");
         else
            printf("WRONG CONTEXT FOR EXIT: NOT INSIDE A LOOP STATEMENT\n");
         printf("\n");
      }
      else if (ForDepth == 0 && LoopDepth > 0)
         ExitSeenInLoop[LoopDepth] = true;
      else if (LoopDepth > 0)
         ExitSeenInLoop[LoopDepth] = true;
      break;

   case CaseNode:
   {
      int hasOtherwise, lastClauseKid;
      UserType SelectorType, LabelType;
      TreeNode ClauseNode, CaseValueNode;
      hasOtherwise = (NKids(T) > 1 &&
                      NodeName(Child(T, NKids(T))) != CaseclNode);
      lastClauseKid = hasOtherwise ? NKids(T) - 1 : NKids(T);

      SelectorType = Expression(Child(T, 1));
      if (!IsOrdinalType(SelectorType))
      {
         ErrorHeader(T);
         printf("CASE EXPRESSION MUST BE AN ORDINAL TYPE\n");
         printf("\n");
      }

      for (Kid = 2; Kid <= lastClauseKid; Kid++)
      {
         ClauseNode = Child(T, Kid);
         CaseValueNode = Child(ClauseNode, 1);
         LabelType = CaseValueType(CaseValueNode);
         if (LabelType != SelectorType)
         {
            ErrorHeader(CaseValueNode);
            printf("CASE VARIABLE AND LABEL TYPE MISMATCH\n");
            printf("\n");
         }
         ProcessNode(Child(ClauseNode, 2));
      }

      if (hasOtherwise)
         ProcessNode(Child(T, NKids(T)));
      break;
   }

   default:
      ErrorHeader(T);
      printf("UNKNOWN NODE NAME ");
      Write_String(stdout, NodeName(T));
      printf("\n");

   } /* end switch */
} /* end ProcessNode */
