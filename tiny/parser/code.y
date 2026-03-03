%{
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <DLists.h>
#include <Tokenizer.h>
#include <Trees.h>

extern TREENODE *root;
int yylex(void);
void yyerror(const char *msg);
typedef struct {
    DNODE mynode;
    TREENODE *nodeptr;
} T_NODE;

%}
%union {
   TOKEN_INFO info;
   DLIST dlist;
}
%token <info>  END
%token <info>  VAR
%token <info>  IDENTIFIER
%token <info>  IF
%token <info>  READ
%token <info>  ELSE
%token <info>  THEN
%token <info>  NE
%token <info>  MOD
%token <info>  WHILE
%token <info>  OUTPUT
%token <info>  NOT
%token <info>  DO
%token <info>  BEGINX
%token <info>  BOOLEAN
%token <info>  INTEGER_NUM
%token <info>  AND
%token <info>  INTEGER
%token <info>  EXP
%token <info>  LTE
%token <info>  GE
%token <info>  OR
%token <info>  ASSIGNMENT
%token <info>  PROGRAM
%type <dlist> NameList
%type <dlist> StmtList
%type <dlist> Tiny
%type <dlist> Dcln
%type <dlist> UnaryTerm
%type <dlist> Statement
%type <dlist> Name
%type <dlist> Body
%type <dlist> Dclns_1
%type <dlist> PowTerm
%type <dlist> Type
%type <dlist> Expression
%type <dlist> Dclns
%type <dlist> Primary
%type <dlist> AddTerm
%type <dlist> MulTerm
%%

Tiny     : PROGRAM  Name     ':'      Dclns    Body     Name     '.'      
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ($1.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$1.string,
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$2) > 0)
		    DAddTail(&r,DRemHead(&$2));

		while (DCount(&$4) > 0)
		    DAddTail(&r,DRemHead(&$4));

		while (DCount(&$5) > 0)
		    DAddTail(&r,DRemHead(&$5));

		while (DCount(&$6) > 0)
		    DAddTail(&r,DRemHead(&$6));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"program",
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		t->mynode = *(DHead(&r));
		root = t->nodeptr;

             }
         ;

Dclns    : VAR      Dclns_1  
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ($1.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$1.string,
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$2) > 0)
		    DAddTail(&r,DRemHead(&$2));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"dclns",
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         | 
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"dclns",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         ;

Dclns_1  : 
             {
		DLIST r;

		InitDList(&r);

		$$ = r;

             }
         | Dcln     ';'      Dclns_1  
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

		$$ = r;

             }
         ;

Dcln     : NameList ':'      Type     
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"dcln",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         ;

NameList : Name     
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		$$ = r;

             }
         | NameList ','      Name     
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

		$$ = r;

             }
         ;

Type     : INTEGER  
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ($1.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$1.string,
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"integer",
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         | BOOLEAN  
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ($1.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$1.string,
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"boolean",
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         ;

Body     : BEGINX   StmtList END      
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ($1.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$1.string,
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$2) > 0)
		    DAddTail(&r,DRemHead(&$2));

		if ($3.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$3.string,
		                                TREETAG_LINE,$3.line,
		                                TREETAG_COLUMN,$3.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"block",
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         ;

StmtList : Statement 
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		$$ = r;

             }
         | StmtList ';'      Statement 
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

		$$ = r;

             }
         ;

Statement : Name     ASSIGNMENT Expression 
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		if ($2.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$2.string,
		                                TREETAG_LINE,$2.line,
		                                TREETAG_COLUMN,$2.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"assign",
		                                TREETAG_LINE,$2.line,
		                                TREETAG_COLUMN,$2.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         | OUTPUT   '('      Expression ')'      
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ($1.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$1.string,
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"output",
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         | IF       Expression THEN     Statement ELSE     Statement 
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ($1.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$1.string,
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$2) > 0)
		    DAddTail(&r,DRemHead(&$2));

		if ($3.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$3.string,
		                                TREETAG_LINE,$3.line,
		                                TREETAG_COLUMN,$3.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$4) > 0)
		    DAddTail(&r,DRemHead(&$4));

		if ($5.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$5.string,
		                                TREETAG_LINE,$5.line,
		                                TREETAG_COLUMN,$5.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$6) > 0)
		    DAddTail(&r,DRemHead(&$6));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"if",
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         | WHILE    Expression DO       Statement 
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ($1.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$1.string,
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$2) > 0)
		    DAddTail(&r,DRemHead(&$2));

		if ($3.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$3.string,
		                                TREETAG_LINE,$3.line,
		                                TREETAG_COLUMN,$3.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$4) > 0)
		    DAddTail(&r,DRemHead(&$4));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"while",
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         | Body     
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		$$ = r;

             }
         | 
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"<null>",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         ;

