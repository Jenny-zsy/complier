%{
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include"windows.h"
#include "ast.h"
#include "table.h"
#include "pascal_lex.h"

#define MAXSTR 50
#define MAXMEMBER 100

#define INTTYPE  0
#define REALTYPE 1

extern int yylex();
extern FILE* yyin;
extern char str1[50];
extern int line_no;
extern int NXQ;
extern int VarCount;
extern ir_quarter_expression QuaterList[MAX_IR_EXP_NUM];//四元式
extern table_variable VarList[TABLE_MAX_VAR_NUM];//符号表

int flag_var_def = 0;

%}
%start    ProgDef
%union {
    struct
    {
         int Iv;
         int CH;
         int NO;
         struct { int TC,FC;} _BExpr;
         struct {int place;int QUAD;int CH;} _forloop;
         struct { int QUAD,CH;} _WBD; //while
         struct { int type,place;union{int Iv;float Rv;} Value;} _Expr;
         char _Rop[5];
         int First;
         char str[50];
         struct node *trNode;
         struct { int PLACE, OFFSET;} _Var;
         struct { int NO, DIM, PLACE;} _Elist;
    }st;
}

//定义终结符：常量符号
%token    	Iden    300
%token    	IntNo	301
%token	  	RealNo  302

//定义终结符：关键字
%token	  	Program 400
%token	  	Begin	401
%token	  	End	    402
%token	  	Var	    403
%token	  	Integer 404
%token	  	Real	405
%token	  	While	406
%token      Do      407
%token		If	    408
%token      Then    409
%token		Else	410
%token		For     411
%token 	    To      412
%token      Array   413
%token      Of      414
%token      Or      415
%token      And     416
%token      Not     417
%token      dian    418
%token      Until   419
%token      step    420

%token		LE	500
%token		GE	501
%token		NE	502	//双目运算符终结符

%left  Or
%left  And
%nonassoc Not
%nonassoc '<' '>' '=' LE GE NE
%left '+' '-'
%left '*' '/' '%'
%nonassoc UMINUS  //左右结合

%type <st> ProgDef
%type <st> SubProg
%type <st> VarDef
%type <st> VarDefList
%type <st> Type
%type <st> VarDefState
%type <st> VarList
%type <st> Statement
%type <st> StateList
%type <st> StateLists
%type <st> CompState
%type <st> AsignState
%type <st> ITE
%type <st> IT
%type <st> Wd
%type <st> ForLoop2
%type <st> ForLoop1
%type <st> RelationOp
%type <st> Expr
%type <st> W
%type <st> Variable
%type <st> Const
%type <st>	BoolExpr
%type <st>	BoolExprAnd
%type <st>	BoolExprOr
//%type <st> FExpr
%type <st> ArrayMSG

%type <st> ArrayVar
%type <st> ExprList

%%
ProgDef	:Program Iden {set_node_val_str(&root,str1);} ';' SubProg '.'
        {
            printf("\nCompile successfully!\n");
            $$.trNode=&root;
            $$.trNode->type=e_program;
            add_son_node(&root,$5.trNode);
            printf("\n\n**** Program %s ****\n",root.val.str);
        } //若规约到该步则表示LR分析成功
	;

SubProg: VarDef CompState
		{
            new_node(&($$.trNode));
            $$.trNode->type = e_sub_prog;
            set_node_val_str($$.trNode, "SubProg");
            add_son_node($$.trNode, $1.trNode);
            add_son_node($$.trNode, $2.trNode);
		}
	;
VarDef:	Var VarDefList ';'
        {
            // 变量声明
            new_node(&($$.trNode));
            $$.trNode->type = e_var_def;
            set_node_val_str($$.trNode, "Var");
            add_son_node($$.trNode, $2.trNode);

		}
	;
