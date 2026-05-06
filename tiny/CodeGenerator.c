/*******************************************************************
          Copyright (C) 1986 by Manuel E. Bermudez
          Translated to C - 1991
********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <header/CommandLine.h>
#include <header/Open_File.h>
#include <header/Table.h>
#include <header/Text.h>
#include <header/Error.h>
#include <header/String_Input.h>
#include <header/Tree.h>
#include <header/Code.h>
#include <header/CodeGenerator.h>
#define LeftMode 0
#define RightMode 1

/*  ABSTRACT MACHINE OPERATIONS  */
#define NOP 1      /* 'NOP'       */
#define HALTOP 2   /* 'HALT'      */
#define LITOP 3    /* 'LIT'       */
#define LLVOP 4    /* 'LLV'       */
#define LGVOP 5    /* 'LGV'       */
#define SLVOP 6    /* 'SLV'       */
#define SGVOP 7    /* 'SGV'       */
#define LLAOP 8    /* 'LLA'       */
#define LGAOP 9    /* 'LGA'       */
#define UOPOP 10   /* 'UOP'       */
#define BOPOP 11   /* 'BOP'       */
#define POPOP 12   /* 'POP'       */
#define DUPOP 13   /* 'DUP'       */
#define SWAPOP 14  /* 'SWAP'      */
#define CALLOP 15  /* 'CALL'      */
#define RTNOP 16   /* 'RTN'       */
#define GOTOOP 17  /* 'GOTO'      */
#define CONDOP 18  /* 'COND'      */
#define CODEOP 19  /* 'CODE'      */
#define SOSOP 20   /* 'SOS'       */
#define LIMITOP 21 /* 'LIMIT'     */

/* ABSTRACT MACHINE OPERANDS */

/* UNARY OPERANDS */
#define UNOT 22      /* 'UNOT'     */
#define UNEG 23      /* 'UNEG'     */
#define USUCC 24     /* 'USUCC'    */
#define UPRED 25     /* 'UPRED'    */
                     /* BINARY OPERANDS */
#define BAND 26      /* 'BAND'     */
#define BOR 27       /* 'BOR'      */
#define BPLUS 28     /* 'BPLUS'    */
#define BMINUS 29    /* 'BMINUS'   */
#define BMULT 30     /* 'BMULT'    */
#define BDIV 31      /* 'BDIV'     */
#define BEXP 32      /* 'BEXP'     */
#define BMOD 33      /* 'BMOD'     */
#define BEQ 34       /* 'BEQ'      */
#define BNE 35       /* 'BNE'      */
#define BLE 36       /* 'BLE'      */
#define BGE 37       /* 'BGE'      */
#define BLT 38       /* 'BLT'      */
#define BGT 39       /* 'BGT'      */
                     /* OS SERVICE CALL OPERANDS */
#define TRACEX 40    /* 'TRACEX'   */
#define DUMPMEM 41   /* 'DUMPMEM'  */
#define OSINPUT 42   /* 'INPUT'    */
#define OSINPUTC 43  /* 'INPUT'    */
#define OSOUTPUT 44  /* 'OUTPUT'   */
#define OSOUTPUTC 45 /* 'OUTPUT'   */
#define OSOUTPUTL 46 /* 'OUTPUTL'  */
#define OSEOF 47     /* 'EOF'      */

