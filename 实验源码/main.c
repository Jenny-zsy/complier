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

	// ���ָ���ļ�������������ļ��л�ȡ�ַ���
	// ���û��ָ����������Ĭ�ϴ��ն˻�ȡ�ַ���
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
	// �ʷ������������ļ����������ⲿ����
	yyset_in(fp);

	// �����﷨��AST��ʼ��
	init_ast();

	// ���дʷ��������﷨�����Լ��﷨������ͬʱ�������������߳����﷨����
	yyparse();

	// �����Ԫʽ
	OutputQuaterList();

	// ������ű�(��������
	OutputVarList();

	// ��������﷨��
	OutputAST();

	return 0;
}