VarDefList:	VarDefList ';' VarDefState
        {
			// 不同类型的多个变量声明
			struct node *last =get_last_node($1.trNode);
			add_brother_node(last,$3.trNode);
			$$.trNode=$1.trNode;
		}
	|	VarDefState
	    {
            $$.trNode=$1.trNode;
        }
	;
VarDefState: VarList ':' Type
		{
			// VarList记录的多个变量指定类型
			int check = 0;
            while ($1.First)
            {
                VarList[$1.First].type = $3.Iv;
                $1.First = VarList[$1.First].addr;

                if(check++ > MAXMEMBER)
                {
                    yyerror("** Repeatly define variable **\n");
                }
            }

            struct node *last = get_last_node($1.trNode);
            add_brother_node(last, $3.trNode);
            $1.trNode->type = e_varlist;
            $$.trNode = $1.trNode;
		}
    |	ArrayVar Of Type
        {
            int check = 0;
            int NO = $1.NO;

            if ($3.Iv == 1)
            {
                $3.Iv = 2;//real array
            }
            else
            {
                $3.Iv = 3;//int array
            }

            while (NO)
            {
                VarList[NO].type = $3.Iv;
                NO = VarList[NO].addr;

                if(check++ > MAXMEMBER)
                {
                    yyerror("** Repeatly define variable **\n");
                }
            }
        }
	;
Type: Integer
		{
			// 整数类型
			$$.Iv = 0;

            new_node(&($$.trNode));
            $$.trNode->type = e_type_int;
            set_node_val_str($$.trNode, "Integer");
		}

	|	Real
		{
			// 实数类型
			$$.Iv = 1;

            new_node(&($$.trNode));
            $$.trNode->type = e_type_real;
            set_node_val_str($$.trNode, "Real");
		}
	;
VarList:	VarList ',' Variable
		{
			// 同一类型的多个变量通过逗号分割
			$$.First = $3._Var.PLACE;
            VarList[$3._Var.PLACE].addr = $1.First;

            struct node *last = get_last_node($1.trNode);
            add_brother_node(last, $3.trNode);
            $$.trNode = $1.trNode;
		}
	|	Variable
		{
            $$.First = $1._Var.PLACE;
            VarList[$1._Var.PLACE].addr = 0;

            $$.trNode = $1.trNode;
		}
	;
StateList:	StateLists Statement
		{
            $$.CH = $2.CH;

            struct node *last = get_last_node($1.trNode);
            add_brother_node(last, $2.trNode);
            $$.trNode = $1.trNode;
		}
	|	Statement
		{
            $$.CH = $1.CH;

            $$.trNode = $1.trNode;
		}
	;
StateLists:	StateList ';'
		{

			// 多个语句之间通过分号分割
			backPatch($1.CH, NXQ);

            $$.trNode = $1.trNode;
		}
	;
Statement:	AsignState
		{
			// 赋值语句是句子的一种
			$$.CH = 0;

			$$.trNode = $$.trNode;
		}
	|	ITE Statement
		{
			// If then Else语句是句子的一种
			$$.CH = merge($1.CH, $2.CH);

            add_son_node($1.trNode, $2.trNode);
            $$.trNode = $1.trNode;
		}
	|	IT Statement
		{
			// If then语句是句子的一种
			$$.CH = merge($1.CH, $2.CH);

            add_son_node($1.trNode, $2.trNode);
            $$.trNode = $1.trNode;
		}

	|	Wd Statement
		{
			// While语句是句子的一种
			backPatch($2.CH, $1._WBD.QUAD);
            gen("j", 0, 0, $1._WBD.QUAD);
            $$.CH = $1._WBD.CH;

            add_son_node($1.trNode, $2.trNode);
            $$.trNode = $1.trNode;
		}
	|	CompState
	    {
			// Begin End语句块
			$$.CH = $1.CH;

			$$.trNode = $1.trNode;
		}
    |    ForLoop2 Do Statement
        {
            //For循环语句
            backPatch($3.CH,$1._forloop.QUAD);
            gen("j",0,0,$1._forloop.QUAD);
            $$.CH=$1.CH;

            add_son_node($1.trNode, $3.trNode);
            $$.trNode = $1.trNode;
        }
    |   {
    }
	;