/* TREE NODE NAMES */
#define ProgramNode 48    /* 'program'  */
#define TypesNode 49      /* 'types'    */
#define TypeNode 50       /* 'type'     */
#define DclnsNode 51      /* 'dclns'    */
#define DclnNode 52       /* 'dcln'     */
#define IntegerTNode 53   /* 'integer'  */
#define BooleanTNode 54   /* 'boolean'  */
#define BlockNode 55      /* 'block'    */
#define AssignNode 56     /* 'assign'   */
#define OutputNode 57     /* 'output'   */
#define IfNode 58         /* 'if'       */
#define WhileNode 59      /* 'while'    */
#define NullNode 60       /* '<null>'   */
#define LENode 61         /* '<='       */
#define PlusNode 62       /* '+'        */
#define MinusNode 63      /* '-'        */
#define ModNode 64        /* 'mod'      */
#define NotNode 65        /* 'not'      */
#define ReadNode 66       /* 'read'     */
#define IntegerNode 67    /* '<integer>'*/
#define IdentifierNode 68 /* '<identifier>'*/
#define EqNode 69         /* '='        */
#define NeNode 70         /* '<>'       */
#define GteNode 71        /* '>='       */
#define LtNode 72         /* '<'        */
#define GtNode 73         /* '>'        */
#define OrNode 74         /* 'or'       */
#define MultNode 75       /* '*'        */
#define DivNode 76        /* '/'        */
#define AndNode 77        /* 'and'      */
#define ExpNode 78        /* '**'       */
#define TrueNode 79       /* 'true'     */
#define FalseNode 80      /* 'false'    */
#define EofNode 81        /* 'eof'      */
#define ForNode 82        /* 'for'      */
#define DowntoNode 83     /* 'downto'   */
#define SwapNode 84       /* 'swap'     */
#define RepeatNode 85     /* 'repeat'   */
#define LoopNode 86       /* 'loop'     */
#define ExitNode 87       /* 'exit'     */
#define CaseNode 88       /* 'case'     */
#define CaseclNode 89     /* 'caseclause'*/
#define RangeNode 90      /* '..'       */
#define CharTNode 91      /* 'char'     */
#define ConstsNode 92     /* 'consts'   */
#define ConstNode 93      /* 'const'    */
#define CharNode 94       /* '<char>'   */
#define StringNode 95     /* '<string>' */
#define EnumNode 96       /* 'enum'     */
#define SuccNode 97       /* 'succ'     */
#define PredNode 98       /* 'pred'     */
#define OrdNode 99        /* 'ord'      */
#define ChrNode 100       /* 'chr'      */

#define NumberOfNodes 100 /* 'chr'*/
#define PrimitiveIntegerType 90001
#define PrimitiveBooleanType 90002
#define PrimitiveCharType 90003
#define EnumLiteralBase 100000
typedef int Mode;

FILE *CodeFile;
char *CodeFileName;
Clabel HaltLabel;
Clabel LoopExitLabel;

char *mach_op[] =
    {"NOP", "HALT", "LIT", "LLV", "LGV", "SLV", "SGV", "LLA", "LGA",
     "UOP", "BOP", "POP", "DUP", "SWAP", "CALL", "RTN", "GOTO", "COND",
     "CODE", "SOS", "LIMIT", "UNOT", "UNEG", "USUCC", "UPRED", "BAND",
     "BOR", "BPLUS", "BMINUS", "BMULT", "BDIV", "BEXP", "BMOD", "BEQ",
     "BNE", "BLE", "BGE", "BLT", "BGT", "TRACEX", "DUMPMEM", "INPUT",
     "INPUTC", "OUTPUT", "OUTPUTC", "OUTPUTL", "EOF"};

/******************************************************************
   add new node names to the end of the array, keeping in strict order
   as defined above, then adjust the j loop control variable in
   InitializeNodeNames().
*******************************************************************/
char *node_name[] =
    {"program", "types", "type", "dclns", "dcln", "integer",
     "boolean", "block", "assign", "output", "if", "while",
     "<null>", "<=", "+", "-", "mod", "not", "read", "<integer>", "<identifier>",
     "=", "<>", ">=", "<", ">", "or", "*", "/", "and", "**",
     "true", "false", "eof", "for", "downto",
     "swap", "repeat", "loop", "exit", "case", "caseclause", "..",
     "char", "consts", "const", "<char>", "<string>", "enum",
     "succ", "pred", "ord", "chr"};

void CodeGenerate(int argc, char *argv[])
{
   int NumberTrees;
   FILE *TreeProbe;

   InitializeCodeGenerator(argc, argv);
   TreeProbe = fopen("_TREE", "r");
   if (TreeProbe == NULL)
   {
      CodeGen0(HALTOP, NoLabel);
      CodeFile = Open_File(CodeFileName, "w");
      DumpCode(CodeFile);
      fclose(CodeFile);
      return;
   }
   fclose(TreeProbe);
   Tree_File = Open_File("_TREE", "r");
   NumberTrees = Read_Trees();
   fclose(Tree_File);

   HaltLabel = ProcessNode(RootOfTree(1), NoLabel);
   CodeGen0(HALTOP, HaltLabel);

#if 0
   PrintAllStrings(stdout);
   PrintTree(stdout,RootOfTree(1));
#endif

   CodeFile = Open_File(CodeFileName, "w");
   DumpCode(CodeFile);
   fclose(CodeFile);

   if (TraceSpecified)
      fclose(TraceFile);

   /******************************************************************
     enable this code to write out the tree after the code generator
     has run.  It will show the new decorations made with MakeAddress().
   *******************************************************************/

   Tree_File = fopen("_TREE", "w");
   Write_Trees();
   fclose(Tree_File);
}

