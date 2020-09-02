#ifndef __TABLE_H__
#define __TABLE_H__

#define TABLE_MAX_IDENT_NAME_LEN 50
#define TABLE_MAX_VAR_NUM 200
#define MAX_IR_EXP_NUM 200
extern int VarCount ;
extern int tempVarCount ;
extern int NXQ ;

/*-------------------符号表----------------------*/
struct arr_info {
	int DIM;
	int *Vector;//Vector[0]存放C
};

typedef struct table_variable__ {
	char name[TABLE_MAX_IDENT_NAME_LEN]; // 变量名
	int type; // 类型
	int addr; // 地址
	struct arr_info *ADDR;
} table_variable;

//extern table_variable VarList[TABLE_MAX_VAR_NUM];

void OutputVarList(void);
int id_or_keyword(char *str);
int lookUp(char *Name);
int enter(char *Name);
int entry(char *Name);
int newTemp(int type);
table_variable VarList[TABLE_MAX_VAR_NUM];//符号表

/*---------------------四元式------------------------*/
typedef struct ir_quarter_expression_ {

	char op[6];
	int arg1;		// 源操作数1
	int arg2;		// 源操作数2
	int result;		// 目的操作数或结果
} ir_quarter_expression;

void OutputQuaterList(void);
void gen(char *op, int ag1, int ag2, int rst);
int merge(int p1, int p2);
void backPatch(int p, int t);

ir_quarter_expression QuaterList[MAX_IR_EXP_NUM];//四元式

#endif