CompState:	Begin StateList End
		{
			// Begin End语句块，Begin类似于C语言的{，End类似于C语言的}
            $$.CH = $2.CH;

            new_node(&($$.trNode));
            $$.trNode->type = e_compstat;
            set_node_val_str($$.trNode, "begin_end");
            add_son_node($$.trNode, $2.trNode);
		}
    |   Begin StateList ';' End
		{
			// Begin End语句块，Begin类似于C语言的{，End类似于C语言的}
            $$.CH = $2.CH;

            new_node(&($$.trNode));
            $$.trNode->type = e_compstat;
            set_node_val_str($$.trNode, "begin_end");
            add_son_node($$.trNode, $2.trNode);
  ;
		}
	;
AsignState:	Variable ':''='  Expr
		{
			// 赋值语句
			if (!$1._Var.OFFSET)
			{
                gen(":=", $4._Expr.place, 0, $1._Var.PLACE);
            }
            else
            {
                gen("[]=", $4._Expr.place, 0, $1._Var.PLACE);
            }
            $1._Expr.type=$4._Expr.type;

            if (flag_var_def == 0)
            {
                char* s1="undefined variable:";
                char* s2=VarList[$1._Var.PLACE].name;
                char *err = (char *) malloc(strlen(s1) + strlen(s2));
                strcpy(err,s1);
                strcat(err,s2);
                yyerror(err);

                /*printf("** undefined variable %s **", VarList[$1._Var.PLACE].name);
                exit(0);*/
            }

            new_node(&($$.trNode));
            $$.trNode->type = e_assign_stat;
            set_node_val_str($$.trNode, ":=");
            add_son_node($$.trNode, $1.trNode);
            add_son_node($$.trNode, $4.trNode)
		}
	;
ITE:	IT Statement Else
		{
			// If Else语句
			int q = NXQ;
            gen("j", 0, 0, 0);
            backPatch($1.CH, NXQ);
            $$.CH = merge($2.CH, q);

            new_node(&($$.trNode));
            $$.trNode->type = e_if_then_else_stat;
            set_node_val_str($$.trNode, "if_then_else");
            add_son_node($$.trNode, $1.trNode);
            add_son_node($$.trNode, $2.trNode);
		}
	;
IT:	If BoolExpr Then
		{
			// If Then 语句
			backPatch($2._BExpr.TC, NXQ);
			$$.CH = $2._BExpr.FC;

            new_node(&($$.trNode));
            $$.trNode->type = e_if_then_stat;
            set_node_val_str($$.trNode, "if_then");
            add_son_node($$.trNode, $2.trNode);
		}

	;
Wd: W BoolExpr Do
		{
			// while循环
			backPatch($2._BExpr.TC, NXQ);
            $$._WBD.CH = $2._BExpr.FC;
            $$._WBD.QUAD = $1.CH;

            add_son_node($1.trNode, $2.trNode);
            $$.trNode = $1.trNode;
		}
	;

W:	 While
        {
			// 文法符号While对应关键字"while"
			$$.CH = NXQ;

            new_node(&($$.trNode));
            $$.trNode->type = e_while_stat;
            set_node_val_str($$.trNode, "while");
        }
	;