void InitializeCodeGenerator(int argc, char *argv[])
{
   InitializeMachineOperations();
   InitializeNodeNames();
   FrameSize = 0;
   CurrentProcLevel = 0;
   LabelCount = 0;
   CodeFileName = System_Argument("-code", "_CODE", argc, argv);
}

void InitializeMachineOperations(void)
{
   int i, j;

   for (i = 0, j = 1; i < 47; i++, j++)
      String_Array_To_String_Constant(mach_op[i], j);
}

void InitializeNodeNames(void)
{
   int i, j;

   for (i = 0, j = 48; j <= NumberOfNodes; i++, j++)
      String_Array_To_String_Constant(node_name[i], j);
}

String MakeStringOf(int Number)
{
   Stack Temp;

   Temp = AllocateStack(50);
   ResetBufferInTextTable();
   if (Number == 0)
      AdvanceOnCharacter('0');
   else
   {
      while (Number > 0)
      {
         Push(Temp, (Number % 10) + 48);
         Number /= 10;
      }

      while (!(IsEmpty(Temp)))
         AdvanceOnCharacter((char)(Pop(Temp)));
   }
   return (ConvertStringInBuffer());
}

void Reference(TreeNode T, Mode M, Clabel L)
{
   int Addr, OFFSET;
   String Op;

   Addr = Decoration(Decoration(T));
   OFFSET = FrameDisplacement(Addr);
   switch (M)
   {
   case LeftMode:
      DecrementFrameSize();
      if (ProcLevel(Addr) == 0)
         Op = SGVOP;
      else
         Op = SLVOP;
      break;
   case RightMode:
      IncrementFrameSize();
      if (ProcLevel(Addr) == 0)
         Op = LGVOP;
      else
         Op = LLVOP;
      break;
   }
   CodeGen1(Op, MakeStringOf(OFFSET), L);
}

int NKids(TreeNode T)
{
   return (Rank(T));
}

int TypeNameIs(TreeNode Type, int Name)
{
   return (Type > 0 && Type < PrimitiveIntegerType &&
           NodeName(Type) == TypeNode &&
           NKids(Type) >= 1 &&
           NodeName(Child(Type, 1)) == Name);
}

int IsCharType(TreeNode Type)
{
   return (Type == PrimitiveCharType);
}

int IsLimitedType(TreeNode Type)
{
   return (Type == PrimitiveBooleanType) ||
          (Type > 0 && Type < PrimitiveIntegerType &&
           NodeName(Type) == TypeNode &&
           NKids(Type) >= 2 &&
           NodeName(Child(Type, 2)) == EnumNode);
}

TreeNode ExprType(TreeNode T)
{
   if (NodeName(T) == IdentifierNode)
      return Decoration(Child(T, 1));
   return Decoration(T);
}

int TypeUpperBound(TreeNode Type)
{
   if (Type == PrimitiveBooleanType)
      return 1;
   if (Type > 0 && Type < PrimitiveIntegerType &&
       NodeName(Type) == TypeNode &&
       NKids(Type) >= 2 &&
       NodeName(Child(Type, 2)) == EnumNode)
      return NKids(Child(Type, 2)) - 1;
   return 0;
}

void EmitLimit(TreeNode Type)
{
   if (!IsLimitedType(Type))
      return;

   CodeGen1(LITOP, MakeStringOf(0), NoLabel);
   IncrementFrameSize();
   CodeGen1(LITOP, MakeStringOf(TypeUpperBound(Type)), NoLabel);
   IncrementFrameSize();
   CodeGen0(LIMITOP, NoLabel);
   DecrementFrameSize();
   DecrementFrameSize();
}