Expression : AddTerm  
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		$$ = r;

             }
         | AddTerm  '='      AddTerm  
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"=",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         | AddTerm  NE       AddTerm  
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		if ($2.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$2.string,
		                                TREETAG_LINE,$2.line,
		                                TREETAG_COLUMN,$2.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"<>",
		                                TREETAG_LINE,$2.line,
		                                TREETAG_COLUMN,$2.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         | AddTerm  '<'      AddTerm  
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"<",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         | AddTerm  '>'      AddTerm  
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,">",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         | AddTerm  LTE      AddTerm  
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		if ($2.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$2.string,
		                                TREETAG_LINE,$2.line,
		                                TREETAG_COLUMN,$2.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"<=",
		                                TREETAG_LINE,$2.line,
		                                TREETAG_COLUMN,$2.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         | AddTerm  GE       AddTerm  
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		if ($2.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$2.string,
		                                TREETAG_LINE,$2.line,
		                                TREETAG_COLUMN,$2.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,">=",
		                                TREETAG_LINE,$2.line,
		                                TREETAG_COLUMN,$2.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         ;

AddTerm  : MulTerm  
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		$$ = r;

             }
         | AddTerm  '+'      MulTerm  
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"+",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         | AddTerm  '-'      MulTerm  
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"-",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         | AddTerm  OR       MulTerm  
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		if ($2.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$2.string,
		                                TREETAG_LINE,$2.line,
		                                TREETAG_COLUMN,$2.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"or",
		                                TREETAG_LINE,$2.line,
		                                TREETAG_COLUMN,$2.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         ;

MulTerm  : PowTerm  
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		$$ = r;

             }
         | MulTerm  '*'      PowTerm  
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"*",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         | MulTerm  '/'      PowTerm  
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"/",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         | MulTerm  AND      PowTerm  
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		if ($2.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$2.string,
		                                TREETAG_LINE,$2.line,
		                                TREETAG_COLUMN,$2.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"and",
		                                TREETAG_LINE,$2.line,
		                                TREETAG_COLUMN,$2.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         | MulTerm  MOD      PowTerm  
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		if ($2.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$2.string,
		                                TREETAG_LINE,$2.line,
		                                TREETAG_COLUMN,$2.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"mod",
		                                TREETAG_LINE,$2.line,
		                                TREETAG_COLUMN,$2.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         ;

PowTerm  : UnaryTerm 
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		$$ = r;

             }
         | UnaryTerm EXP      PowTerm  
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		if ($2.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$2.string,
		                                TREETAG_LINE,$2.line,
		                                TREETAG_COLUMN,$2.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"**",
		                                TREETAG_LINE,$2.line,
		                                TREETAG_COLUMN,$2.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         ;

UnaryTerm : Primary  
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		$$ = r;

             }
         | '-'      UnaryTerm 
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&$2) > 0)
		    DAddTail(&r,DRemHead(&$2));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"-",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         | '+'      UnaryTerm 
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&$2) > 0)
		    DAddTail(&r,DRemHead(&$2));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"u+",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         | NOT      UnaryTerm 
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ($1.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$1.string,
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$2) > 0)
		    DAddTail(&r,DRemHead(&$2));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"not",
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         ;

Primary  : READ     
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ($1.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$1.string,
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"read",
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         | Name     
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		$$ = r;

             }
         | INTEGER_NUM 
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ($1.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$1.string,
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"<integer>",
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         | '('      Expression ')'      
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&$2) > 0)
		    DAddTail(&r,DRemHead(&$2));

		$$ = r;

             }
         ;

Name     : IDENTIFIER 
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ($1.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$1.string,
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"<identifier>",
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         ;