BoolExpr: Expr RelationOp Expr
		{
            $$._BExpr.TC = NXQ;
            $$._BExpr.FC = NXQ + 1;
            gen($2._Rop, $1._Expr.place, $3._Expr.place, 0);
            gen("j", 0, 0, 0);

            new_node(&($$.trNode));
            $$.trNode->type = e_bool_exp;
            set_node_val_str($$.trNode, &($2._Rop[1]));
            add_son_node($$.trNode, $1.trNode);
            add_son_node($$.trNode, $3.trNode);
		}
    |	BoolExprAnd BoolExpr
	    {
            $$._BExpr.TC=$2._BExpr.TC;
            $$._BExpr.FC=merge($1._BExpr.FC,$2._BExpr.FC);

            new_node(&($$.trNode));
            $$.trNode->type = e_bool_exp;
            set_node_val_str($$.trNode, "and");
            add_son_node($$.trNode, $1.trNode);
            add_son_node($$.trNode, $2.trNode);
		}
    |	BoolExprOr BoolExpr
	    {
            $$._BExpr.FC=$2._BExpr.FC;
            $$._BExpr.TC=merge($1._BExpr.TC,$2._BExpr.TC);

            new_node(&($$.trNode));
            $$.trNode->type = e_bool_exp;
            set_node_val_str($$.trNode, "or");
            add_son_node($$.trNode, $1.trNode);
            add_son_node($$.trNode, $2.trNode);
		}
	|	Not BoolExpr
	    {
            $$._BExpr.TC = $2._BExpr.FC; $$._BExpr.FC = $2._BExpr.TC;

            new_node(&($$.trNode));
            $$.trNode->type = e_bool_exp;
            set_node_val_str($$.trNode, "Not");
            add_son_node($$.trNode, $2.trNode);
		}
	|	'(' BoolExpr ')'
	    {
            $$._BExpr.TC = $2._BExpr.TC; $$._BExpr.FC = $2._BExpr.FC;

            $$.trNode = $2.trNode;
		}
	;
BoolExprAnd: BoolExpr And
		{
            backPatch($1._BExpr.TC, NXQ);
            $$._BExpr.FC = $1._BExpr.FC;

            $$.trNode = $1.trNode;
		}
BoolExprOr:	BoolExpr Or
		{
            backPatch($1._BExpr.FC,NXQ);
            $$._BExpr.TC=$1._BExpr.TC;

		}
Expr: Expr'+'Expr
		{
            $$._Expr.place = newTemp($1._Expr.type);
            gen("+", $1._Expr.place, $3._Expr.place, $$._Expr.place);
            $$._Expr.type=$1._Expr.type;

            new_node(&($$.trNode));
            $$.trNode->type = e_exp;
            set_node_val_str($$.trNode, "+");
            add_son_node($$.trNode, $1.trNode);
            add_son_node($$.trNode, $3.trNode);
		}
	|	Expr'-'Expr
		{
            $$._Expr.place = newTemp($1._Expr.type);
            gen("-", $1._Expr.place, $3._Expr.place, $$._Expr.place);
            $$._Expr.type=$1._Expr.type;

            new_node(&($$.trNode));
            $$.trNode->type = e_exp;
            set_node_val_str($$.trNode, "-");
            add_son_node($$.trNode, $1.trNode);
            add_son_node($$.trNode, $3.trNode);
		}
	|	Expr'*'Expr
		{
            $$._Expr.place = newTemp($1._Expr.type);
            gen("*", $1._Expr.place, $3._Expr.place, $$._Expr.place);
            $$._Expr.type=$1._Expr.type;

            new_node(&($$.trNode));
            $$.trNode->type = e_exp;
            set_node_val_str($$.trNode, "*");
            add_son_node($$.trNode, $1.trNode);
            add_son_node($$.trNode, $3.trNode);
		}
	|	Expr'/'Expr
		{
            $$._Expr.place = newTemp($1._Expr.type);
            gen("/", $1._Expr.place, $3._Expr.place, $$._Expr.place);
            $$._Expr.type=$1._Expr.type;

            new_node(&($$.trNode));
            $$.trNode->type = e_exp;
            set_node_val_str($$.trNode, "/");
            add_son_node($$.trNode, $1.trNode);
            add_son_node($$.trNode, $3.trNode);
		}
	|	'('Expr')'
		{
            $$._Expr.place = $2._Expr.place;
            $$._Expr.type=$2._Expr.type;

            $$.trNode = $2.trNode;
		}
	|	'-' Expr %prec UMINUS
		{
            $$._Expr.place = newTemp($2._Expr.type);
            $$._Expr.type=$2._Expr.type;

            gen("-", $2._Expr.place, 0, $$._Expr.place);

            new_node(&($$.trNode));
            $$.trNode->type = e_exp;
            set_node_val_str($$.trNode, "-");
            add_son_node($$.trNode, $2.trNode);
		}
	|	Variable
		{

            if (!$1._Var.OFFSET)
            {
                $$._Expr.place = $1._Var.PLACE;
            }
            else
            {
                int T = newTemp($1._Expr.type);
                gen("=[]", $1._Var.PLACE, 0, T);
                $$._Expr.place = T;
            }
            $$._Expr.type=$1._Expr.type;

            // undefined error
            if (flag_var_def == 0)
            {
                char* s1="undefined variable:";
                char* s2=VarList[$1._Var.PLACE].name;
                char *err = (char *) malloc(strlen(s1) + strlen(s2));
                strcpy(err,s1);
                strcat(err,s2);
                yyerror(err);

                /*printf("** undefined variable %s **", VarList[$1._Var.PLACE].name);
                exit(0);*/
            }

            $$.trNode = $1.trNode;
		}

	|	Const
		{
            $$._Expr.type = $1._Expr.type;
            $$._Expr.place = $1._Expr.place;
            if ($$._Expr.type)
            {
                $$._Expr.Value.Rv = $1._Expr.Value.Rv;
            }
            else
            {
                $$._Expr.Value.Iv = $1._Expr.Value.Iv;
            }

            $$.trNode = $1.trNode;
		}
	;

