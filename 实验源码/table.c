#include <stdio.h>

#include <stdlib.h>
#include <ctype.h>

#include "table.h"
#include "pascal_yacc.h"

/*
 * 请在本文件中编写有关词法与语法分析中所需要用到有关符号表相关的函数
 */

int VarCount = 1;
int tempVarCount = 1;
int NXQ = 1;
static char KeyWord[][TABLE_MAX_IDENT_NAME_LEN] = {
		"PROGRAM",
		"BEGIN",
		"END",
		"VAR",
		"INTEGER",
		"REAL",
		"For",
		"WHILE",
		"DO",
		"IF",
		"THEN",
		"ELSE",
		"OR",
		"AND",
		"NOT",
		"ARRAY",
		"UNTIL",
		"STEP"
	};

int id_or_keyword(char *str)
{
	unsigned int i, j;
	char *p, buf[TABLE_MAX_IDENT_NAME_LEN];

	for (i = 0; i < sizeof(KeyWord) / sizeof(KeyWord[0]); i++) {
		p = str;

		for (j = 0; j < strlen(str); j++)
			buf[j] = (char)toupper(p[j]);

		buf[j] = '\0';

		if (!strcmp(KeyWord[i], buf)) {
			break;
		}
	}

	if (i < sizeof(KeyWord) / sizeof(KeyWord[0]))
		return i + 400;

	return Iden;
}

void OutputVarList(void)
{
	int i = 0;
	printf("\n------符号表------\n");

	printf(" No.\t name \t\t   type\n");

	if (i >= VarCount) {
		printf("Symbol Table is NULL!\n");
		return;
	}

	for (i = 1; i < VarCount; i++) {
		printf("%4d\t%6s\t\t", i, VarList[i].name);
		if (VarList[i].type == 1)
        {
			printf(" REAL  \n");
		}
		else if(VarList[i].type == 0)
        {
			printf(" INTEGER\n");
		}
		else if (VarList[i].type == 2)
        {
			printf(" REAL ARRAY\n");
		}
		else if (VarList[i].type == 3)
        {
			printf(" INTEGER ARRAY\n");
		}
	}

	return;
}

int lookUp(char *Name)
{
	int i;
	for (i = 1; i < VarCount; ++i) {
		if (!strncasecmp(Name, VarList[i].name) ) {
			return i;
		}

	}
	return 0;
}


int enter(char *Name)
{
	//printf("* %s *", Name);
	strcpy(VarList[VarCount].name, Name);
	VarList[VarCount].type = 0; // default type is INTEGER
	return VarCount++;
}


int entry(char *Name)
{
	int i = lookUp(Name);
	if (i > 0) {
		return i;
	} else {
		return enter(Name);
	}
}

int newTemp(int type)
{
	char temp[5];
	sprintf(temp, "T%d", tempVarCount++);
	strcpy(VarList[VarCount].name, temp);
	VarList[VarCount].type = type;
	return VarCount++;
}

/*
 * 请在本文件中编写有关四元式创建与维护、打印等相关的函数接口
 */

ir_quarter_expression QuaterList[MAX_IR_EXP_NUM];

void OutputQuaterList(void)
{
	int i = 1;

	if (i >= NXQ) {
		printf("no quater exists!\n");
	}
    printf("\n------四元式------\n");
	for (i = 1;i<NXQ;i++) {

		printf("(%3d) ( %5s, ", i, QuaterList[i].op);
		if (QuaterList[i].arg1)
			printf("%6s, ", VarList[QuaterList[i].arg1].name);
		else
			printf("      , ");

		if (QuaterList[i].arg2)
			printf("%6s, ", VarList[QuaterList[i].arg2].name);
		else printf("      , ");

		if ((QuaterList[i].op[0] == 'j') || (QuaterList[i].op[0] == 'S'))
			printf("%6d )\n", QuaterList[i].result);
		else if (QuaterList[i].result)
			printf("%6s )\n", VarList[QuaterList[i].result].name);
		else printf("-\t )\n");
	}

	return;
}

void gen(char *op, int ag1, int ag2, int rst)
{
	strcpy(QuaterList[NXQ].op, op);
	QuaterList[NXQ].arg1 = ag1;
	QuaterList[NXQ].arg2 = ag2;
	QuaterList[NXQ].result = rst;
	NXQ++;
}


int merge(int p1, int p2)
{
	int p;
	if (!p2) { // p2 = 0即第二条链为空
		return p1;
	} else {
		//find the last quadruple of chain p2
		p = p2;
		while (QuaterList[p].result) {
			p = QuaterList[p].result;
		}
		// append p1 to p2
		QuaterList[p].result = p1;
		return p2;
	}
}


void backPatch(int p, int t)
{
	int q = p, q1;
	while (q) {
		q1 = QuaterList[q].result;
		QuaterList[q].result = t;
		q = q1;
	}
	return;
}

