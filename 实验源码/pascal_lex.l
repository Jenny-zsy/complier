%{
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "pascal_yacc.h"
#include "table.h"

/* 行号 */
int line_no = 1;

/*类型 标识符 整型 实型*/
#define    	Iden    	300
#define    	IntNo		301
#define	  	RealNo  	302

/*关键字*/
#define	  	Program 400
#define	  	Begin	401
#define	  	End	    402
#define	  	Var	    403
#define	  	Integer 404
#define	  	Real	405
#define	  	While	406
#define     Do      407
#define		If	    408
#define     Then    409
#define		Else	410
#define		For     411
#define 	To      412
#define     Array   413
#define     Of      414
#define     Or      415
#define     And     416
#define     Not     417
#define     dian    418
#define     Until   419
#define     step    420

/*双目运算符*/
#define		LE	500
#define		GE	501
#define		NE	502


#define		ERRORCHAR	600

#define MAXSTR 50

/* This array is used for determin if a identier is keyword */

char str1[50]; /* this array is used to store the string of identifier or
		  integer/real number.When one of them are abtained in yytext,
		  copy it to str1. str1 will be used in YACC source file
		  (YSP file filename.y) */

%}
/* 语言不区分大小写 */
A [aA]
B [bB]
C [cC]
D [dD]
E [eE]
F [fF]
G [gG]
H [hH]
I [iI]
J [jJ]
K [kK]
L [lL]
M [mM]
N [nN]
O [oO]
P [pP]
Q [qQ]
R [rR]
S [sS]
T [tT]
U [uU]
V [vV]
W [wW]
X [xX]
Y [yY]
Z [zZ]
NQUOTE [^']
letter      [A-Za-z]
alnum		[A-Za-z0-9\_]
d			[0-9]
white		[\t\n\040]
hua         [\_]

%start		COMMENT
%%

\{			        {ECHO;BEGIN COMMENT;} /*ECHO:存入yyout*/
<COMMENT>\}		    {ECHO;BEGIN 0;}
<COMMENT>\n		    {ECHO;++line_no;}
<COMMENT>[^\}]+ 	{ECHO;} /*去注释*/
[\n]                        	{ECHO;++line_no;}
[Bb][eE][Gg][iI][Nn]	        {ECHO;return Begin;}
[eE][Nn][Dd]		            {ECHO;return End;}
[Pp][Rr][oO][Gg][Rr][Aa][Mm]	{ECHO;return Program;}
[Vv][Aa][Rr]		            {ECHO;return Var;}
[Ii][nN][Tt][eE][Gg][eE][Rr]	{ECHO;return Integer;}
[Rr][eE][Aa][lL]	            {ECHO;return Real;}
[Ww][Hh][Ii][Ll][Ee]	        {ECHO;return While;}
[Dd][oO]					    {ECHO;return Do;}
[iI][Ff]		                {ECHO;return If;}
[Tt][Hh][Ee][Nn]	            {ECHO;return Then;}
[Ee][Ll][Ss][Ee]	            {ECHO;return Else;}
[Ff][Oo][Rr]	                {ECHO;return For;}
[Tt][Oo]	                    {ECHO;return To;}
[Aa][Rr][Rr][Aa][Yy]        	{ECHO;return Array;}
[Oo][Ff]	                    {ECHO;return Of;}
[Oo][Rr]					    {ECHO;return Or;}
[Aa][Nn][Dd]			        {ECHO;return And;}
[Nn][Oo][Tt]			        {ECHO;return Not;}
[Uu][Nn][Tt][Ii][Ll]            {ECHO;return Until;}
[Ss][Tt][Ee][Pp]                {ECHO;return step;}

({d}+(\.{d}*)?[Ee]([+-])?{d}+)|({d}*\.{d}+[Ee]([+-])?{d}+)	{ECHO;strcpy(str1,yytext);return RealNo;}
{d}+\.{d}*|{d}*\.{d}+		{ECHO;strcpy(str1,yytext);return RealNo;}
{d}+			{ECHO;strcpy(str1,yytext);return IntNo;}

"("			{ECHO;return '(';}
")"			{ECHO;return ')';}
"["			{ECHO;return '[';}
"]"			{ECHO;return ']';}
">"			{ECHO;return '>';}
"<"			{ECHO;return '<';}
"="			{ECHO;return '=';}
"<="		{ECHO;return LE;}
">="		{ECHO;return GE;}
"<>"		{ECHO;return NE;}
":"			{ECHO;return ':';}
";"			{ECHO;return ';';}
"\."		{ECHO;return '.';}
"*"			{ECHO;return '*';}
"+"			{ECHO;return '+';}
"-"			{ECHO;return '-';}
"/"			{ECHO;return '/';}
"%"			{ECHO;return '%';}
","			{ECHO;return ',';}
"&"         {ECHO;return '&';}
"|"         {ECHO;return '|';}
"!"         {ECHO;return '!';}
"\.\."      {ECHO;return dian;}

{hua}{alnum}*	{ ECHO;strcpy(str1,yytext);return Iden;} /*标识符以下划线开头*/
{letter}{alnum}*	{ ECHO;strcpy(str1,yytext);return Iden;} /*标识符以字母开头*/
{white}+		{ECHO;}
.			{printf("Invalid char %s\n",yytext);
			 return ERRORCHAR;
			}
%%


#ifndef yywrap
 int yywrap(){return 1;}
#endif