Variable: Iden
		{
			// 文法符号Iden对应标识符，以字母或下划线开头后面是字母、数字或下划线组成的符号串
            if (lookUp(str1))
            {
                flag_var_def = 1;
                $$._Expr.type=VarList[lookUp(str1)].type;
            }
            else
            {
                flag_var_def = 0;
            }
            $$._Var.PLACE = entry(str1);
            $$._Var.OFFSET = 0;


            new_node(&($$.trNode));
            set_node_val_str($$.trNode, str1);
		}
    |	ExprList ']'
		{

			char Cstr[10], astr[10] = "ArrPtr";
			int T = newTemp($1._Expr.type);

			gen("-", entry(astr), entry(Cstr),T);
			$$._Elist.PLACE = T;
			$$._Var.OFFSET = $1._Elist.PLACE;
		}
	;

Const:  IntNo
		{
            $$._Expr.type = 0;
            $$._Expr.place = entry(str1);
            VarList[$$._Expr.place].type = 0;
            $$._Expr.Value.Iv = atoi(str1);

            new_node(&($$.trNode));
            set_node_val_str($$.trNode, str1);
		}
	|	RealNo
		{
            $$._Expr.type = 1;
            $$._Expr.place = entry(str1);
            VarList[$$._Expr.place].type = 1;
            $$._Expr.Value.Rv = (float)atof(str1);

            new_node(&($$.trNode));
            set_node_val_str($$.trNode, str1);
		}
	;

RelationOp:	'<'
		{
			// 小于
			strcpy($$._Rop, "j<");
		}
	|	'>'
		{
			// 大于
			strcpy($$._Rop, "j>");
		}
	|	'='
		{
			// 等于
			strcpy($$._Rop, "j=");
		}
	|	GE
		{
			// 文法符号GE对应大于等于，符号串为">=
			strcpy($$._Rop, "j>=");
		}
	|	NE
		{
			// 文法符号NE对应不等于，符号串为"<>""
			strcpy($$._Rop, "j!=");
		}
	|	LE
		{
			// 文法符号LE对应小于等于，符号串为"<=""
			strcpy($$._Rop, "j<=");
		}
	;

