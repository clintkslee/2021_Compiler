digit		[0-9]
letter		[A-Za-z_]
delim		[ \t]
line		[\n]
ws		{delim}+
%{
#include "y.tab.h"
extern int yylval;
extern int line_no;
%}

%%

"#include"	{ printf("%s ", yytext); }
"<stdio.h>"	{ printf("%s ", yytext); }
{ws}		{ }
{line}		{ line_no++; printf("\n"); }
auto		{ printf("%s ", yytext); return(AUTO_SYM); }
break		{ printf("%s ", yytext); return(BREAK_SYM); }
case		{ printf("%s ", yytext); return(CASE_SYM); }
continue	{ printf("%s ", yytext); return(CONTINUE_SYM); }
default	{ printf("%s ", yytext); return(DEFAULT_SYM); }
do		{ printf("%s ", yytext); return(DO_SYM); }
else		{ printf("%s ", yytext); return(ELSE_SYM); }
enum		{ printf("%s ", yytext); return(ENUM_SYM); }
for		{ printf("%s ", yytext); return(FOR_SYM); }
if		{ printf("%s ", yytext); return(IF_SYM); }
return		{ printf("%s ", yytext); return(RETURN_SYM); }
sizeof		{ printf("%s ", yytext); return(SIZEOF_SYM); }
static		{ printf("%s ", yytext); return(STATIC_SYM); }
struct		{ printf("%s ", yytext); return(STRUCT_SYM); }
switch		{ printf("%s ", yytext); return(SWITCH_SYM); }
typedef	{ printf("%s ", yytext); return(TYPEDEF_SYM); }
union		{ printf("%s ", yytext); return(UNION_SYM); }
while		{ printf("%s ", yytext); return(WHILE_SYM); }
int		{ printf("%s ", yytext); return(TYPE_IDENTIFIER); }
float		{ printf("%s ", yytext); return(TYPE_IDENTIFIER); }
char		{ printf("%s ", yytext); return(TYPE_IDENTIFIER); }
void		{ printf("%s ", yytext); return(TYPE_IDENTIFIER); }

const		{ printf("%s ", yytext); return(CONST_SYM); }
"\~"		{ printf("%s ", yytext); return(TILDE); }
"<<"		{ printf("%s ", yytext); return(SHIFTLEFT); }
">>"		{ printf("%s ", yytext); return(SHIFTRIGHT); }
"^"		{ printf("%s ", yytext); return(HAT); }
"|"		{ printf("%s ", yytext); return(BAR); }
"?"		{ printf("%s ", yytext); return(QUES); }

"\+\+"		{ printf("%s ", yytext); return(PLUSPLUS); }
"\-\-"		{ printf("%s ", yytext); return(MINUSMINUS); }
"\->"		{ printf("%s ", yytext); return(ARROW); }
"<"		{ printf("%s ", yytext); return(LSS); }
">"		{ printf("%s ", yytext); return(GTR); }
"<="		{ printf("%s ", yytext); return(LEQ); }
">="		{ printf("%s ", yytext); return(GEQ); }
"=="		{ printf("%s ", yytext); return(EQL); }
"!="		{ printf("%s ", yytext); return(NEQ); }
"&&"		{ printf("%s ", yytext); return(AMPAMP); }
"||"		{ printf("%s ", yytext); return(BARBAR); }
"\.\.\."	{ printf("%s ", yytext); return(DOTDOTDOT); }
"("		{ printf("%s ", yytext); return(LP); }
")"		{ printf("%s ", yytext); return(RP); }
"\["		{ printf("%s ", yytext); return(LB); }
"\]"		{ printf("%s ", yytext); return(RB); }
"\{"		{ printf("%s ", yytext); return(LR); }
"\}"		{ printf("%s ", yytext); return(RR); }
"\:"		{ printf("%s ", yytext); return(COLON); }
"\."		{ printf("%s ", yytext); return(PERIOD); }
"\,"		{ printf("%s ", yytext); return(COMMA); }
"\!"		{ printf("%s ", yytext); return(EXCL); }
"\*"		{ printf("%s ", yytext); return(STAR); }
"\/"		{ printf("%s ", yytext); return(SLASH); }
"\%"		{ printf("%s ", yytext); return(PERCENT); }
"\&"		{ printf("%s ", yytext); return(AMP); }
"\;"		{ printf("%s ", yytext); return(SEMICOLON); }
"\+"		{ printf("%s ", yytext); return(PLUS); }
"\-"		{ printf("%s ", yytext); return(MINUS); }
"="		{ printf("%s ", yytext); return(ASSIGN); }

{digit}+			{ printf("%s ", yytext); return(INTEGER_CONSTANT); }
{digit}+\.{digit}+		{ printf("%s ", yytext); return(FLOAT_CONSTANT); }
{letter}({letter}|{digit})*	{ printf("%s ", yytext); return(IDENTIFIER); }
\"([^"\n]|\\["\n])*\"		{ printf("%s ", yytext); return(STRING_LITERAL); }
\'([^'\n]|\'\')\'		{ printf("%s ", yytext); return(CHARACTER_CONSTANT); }

%%
		