int CharValue(TreeNode T)
{
   String Text;
   char Ch;

   Text = NodeName(Child(T, 1));
   Ch = Character(Text, 2);
   if (Ch == '\\')
   {
      switch (Character(Text, 3))
      {
      case 'n':
         return (int)'\n';
      case 't':
         return (int)'\t';
      case 'r':
         return (int)'\r';
      case '0':
         return 0;
      case '\\':
         return (int)'\\';
      case '\'':
         return (int)'\'';
      case '"':
         return (int)'"';
      default:
         return (int)Character(Text, 3);
      }
   }
   return (int)Ch;
}

int EscapedCharValue(String Text, int *Index)
{
   char Ch;

   Ch = Character(Text, *Index);
   if (Ch != '\\')
      return (int)Ch;

   (*Index)++;
   switch (Character(Text, *Index))
   {
   case 'n':
      return (int)'\n';
   case 't':
      return (int)'\t';
   case 'r':
      return (int)'\r';
   case '0':
      return 0;
   case '\\':
      return (int)'\\';
   case '\'':
      return (int)'\'';
   case '"':
      return (int)'"';
   default:
      return (int)Character(Text, *Index);
   }
}

int EnumOrdinal(TreeNode Declaration)
{
   TreeNode Type, EnumTree;
   int Kid;

   Type = Decoration(Declaration) - EnumLiteralBase;
   if (Type == NullTree || Type >= PrimitiveIntegerType || NKids(Type) < 2)
      return 0;

   EnumTree = Child(Type, 2);
   for (Kid = 1; Kid <= NKids(EnumTree); Kid++)
      if (Child(EnumTree, Kid) == Declaration)
         return Kid - 1;

   return 0;
}

void EmitConstant(TreeNode T, Clabel CurrLabel)
{
   TreeNode Declaration;

   switch (NodeName(T))
   {
   case IntegerNode:
      CodeGen1(LITOP, NodeName(Child(T, 1)), CurrLabel);
      IncrementFrameSize();
      break;

   case CharNode:
      CodeGen1(LITOP, MakeStringOf(CharValue(T)), CurrLabel);
      IncrementFrameSize();
      break;

   case TrueNode:
      CodeGen1(LITOP, MakeStringOf(1), CurrLabel);
      IncrementFrameSize();
      break;

   case FalseNode:
      CodeGen1(LITOP, MakeStringOf(0), CurrLabel);
      IncrementFrameSize();
      break;

   case IdentifierNode:
      Declaration = Decoration(T);
      if (NodeName(Declaration) == ConstNode)
         EmitConstant(Child(Declaration, 2), CurrLabel);
      else if (Decoration(Declaration) > EnumLiteralBase)
      {
         CodeGen1(LITOP, MakeStringOf(EnumOrdinal(Declaration)), CurrLabel);
         IncrementFrameSize();
      }
      else
         Reference(T, RightMode, CurrLabel);
      break;
   }
}

Clabel EmitString(TreeNode T, Clabel CurrLabel)
{
   String Text;
   int i;
   int Length;
   Clabel Label;

   Text = NodeName(Child(T, 1));
   Length = StringLength(Text);
   Label = CurrLabel;
   for (i = 2; i < Length; i++)
   {
      CodeGen1(LITOP, MakeStringOf(EscapedCharValue(Text, &i)), Label);
      IncrementFrameSize();
      CodeGen1(SOSOP, OSOUTPUTC, NoLabel);
      DecrementFrameSize();
      Label = NoLabel;
   }
   return Label;
}

void EmitCaseValue(TreeNode T, Clabel CurrLabel)
{
   EmitConstant(T, CurrLabel);
}

