#include <stdio.h>
#include <stdlib.h>
#include "pascal_lex.h"
#include "pascal_yacc.h"

#include "ast.h"
#include "table.h"

extern int yyparse();
extern FILE* yyin;

int main(int argc, char *argv[])
//int main()
{
	FILE * fp = stdin;

	// 如果指定文件名参数，则从文件中获取字符串
	// 如果没有指定参数，则默认从终端获取字符串
	if (argc > 1) {
		if ((fp = fopen(argv[1], "r")) == NULL) {
			printf("Can't open file %s\n", argv[1]);
			return -1;
		}
	}
	/*FILE *fp;
	char filename[100];
	gets(filename);
    fp=fopen(filename,"r");
    if(fp=fopen(filename,"r") == NULL)
    {
        printf("Can't open file \n");
        return -1;
    }*/
	// 词法分析的输入文件，必须由外部设置
	yyset_in(fp);

	// 抽象语法树AST初始化
	init_ast();

	// 进行词法分析、语法分析以及语法分析，同时产生分析树或者抽象语法树等
	yyparse();

	// 输出四元式
	OutputQuaterList();

	// 输出符号表(变量名）
	OutputVarList();

	// 输出抽象语法树
	OutputAST();

	return 0;
}