ArrayVar: VarList ':' Array '[' ArrayMSG ']'
		{
			//int NO = $1.NO;
			$$.NO = $1.First;

			/*while (NO)
			{
				FillArrMSG_C(NO);
				NO = VarList[NO].ADDR;
			}*/
		}
	;
ArrayMSG: Expr dian Expr
		{

			int NO = $$.NO;
			int low = $1._Expr.Value.Iv, high = $3._Expr.Value.Iv;
			$$.NO = $1._Expr.place;


			while (NO)
			{
                    VarList[NO].ADDR = malloc(sizeof(struct arr_info));
                    printf("error");
                    VarList[NO].ADDR->DIM = 1;
                    VarList[NO].ADDR->Vector = malloc(5*sizeof(int));
                    VarList[NO].ADDR->Vector[2] = low;
                    VarList[NO].ADDR->Vector[3] = high;
                    VarList[NO].ADDR->Vector[4] = (high - low) + 1;
                    VarList[NO].ADDR;
           }
		}
    |   ArrayMSG ',' Expr dian Expr
		{

			/*int NO = $1.NO;

			int dim = VarList[NO].ADDR->DIM+1;

			int low = $3._Expr.Value.Iv, high = $5._Expr.Value.Iv;*/
			$$.NO = $1.NO;


			/*while (NO)
			{
                    VarList[NO].ADDR->DIM++;
                    VarList[NO].ADDR->Vector = realloc(VarList[NO].ADDR->Vector, (3 * dim + 2) * sizeof(int));
                    VarList[NO].ADDR->Vector[3*dim - 1] = low;
                    VarList[NO].ADDR->Vector[3*dim] = high;
                    VarList[NO].ADDR->Vector[3*dim + 1] = (high - low) + 1;
                    VarList[NO].ADDR;
            }*/

		}
	;

ExprList: Variable '[' Expr ']'
		{
			$$._Elist.PLACE = $3._Expr.place;
			$$._Elist.DIM = 1;

			$$._Elist.NO = $1._Var.PLACE;
		}
	|	ExprList '[' Expr
		{

			char num[5];
			int k,d;
			int T = newTemp($1._Expr.type);
			k = $1._Elist.DIM + 1;
			//d = Access_d($1._Elist.NO, k);


			printf(num, "%d", d);
			gen("*", $1._Elist.PLACE, entry(num), T);
			gen("+", $3._Expr.place, T, T);
			$$._Elist.NO = $1._Elist.NO;
			$$._Elist.PLACE = T;
			//$$._Elist.DIM = k;

		}
	;

ForLoop1: For Variable ':''=' Expr
		{
            gen("=",$5._Expr.place,0,$2._Var.PLACE);
            $$._Expr.place=$2._Var.PLACE;

            new_node(&($$.trNode));
            $$.trNode->type = e_forloop1_stat;
            set_node_val_str($$.trNode, ":=");
            add_son_node($$.trNode, $2.trNode);
            add_son_node($$.trNode, $5.trNode);
		}
ForLoop2 : ForLoop1 step Expr Until Expr
        {
            int p = NXQ;
            $$._forloop.QUAD = NXQ;
            gen( "j≤", $1._Expr.place,$5._Expr.place,p+2);
            $$._Expr.place=$1._Expr.place;
            $$.CH=NXQ;
            gen( "j", 0, 0, 0);
            gen("+",$1._Expr.place,$3._Expr.place,$1._Expr.place);

            new_node(&($$.trNode));
            $$.trNode->type = e_forloop2_stat;
            set_node_val_str($$.trNode, "for_step_until");
            add_son_node($$.trNode, $1.trNode);
            add_son_node($$.trNode, $5.trNode);
        }
%%

int yyerror(char *errstr)
{
    printf("Syntax error: %s\n",errstr);

    exit(0);
}
