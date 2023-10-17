digit		[0-9]
letter		[A-Za-z_]
delim		[ \t]
line		[\n]
ws		{delim}+

%{
#include "type.h"
typedef union { 
	char cval; 
	int ival; 
	char* pval; 
	A_NODE* anode;
	A_TYPE* atype;
	A_SPECIFIER* aspec;
	A_ID* aid;
	S_KIND skind;
	T_KIND tkind;
} YYSTYPE;
#include "y.tab.h"

extern YYSTYPE yylval;

int yywrap(void);
extern int line_no;
extern A_ID *current_id; 
char *makeString();
int checkIdentifier();
%}

%%

"#include"	{ }
"<stdio.h>"	{ }
{ws}		{ }
{line}		{ line_no++; }
auto		{ return(AUTO_SYM); }
break		{ return(BREAK_SYM); }
case		{ return(CASE_SYM); }
continue	{ return(CONTINUE_SYM); }
default	{ return(DEFAULT_SYM); }
do		{ return(DO_SYM); }
else		{ return(ELSE_SYM); }
enum		{ return(ENUM_SYM); }
for		{ return(FOR_SYM); }
if		{ return(IF_SYM); }
return		{ return(RETURN_SYM); }
sizeof		{ return(SIZEOF_SYM); }
static		{ return(STATIC_SYM); }
struct		{ return(STRUCT_SYM); }
switch		{ return(SWITCH_SYM); }
typedef	{ return(TYPEDEF_SYM); }
union		{ return(UNION_SYM); }
while		{ return(WHILE_SYM); }

"\+\+"		{ return(PLUSPLUS); }
"\-\-"		{ return(MINUSMINUS); }
"\->"		{ return(ARROW); }
"<"		{ return(LSS); }
">"		{ return(GTR); }
"<="		{ return(LEQ); }
">="		{ return(GEQ); }
"=="		{ return(EQL); }
"!="		{ return(NEQ); }
"&&"		{ return(AMPAMP); }
"||"		{ return(BARBAR); }
"\.\.\."	{ return(DOTDOTDOT); }
"("		{ return(LP); }
")"		{ return(RP); }
"\["		{ return(LB); }
"\]"		{ return(RB); }
"\{"		{ return(LR); }
"\}"		{ return(RR); }
"\:"		{ return(COLON); }
"\."		{ return(PERIOD); }
"\,"		{ return(COMMA); }
"\!"		{ return(EXCL); }
"\*"		{ return(STAR); }
"\/"		{ return(SLASH); }
"\%"		{ return(PERCENT); }
"\&"		{ return(AMP); }
"\;"		{ return(SEMICOLON); }
"\+"		{ return(PLUS); }
"\-"		{ return(MINUS); }
"\="		{ return(ASSIGN); }


{digit}+			{ yylval.ival=atoi(yytext); return(INTEGER_CONSTANT); }
{digit}+\.{digit}+		{ yylval.pval=makeString(yytext); return(FLOAT_CONSTANT); }
{letter}({letter}|{digit})*	{ return(checkIdentifier(yytext)); }
\"([^"\n]|\\["\n])*\"		{ yylval.pval=makeString(yytext); return(STRING_LITERAL); }
\'([^'\n]|\'\')\'		{ yylval.cval=*(yytext+1); return(CHARACTER_CONSTANT); }
"//"[^\n]*			{ }

%%
		
char *makeString(char *s) {
	//printf("makeString called\n");
	char *t;
	t=malloc(strlen(s)+1);
	strcpy(t, s);
	return(t);
}

int checkIdentifier(char *s) {
	//printf("checkIdentifier called %s\n", s);
	A_ID *id=0;
	char *t;
	id=current_id;
	while(id) {
		if(strcmp(id->name, s)==0)
			break;
		id=id->prev; 
	}
	if(id==0) {
		yylval.pval=makeString(s);
		return(IDENTIFIER);
	}
	else if(id->kind==ID_TYPE) {
		yylval.atype=id->type;
		return(TYPE_IDENTIFIER);
	}
	else {
		yylval.pval=id->name;
		return(IDENTIFIER);
	}
}
