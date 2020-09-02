# complier
## 简介
使用lex工具进行词法分析，yacc进行语法分析，实现对miniparcel的编译
### miniparcel文法
G[ProgDef]:  
ProgDef:　Program　Iden　';'　SubProg　'.'  
SubProg:　VarDef　CompState  
VarDef: 　Var　VarDefList ';'  
VarDefList:　VarDefList　';'　VarDefState　|　VarDefState  
VarDefState:　VarList　':'　Type  
Type:　Integer　|　Real　|　ArrayDef  
ArrayDef:　Array'['ArrayWidth']'Of　Integer　|　Array'['ArrayWidth']'　Of　Real  
ArrayWidth:　ArrayWidth','Integer | Integer  
VarList:　VarList','Variable　|　Variable  
StateList:　S_L Statement　|　Statement  
S_L:　StateList　';'  
Statement:　AssignState　|　ISE　Statement 　|　IBT　 Statement　|　WBD　Statement　|　CompState　|  
CompState:　Begin　StateList　End  
AssignState:　Variable　AssignOper　Expr  
ISE:　IBT　Statement　Else  
IBT:　If　BoolExpr　Then  
WBD:　Wh　BoolExpr　Do  
Wh:　While  
Expr:　Expr'+'Expr　|　Expr'-'Expr　|  Expr'*'Expr　｜　Expr'/'Expr　|　'('Expr')'　|　'-' Expr　|　Variable　|　Const  
BoolExpr:　Expr　RelationOp　Expr　|　BoolExpr　And　BoolExpr　|　BoolExpr　Or　BoolExpr　|　Not　BoolExpr　|　'('　BoolExpr　')'  
Variable:　Iden　|　Variable'['Iden']'  
Const:　IntNo　|　RealNo  
RelationOp:　'<'　|　'>'　|　'='　|　GE　|　NE　|　LE  
## 执行方式
1. cmd下进入..\可执行程序 目录下。
2. 执行minipascal.exe＋ ..\测试用例\**.txt。
3. 执行dot -Tpng graph.dot -o graph.png命令。
4. 输入graph.png或在该目录下即可打开png文件查看语法树。