void Expression(TreeNode T, Clabel CurrLabel)
{
   int Kid;
   Clabel Label1;

   if (TraceSpecified)
   {
      fprintf(TraceFile, "<<< CODE GENERATOR >>> Processing Node ");
      Write_String(TraceFile, NodeName(T));
      fprintf(TraceFile, " , Label is  ");
      Write_String(TraceFile, CurrLabel);
      fprintf(TraceFile, "\n");
   }

   switch (NodeName(T))
   {
   case LENode:
      Expression(Child(T, 1), CurrLabel);
      Expression(Child(T, 2), NoLabel);
      CodeGen1(BOPOP, BLE, NoLabel);
      DecrementFrameSize();
      break;

   case EqNode:
      Expression(Child(T, 1), CurrLabel);
      Expression(Child(T, 2), NoLabel);
      CodeGen1(BOPOP, BEQ, NoLabel);
      DecrementFrameSize();
      break;

   case NeNode:
      Expression(Child(T, 1), CurrLabel);
      Expression(Child(T, 2), NoLabel);
      CodeGen1(BOPOP, BNE, NoLabel);
      DecrementFrameSize();
      break;

   case GteNode:
      Expression(Child(T, 1), CurrLabel);
      Expression(Child(T, 2), NoLabel);
      CodeGen1(BOPOP, BGE, NoLabel);
      DecrementFrameSize();
      break;

   case LtNode:
      Expression(Child(T, 1), CurrLabel);
      Expression(Child(T, 2), NoLabel);
      CodeGen1(BOPOP, BLT, NoLabel);
      DecrementFrameSize();
      break;

   case GtNode:
      Expression(Child(T, 1), CurrLabel);
      Expression(Child(T, 2), NoLabel);
      CodeGen1(BOPOP, BGT, NoLabel);
      DecrementFrameSize();
      break;

   case OrNode:
      Expression(Child(T, 1), CurrLabel);
      Expression(Child(T, 2), NoLabel);
      CodeGen1(BOPOP, BOR, NoLabel);
      DecrementFrameSize();
      break;

   case AndNode:
      Expression(Child(T, 1), CurrLabel);
      Expression(Child(T, 2), NoLabel);
      CodeGen1(BOPOP, BAND, NoLabel);
      DecrementFrameSize();
      break;

   case PlusNode:
   case ModNode:
      Expression(Child(T, 1), CurrLabel);
      if (Rank(T) == 2)
      {
         Expression(Child(T, 2), NoLabel);
         if (NodeName(T) == ModNode)
            CodeGen1(BOPOP, BMOD, NoLabel);
         else
            CodeGen1(BOPOP, BPLUS, NoLabel);
         DecrementFrameSize();
      }
      /* else unary +, do nothing - value already on stack */
      break;

   case MinusNode:
      Expression(Child(T, 1), CurrLabel);
      if (Rank(T) == 2)
      {
         Expression(Child(T, 2), NoLabel);
         CodeGen1(BOPOP, BMINUS, NoLabel);
         DecrementFrameSize();
      }
      else
         CodeGen1(UOPOP, UNEG, NoLabel);
      break;

   case MultNode:
      Expression(Child(T, 1), CurrLabel);
      Expression(Child(T, 2), NoLabel);
      CodeGen1(BOPOP, BMULT, NoLabel);
      DecrementFrameSize();
      break;

   case DivNode:
      Expression(Child(T, 1), CurrLabel);
      Expression(Child(T, 2), NoLabel);
      CodeGen1(BOPOP, BDIV, NoLabel);
      DecrementFrameSize();
      break;

   case ExpNode:
      Expression(Child(T, 1), CurrLabel);
      Expression(Child(T, 2), NoLabel);
      CodeGen1(BOPOP, BEXP, NoLabel);
      DecrementFrameSize();
      break;

   case NotNode:
      Expression(Child(T, 1), CurrLabel);
      CodeGen1(UOPOP, UNOT, NoLabel);
      break;

   case EofNode:
      CodeGen1(SOSOP, OSEOF, CurrLabel);
      IncrementFrameSize();
      break;

   case TrueNode:
      CodeGen1(LITOP, MakeStringOf(1), CurrLabel);
      IncrementFrameSize();
      break;

   case FalseNode:
      CodeGen1(LITOP, MakeStringOf(0), CurrLabel);
      IncrementFrameSize();
      break;

   case IntegerNode:
   case CharNode:
      EmitConstant(T, CurrLabel);
      break;

   case SuccNode:
      Expression(Child(T, 1), CurrLabel);
      CodeGen1(UOPOP, USUCC, NoLabel);
      EmitLimit(Decoration(T));
      break;

   case PredNode:
      Expression(Child(T, 1), CurrLabel);
      CodeGen1(UOPOP, UPRED, NoLabel);
      EmitLimit(Decoration(T));
      break;

   case OrdNode:
   case ChrNode:
      Expression(Child(T, 1), CurrLabel);
      break;

   case IdentifierNode:
      EmitConstant(T, CurrLabel);
      break;

   default:
      ReportTreeErrorAt(T);
      printf("<<< CODE GENERATOR >>> : UNKNOWN NODE NAME ");
      Write_String(stdout, NodeName(T));
      printf("\n");

   } /* end switch */
} /* end Expression */

Clabel ProcessNode(TreeNode T, Clabel CurrLabel)
{
   int Kid, Num;
   Clabel Label1, Label2, Label3, SavedLoopExitLabel;

   if (TraceSpecified)
   {
      fprintf(TraceFile, "<<< CODE GENERATOR >>> Processing Node ");
      Write_String(TraceFile, NodeName(T));
      fprintf(TraceFile, " , Label is  ");
      Write_String(TraceFile, CurrLabel);
      fprintf(TraceFile, "\n");
   }

   switch (NodeName(T))
   {
   case ProgramNode:
      for (Kid = 1; Kid <= NKids(T); Kid++)
         if (NodeName(Child(T, Kid)) == DclnsNode)
            CurrLabel = ProcessNode(Child(T, Kid), CurrLabel);
      for (Kid = 1; Kid <= NKids(T); Kid++)
         if (NodeName(Child(T, Kid)) == BlockNode)
            CurrLabel = ProcessNode(Child(T, Kid), NoLabel);
      return (CurrLabel);

   case ConstsNode:
   case TypesNode:
      for (Kid = 1; Kid <= NKids(T); Kid++)
         CurrLabel = ProcessNode(Child(T, Kid), CurrLabel);
      return (CurrLabel);

   case ConstNode:
   case TypeNode:
      return (CurrLabel);

   case DclnsNode:
      for (Kid = 1; Kid <= NKids(T); Kid++)
         CurrLabel = ProcessNode(Child(T, Kid), CurrLabel);
      if (NKids(T) > 0)
         return (NoLabel);
      else
         return (CurrLabel);

   case DclnNode:
      for (Kid = 1; Kid < NKids(T); Kid++)
      {
         if (Kid != 1)
            CodeGen1(LITOP, MakeStringOf(0), NoLabel);
         else
            CodeGen1(LITOP, MakeStringOf(0), CurrLabel);
         Num = MakeAddress();
         Decorate(Child(T, Kid), Num);
         IncrementFrameSize();
      }
      return (NoLabel);

   case BlockNode:
      for (Kid = 1; Kid <= NKids(T); Kid++)
         CurrLabel = ProcessNode(Child(T, Kid), CurrLabel);
      return (CurrLabel);

   case AssignNode:
      Expression(Child(T, 2), CurrLabel);
      EmitLimit(ExprType(Child(T, 1)));
      Reference(Child(T, 1), LeftMode, NoLabel);
      return (NoLabel);

   case OutputNode:
      Label1 = CurrLabel;
      for (Kid = 1; Kid <= NKids(T); Kid++)
      {
         if (NodeName(Child(T, Kid)) == StringNode)
            Label1 = EmitString(Child(T, Kid), Label1);
         else
         {
            Expression(Child(T, Kid), Label1);
            if (IsCharType(ExprType(Child(T, Kid))))
               CodeGen1(SOSOP, OSOUTPUTC, NoLabel);
            else
               CodeGen1(SOSOP, OSOUTPUT, NoLabel);
            DecrementFrameSize();
            Label1 = NoLabel;
         }
      }
      CodeGen1(SOSOP, OSOUTPUTL, Label1);
      return (NoLabel);

   case ReadNode:
      Label1 = CurrLabel;
      for (Kid = 1; Kid <= NKids(T); Kid++)
      {
         if (IsCharType(ExprType(Child(T, Kid))))
            CodeGen1(SOSOP, OSINPUTC, Label1);
         else
            CodeGen1(SOSOP, OSINPUT, Label1);
         IncrementFrameSize();
         Reference(Child(T, Kid), LeftMode, NoLabel);
         Label1 = NoLabel;
      }
      return (NoLabel);

   case IfNode:
      Expression(Child(T, 1), CurrLabel);
      Label1 = MakeLabel();
      Label2 = MakeLabel();
      Label3 = MakeLabel();
      CodeGen2(CONDOP, Label1, Label2, NoLabel);
      DecrementFrameSize();
      CodeGen1(GOTOOP, Label3, ProcessNode(Child(T, 2), Label1));
      if (Rank(T) == 3)
         CodeGen0(NOP, ProcessNode(Child(T, 3), Label2));
      else
         CodeGen0(NOP, Label2);
      return (Label3);

   case WhileNode:
      if (CurrLabel == NoLabel)
         Label1 = MakeLabel();
      else
         Label1 = CurrLabel;
      Label2 = MakeLabel();
      Label3 = MakeLabel();
      Expression(Child(T, 1), Label1);
      CodeGen2(CONDOP, Label2, Label3, NoLabel);
      DecrementFrameSize();
      CodeGen1(GOTOOP, Label1, ProcessNode(Child(T, 2), Label2));
      return (Label3);

   case NullNode:
      return (CurrLabel);

   case ForNode:
      Expression(Child(T, 2), CurrLabel);
      EmitLimit(ExprType(Child(T, 1)));
      Reference(Child(T, 1), LeftMode, NoLabel);

      Label1 = MakeLabel();
      Label2 = MakeLabel();
      Label3 = MakeLabel();
      /* Condition: i <= end */
      Reference(Child(T, 1), RightMode, Label1);
      Expression(Child(T, 3), NoLabel);
      CodeGen1(BOPOP, BLE, NoLabel);
      DecrementFrameSize();
      CodeGen2(CONDOP, Label2, Label3, NoLabel);
      DecrementFrameSize();
      /* Execute body at Label2; get post-body label */
      Label2 = ProcessNode(Child(T, 4), Label2);
      /* Increment: i := i + 1 */
      Reference(Child(T, 1), RightMode, Label2);
      CodeGen1(LITOP, MakeStringOf(1), NoLabel);
      IncrementFrameSize();
      CodeGen1(BOPOP, BPLUS, NoLabel);
      DecrementFrameSize();
      Reference(Child(T, 1), LeftMode, NoLabel);
      /* Jump back to loop top */
      CodeGen1(GOTOOP, Label1, NoLabel);
      return (Label3);

   case DowntoNode:
      /* for i := start downto end do body -- descending loop */
      /* Initialize: i = start */
      Expression(Child(T, 2), CurrLabel);
      EmitLimit(ExprType(Child(T, 1)));
      Reference(Child(T, 1), LeftMode, NoLabel);
      /* Set up loop labels */
      Label1 = MakeLabel(); /* loop top (condition) */
      Label2 = MakeLabel(); /* body entry */
      Label3 = MakeLabel(); /* loop exit */
      /* Condition: i >= end */
      Reference(Child(T, 1), RightMode, Label1);
      Expression(Child(T, 3), NoLabel);
      CodeGen1(BOPOP, BGE, NoLabel);
      DecrementFrameSize();
      CodeGen2(CONDOP, Label2, Label3, NoLabel);
      DecrementFrameSize();
      /* Execute body at Label2; get post-body label */
      Label2 = ProcessNode(Child(T, 4), Label2);
      /* Decrement: i := i - 1 */
      Reference(Child(T, 1), RightMode, Label2);
      CodeGen1(LITOP, MakeStringOf(1), NoLabel);
      IncrementFrameSize();
      CodeGen1(BOPOP, BMINUS, NoLabel);
      DecrementFrameSize();
      Reference(Child(T, 1), LeftMode, NoLabel);
      /* Jump back to loop top */
      CodeGen1(GOTOOP, Label1, NoLabel);
      return (Label3);

   case SwapNode:
      Reference(Child(T, 1), RightMode, CurrLabel);
      Reference(Child(T, 2), RightMode, NoLabel);
      Reference(Child(T, 1), LeftMode, NoLabel);
      Reference(Child(T, 2), LeftMode, NoLabel);
      return (NoLabel);

   case RepeatNode:
   {
      Clabel BodyLabel;

      if (CurrLabel == NoLabel)
         Label1 = MakeLabel();
      else
         Label1 = CurrLabel;
      Label2 = MakeLabel();

      BodyLabel = Label1;
      for (Kid = 1; Kid < NKids(T); Kid++)
         BodyLabel = ProcessNode(Child(T, Kid), BodyLabel);

      Expression(Child(T, NKids(T)), BodyLabel);

      CodeGen2(CONDOP, Label2, Label1, NoLabel);
      DecrementFrameSize();
      return (Label2);
   }

   case LoopNode:

      if (CurrLabel == NoLabel)
         Label1 = MakeLabel();
      else
         Label1 = CurrLabel;
      Label2 = MakeLabel();
      SavedLoopExitLabel = LoopExitLabel; /* save for nested loops */
      LoopExitLabel = Label2;
      Label3 = Label1;
      for (Kid = 1; Kid <= NKids(T); Kid++)
         Label3 = ProcessNode(Child(T, Kid), Label3);
      CodeGen1(GOTOOP, Label1, Label3);
      LoopExitLabel = SavedLoopExitLabel;
      return (Label2);

   case ExitNode:
      /* jump out of the immediately enclosing loop-pool */
      CodeGen1(GOTOOP, LoopExitLabel, CurrLabel);
      return (NoLabel);

   case CaseNode:
   {
      int hasOtherwise, lastClauseKid;
      Clabel endLabel, bodyLabel, nextLabel, prevNextLabel, checkHighLabel;
      TreeNode clause, caseVal, bodyStmt;

      hasOtherwise = (NKids(T) > 1 &&
                      NodeName(Child(T, NKids(T))) != CaseclNode);
      lastClauseKid = hasOtherwise ? NKids(T) - 1 : NKids(T);
      endLabel = MakeLabel();
      prevNextLabel = NoLabel;

      Expression(Child(T, 1), CurrLabel); /* evaluate selector; stack: [sel] */

      for (Kid = 2; Kid <= lastClauseKid; Kid++)
      {
         clause = Child(T, Kid);
         caseVal = Child(clause, 1);
         bodyStmt = Child(clause, 2);
         bodyLabel = MakeLabel();
         nextLabel = MakeLabel();

         if (NodeName(caseVal) == RangeNode)
         {
            /* range test: sel >= lo AND sel <= hi */
            checkHighLabel = MakeLabel();
            CodeGen0(DUPOP, prevNextLabel);
            IncrementFrameSize();
            EmitCaseValue(Child(caseVal, 1), NoLabel);
            CodeGen1(BOPOP, BGE, NoLabel);
            DecrementFrameSize();
            CodeGen2(CONDOP, checkHighLabel, nextLabel, NoLabel);
            DecrementFrameSize();
            CodeGen0(DUPOP, checkHighLabel);
            IncrementFrameSize();
            EmitCaseValue(Child(caseVal, 2), NoLabel);
            CodeGen1(BOPOP, BLE, NoLabel);
            DecrementFrameSize();
            CodeGen2(CONDOP, bodyLabel, nextLabel, NoLabel);
            DecrementFrameSize();
         }
         else
         {
            /* single-value test: sel == value */
            CodeGen0(DUPOP, prevNextLabel);
            IncrementFrameSize();
            EmitCaseValue(caseVal, NoLabel);
            CodeGen1(BOPOP, BEQ, NoLabel);
            DecrementFrameSize();
            CodeGen2(CONDOP, bodyLabel, nextLabel, NoLabel);
            DecrementFrameSize();
         }

         /* at bodyLabel: [sel] on stack; POP it, execute body, GOTO end */
         CodeGen0(POPOP, bodyLabel);
         DecrementFrameSize();
         CodeGen1(GOTOOP, endLabel, ProcessNode(bodyStmt, NoLabel));
         prevNextLabel = nextLabel;
      }

      /* all clauses failed: pop selector, run otherwise or fall through */
      if (hasOtherwise)
      {
         CodeGen0(POPOP, prevNextLabel);
         DecrementFrameSize();
         CodeGen1(GOTOOP, endLabel, ProcessNode(Child(T, NKids(T)), NoLabel));
      }
      else
      {
         CodeGen0(POPOP, prevNextLabel);
         DecrementFrameSize();
      }
      return (endLabel);
   }

   default:
      ReportTreeErrorAt(T);
      printf("<<< CODE GENERATOR >>> : UNKNOWN NODE NAME ");
      Write_String(stdout, NodeName(T));
      printf("\n");

   } /* end switch */
} /* end ProcessNode */
