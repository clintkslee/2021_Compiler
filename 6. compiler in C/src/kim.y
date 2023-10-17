%{
#define YYSTYPE_IS_DECLARED  1
#define LIT_MAX 100 //sem
#include "type.h"

extern char* yytext;
int line_no=1;
int syntax_err=0;
A_NODE *root;
A_ID *current_id=NIL;
int current_level=0;
A_TYPE *int_type, *char_type, *void_type, *float_type, *string_type;

//sem
int global_address=12;
int semantic_err=0;
A_LITERAL literal_table[LIT_MAX];
int literal_no=0;
int literal_size=0;

//gen
int label_no=0;
int gen_err=0;

%}

%token<pval> FLOAT_CONSTANT STRING_LITERAL IDENTIFIER 
%token<cval> CHARACTER_CONSTANT 
%token<atype> TYPE_IDENTIFIER 
%token<ival> INTEGER_CONSTANT 
%token PLUS MINUS PLUSPLUS MINUSMINUS AMP BARBAR AMPAMP ARROW SEMICOLON 
        LSS GTR LEQ GEQ EQL NEQ DOTDOTDOT LP RP LB 
        RB LR RR PERIOD COMMA EXCL STAR SLASH PERCENT ASSIGN 
        COLON AUTO_SYM STATIC_SYM TYPEDEF_SYM STRUCT_SYM ENUM_SYM SIZEOF_SYM UNION_SYM IF_SYM ELSE_SYM 
        WHILE_SYM DO_SYM FOR_SYM CONTINUE_SYM BREAK_SYM RETURN_SYM SWITCH_SYM CASE_SYM DEFAULT_SYM 
	
%type<anode> program initializer initializer_list postfix_expression primary_expression unary_expression cast_expression multiplicative_expression additive_expression 
            shift_expression relational_expression equality_expression bitwise_and_expression bitwise_xor_expression bitwise_or_expression logical_and_expression 
            logical_or_expression conditional_expression assignment_expression comma_expression expression constant_expression constant_expression_opt 
            arg_expression_list arg_expression_list_opt jump_statement expression_opt for_expression iteration_statement selection_statement expression_statement 
            compound_statement labeled_statement statement statement_list statement_list_opt 
%type<atype> struct_specifier enum_specifier type_specifier type_name direct_abstract_declarator abstract_declarator abstract_declarator_opt pointer
%type<aspec> declaration_specifiers 
%type<aid> translation_unit declaration declaration_list init_declarator_list_opt init_declarator_list init_declarator struct_declaration_list struct_declaration 
            struct_declarator_list parameter_declaration parameter_list parameter_type_list parameter_type_list_opt direct_declarator declarator enumerator 
            enumerator_list struct_declarator declaration_list_opt external_declaration function_definition
%type<skind> storage_class_specifier
%type<tkind> struct_or_union

%start program

%%

program
	:translation_unit	
    {root=makeNode(N_PROGRAM, NIL, $1, NIL); checkForwardReference();}
	;
translation_unit
	:external_declaration                   {$$=$1;}
	|translation_unit external_declaration	{$$=linkDeclaratorList($1, $2);}
	;
external_declaration
	:function_definition	{$$=$1;}
	|declaration		    {$$=$1;}
	;
function_definition
	:declaration_specifiers declarator	{$<aid>$=setFunctionDeclaratorSpecifier($2, $1);}
	compound_statement			        {$$=setFunctionDeclaratorBody($<aid>3, $4);}
	|declarator				            {$<aid>$=setFunctionDeclaratorSpecifier($1, makeSpecifier(int_type, 0));}
	compound_statement 			        {$$=setFunctionDeclaratorBody($<aid>2, $3);}
	;
declaration_list_opt
	:/* empty */		{$$=NIL;}
	|declaration_list	{$$=$1;}
	;
declaration_list
	:declaration			        {$$=$1;}
	|declaration_list declaration	{$$=linkDeclaratorList($1, $2);}
	;	
declaration
	:declaration_specifiers init_declarator_list_opt SEMICOLON	    {$$=setDeclaratorListSpecifier($2, $1);}
	;
declaration_specifiers
	:type_specifier					                {$$=makeSpecifier($1, 0);}
	|storage_class_specifier				        {$$=makeSpecifier(0, $1);}
	|type_specifier declaration_specifiers	    	{$$=updateSpecifier($2, $1, 0);}
	|storage_class_specifier declaration_specifiers	{$$=updateSpecifier($2, 0, $1);}
	;
storage_class_specifier
	:AUTO_SYM	        {$$=S_AUTO;}
	|STATIC_SYM	        {$$=S_STATIC;}
	|TYPEDEF_SYM    	{$$=S_TYPEDEF;}
	;
init_declarator_list_opt
	:/* empty */	    	{$$=makeDummyIdentifier();}
	|init_declarator_list	{$$=$1;}
	;
init_declarator_list
	:init_declarator			            	{$$=$1;}
	|init_declarator_list COMMA init_declarator	{$$=linkDeclaratorList($1, $3);}
	;
init_declarator
	:declarator		        		{$$=$1;}
	|declarator ASSIGN initializer	{$$=setDeclaratorInit($1, $3);}
	;	
initializer
	:constant_expression		{$$=makeNode(N_INIT_LIST_ONE, NIL, $1, NIL);}
	|LR initializer_list RR	    {$$=$2;}
	;
initializer_list
	:initializer				        {$$=makeNode(N_INIT_LIST, $1, NIL, makeNode(N_INIT_LIST_NIL, NIL, NIL, NIL));}
	|initializer_list COMMA initializer	{$$=makeNodeList(N_INIT_LIST, $1, $3);}
	;
type_specifier
	:struct_specifier	{$$=$1;}
	|enum_specifier	    {$$=$1;}
	|TYPE_IDENTIFIER	{$$=$1;}
	;
struct_specifier
	:struct_or_union IDENTIFIER	
    {$<atype>$=setTypeStructOrEnumIdentifier($1, $2, ID_STRUCT);}
	LR  {$<aid>$=current_id; current_level++;}   struct_declaration_list RR
    {checkForwardReference(); $$=setTypeField($<atype>3, $6); current_level--; 
    current_id=$<aid>5;}
	|struct_or_union    {$<atype>$=makeType($1);}  LR  {$<aid>$=current_id; current_level++;}
	struct_declaration_list RR  {checkForwardReference(); $$=setTypeField($<atype>2, $5); 
    current_level--; current_id=$<aid>4;}
	|struct_or_union IDENTIFIER	
    {$$=getTypeOfStructOrEnumRefIdentifier($1, $2, ID_STRUCT);}
	;
struct_or_union
	:STRUCT_SYM	    {$$=T_STRUCT;}
	|UNION_SYM	    {$$=T_UNION;}
	; 
struct_declaration_list
	:struct_declaration				                {$$=$1;}
	|struct_declaration_list struct_declaration	    {$$=linkDeclaratorList($1, $2);}
	;
struct_declaration
	:type_specifier struct_declarator_list SEMICOLON	
    {$$=setStructDeclaratorListSpecifier($2, $1);}
	;
struct_declarator_list
	:struct_declarator				            	{$$=$1;}
	|struct_declarator_list COMMA struct_declarator	{$$=linkDeclaratorList($1, $3);}
	;
struct_declarator
	:declarator     {$$=$1;}
	;
enum_specifier
	:ENUM_SYM IDENTIFIER	
    {$<atype>$=setTypeStructOrEnumIdentifier(T_ENUM, $2, ID_ENUM);}
	LR enumerator_list RR	{$$=setTypeField($<atype>3, $5);}
	|ENUM_SYM		        {$<atype>$=makeType(T_ENUM);} 
	LR enumerator_list RR	{$$=setTypeField($<atype>2, $4);}
	|ENUM_SYM IDENTIFIER	
    {$$=getTypeOfStructOrEnumRefIdentifier(T_ENUM, $2, ID_ENUM);}
	;
enumerator_list
	:enumerator				            {$$=$1;}
	|enumerator_list COMMA enumerator	{$$=linkDeclaratorList($1, $3);}
	;
enumerator
	:IDENTIFIER		
    {$$=setDeclaratorKind(makeIdentifier($1), ID_ENUM_LITERAL);}
	|IDENTIFIER 		
    {$<aid>$=setDeclaratorKind(makeIdentifier($1), ID_ENUM_LITERAL);}
	ASSIGN expression	{$$=setDeclaratorInit($<aid>2, $4);}
	;
declarator
	:pointer direct_declarator	{$$=setDeclaratorElementType($2, $1);}
	|direct_declarator	    	{$$=$1;}
	;
pointer
	:STAR	    	{$$=makeType(T_POINTER);}
	|STAR pointer	{$$=setTypeElementType($2, makeType(T_POINTER));}		
	;
direct_declarator
	:IDENTIFIER			    {$$=makeIdentifier($1);}
	|LP declarator RP		{$$=$2;}
	|direct_declarator LB constant_expression_opt RB	
    {$$=setDeclaratorElementType($1, setTypeExpr(makeType(T_ARRAY), $3));}
	|direct_declarator LP	{$<aid>$=current_id; current_level++;} 
	parameter_type_list_opt RP	
    {checkForwardReference(); current_id=$<aid>3; current_level--; 
    $$=setDeclaratorElementType($1, setTypeField(makeType(T_FUNC), $4));}
	;
parameter_type_list_opt
	:/* empty */	    	{$$=NIL;}
	|parameter_type_list	{$$=$1;}
	;
parameter_type_list
	:parameter_list	                {$$=$1;}
	|parameter_list COMMA DOTDOTDOT	{$$=linkDeclaratorList($1, setDeclaratorKind(makeDummyIdentifier(), ID_PARM));}
	;
parameter_list
	:parameter_declaration                  	{$$=$1;}
	|parameter_list COMMA parameter_declaration	{$$=linkDeclaratorList($1, $3);}
	;
parameter_declaration
	:declaration_specifiers declarator	
    {$$=setParameterDeclaratorSpecifier($2, $1);}
	|declaration_specifiers abstract_declarator_opt	
    {$$=setParameterDeclaratorSpecifier(setDeclaratorType(makeDummyIdentifier(), $2), $1);}
	;
abstract_declarator_opt
	:/* empty */		    {$$=NIL;}
	|abstract_declarator	{$$=$1;}
	;
abstract_declarator
	:pointer	        		{$$=makeType(T_POINTER);}
	|direct_abstract_declarator	{$$=$1;}
	|pointer direct_abstract_declarator	
    {$$=setTypeElementType($2, makeType(T_POINTER));}
	;
direct_abstract_declarator
	:LP abstract_declarator RP					{$$=$2;}
	|LB constant_expression_opt RB				
    {$$=setTypeExpr(makeType(T_ARRAY), $2);}
	|direct_abstract_declarator LB constant_expression_opt RB	
    {$$=setTypeElementType($1, setTypeExpr(makeType(T_ARRAY), $3));}
	|LP parameter_type_list_opt RP				
    {$$=setTypeField(makeType(T_FUNC), $2);}
	|direct_abstract_declarator LP parameter_type_list_opt RP	
    {$$=setTypeElementType($1, setTypeField(makeType(T_FUNC), $3));}
	;
statement_list_opt
	:/* empty */	{$$=makeNode(N_STMT_LIST_NIL, NIL, NIL, NIL);}
	|statement_list	{$$=$1;}
	;
statement_list
	:statement		        	{$$=makeNode(N_STMT_LIST, $1, NIL, makeNode(N_STMT_LIST_NIL, NIL, NIL, NIL));}
	|statement_list statement	{$$=makeNodeList(N_STMT_LIST, $1, $2);}
	;
statement
	:labeled_statement  	{$$=$1;}
	|compound_statement	    {$$=$1;}
	|expression_statement	{$$=$1;}
	|selection_statement	{$$=$1;}
	|iteration_statement	{$$=$1;}
	|jump_statement	        {$$=$1;}
	;
labeled_statement
	:CASE_SYM constant_expression COLON statement	{$$=makeNode(N_STMT_LABEL_CASE, $2, NIL, $4);}
	|DEFAULT_SYM COLON statement	                {$$=makeNode(N_STMT_LABEL_DEFAULT, NIL, $3, NIL);}
	;	
compound_statement
	:LR {$<aid>$=current_id; current_level++;} declaration_list_opt 
	statement_list_opt RR	{checkForwardReference();
	$$=makeNode(N_STMT_COMPOUND, $3, NIL, $4); current_id=$<aid>2;
	current_level--;}
	;	
expression_statement
	:SEMICOLON		{$$=makeNode(N_STMT_EMPTY, NIL, NIL, NIL);}
	|expression SEMICOLON	{$$=makeNode(N_STMT_EXPRESSION, NIL, $1, NIL);}
	;
selection_statement
	:IF_SYM LP expression RP statement				        {$$=makeNode(N_STMT_IF, $3, NIL, $5);}
	|IF_SYM LP expression RP statement ELSE_SYM statement	{$$=makeNode(N_STMT_IF_ELSE, $3, $5, $7);}
	|SWITCH_SYM LP expression RP statement			        {$$=makeNode(N_STMT_SWITCH, $3, NIL, $5);}
	;
iteration_statement
	:WHILE_SYM LP expression RP statement               	{$$=makeNode(N_STMT_WHILE, $3, NIL, $5);}
	|DO_SYM statement WHILE_SYM LP expression RP SEMICOLON	{$$=makeNode(N_STMT_DO, $2, NIL, $5);}
	|FOR_SYM LP for_expression RP statement	                {$$=makeNode(N_STMT_FOR, $3, NIL, $5);}
	;
for_expression
	:expression_opt SEMICOLON expression_opt SEMICOLON expression_opt	{$$=makeNode(N_FOR_EXP, $1, $3, $5);}
	;
expression_opt
	:/* empty */	{$$=NIL;}
	|expression	    {$$=$1;}
	;
jump_statement
	:RETURN_SYM expression_opt SEMICOLON	{$$=makeNode(N_STMT_RETURN, NIL, $2, NIL);}
	|CONTINUE_SYM SEMICOLON		            {$$=makeNode(N_STMT_CONTINUE, NIL, NIL, NIL);}
	|BREAK_SYM SEMICOLON			        {$$=makeNode(N_STMT_BREAK, NIL, NIL, NIL);}
	;
arg_expression_list_opt
	:/* empty */		    {$$=makeNode(N_ARG_LIST_NIL, NIL, NIL, NIL);}
	|arg_expression_list	{$$=$1;}	
	;
arg_expression_list
	:assignment_expression	
    {$$=makeNode(N_ARG_LIST, $1, NIL, makeNode(N_ARG_LIST_NIL, NIL, NIL, NIL));}
	|arg_expression_list COMMA assignment_expression	
    {$$=makeNodeList(N_ARG_LIST, $1, $3);}
	;
constant_expression_opt
	:/* empty */	        {$$=NIL;}
	|constant_expression	{$$=$1;}
	;
constant_expression
	:expression          	{$$=$1;}
	;
expression
	:comma_expression	    {$$=$1;}
	;	
comma_expression
	:assignment_expression	{$$=$1;}
	;
assignment_expression
	:conditional_expression	                        {$$=$1;}
	|unary_expression ASSIGN assignment_expression	{$$=makeNode(N_EXP_ASSIGN, $1, NIL, $3);}
	;
conditional_expression
	:logical_or_expression	{$$=$1;}
	;
logical_or_expression
	:logical_and_expression	                                {$$=$1;}
	|logical_or_expression BARBAR logical_and_expression	{$$=makeNode(N_EXP_OR, $1, NIL, $3);}
	;	
logical_and_expression
	:bitwise_or_expression	                                {$$=$1;}
	|logical_and_expression AMPAMP bitwise_or_expression	{$$=makeNode(N_EXP_AND, $1, NIL, $3);}
	;
bitwise_or_expression
	:bitwise_xor_expression	{$$=$1;}
	;
bitwise_xor_expression
	:bitwise_and_expression	{$$=$1;}
	;
bitwise_and_expression
	:equality_expression	{$$=$1;}
	;
equality_expression
	:relational_expression	{$$=$1;}
	|equality_expression EQL relational_expression	{$$=makeNode(N_EXP_EQL, $1, NIL, $3);}
	|equality_expression NEQ relational_expression	{$$=makeNode(N_EXP_NEQ, $1, NIL, $3);}
	;	
relational_expression
	:shift_expression	{$$=$1;}
	|relational_expression LSS shift_expression	{$$=makeNode(N_EXP_LSS, $1, NIL, $3);}
	|relational_expression GTR shift_expression	{$$=makeNode(N_EXP_GTR, $1, NIL, $3);}
	|relational_expression LEQ shift_expression	{$$=makeNode(N_EXP_LEQ, $1, NIL, $3);}
	|relational_expression GEQ shift_expression	{$$=makeNode(N_EXP_GEQ, $1, NIL, $3);}
	;	
shift_expression
	:additive_expression	{$$=$1;}
	;
additive_expression
	:multiplicative_expression	{$$=$1;}
	|additive_expression PLUS multiplicative_expression	    {$$=makeNode(N_EXP_ADD, $1, NIL, $3);}
	|additive_expression MINUS multiplicative_expression	{$$=makeNode(N_EXP_SUB, $1, NIL, $3);}
	;	
multiplicative_expression
	:cast_expression	                                {$$=$1;}
	|multiplicative_expression STAR cast_expression 	{$$=makeNode(N_EXP_MUL, $1, NIL, $3);}
	|multiplicative_expression SLASH cast_expression	{$$=makeNode(N_EXP_DIV, $1, NIL, $3);}
	|multiplicative_expression PERCENT cast_expression	{$$=makeNode(N_EXP_MOD, $1, NIL, $3);}
	;
cast_expression
	:unary_expression	                {$$=$1;}
	|LP type_name RP cast_expression	{$$=makeNode(N_EXP_CAST, $2, NIL, $4);}
	;	
unary_expression
	:postfix_expression	            {$$=$1;}
	|PLUSPLUS unary_expression	    {$$=makeNode(N_EXP_PRE_INC, NIL, $2, NIL);}
	|MINUSMINUS unary_expression	{$$=makeNode(N_EXP_PRE_DEC, NIL, $2, NIL);}
	|AMP cast_expression		    {$$=makeNode(N_EXP_AMP, NIL, $2, NIL);}
	|STAR cast_expression		    {$$=makeNode(N_EXP_STAR, NIL, $2, NIL);}
	|EXCL cast_expression		    {$$=makeNode(N_EXP_NOT, NIL, $2, NIL);}
	|MINUS cast_expression		    {$$=makeNode(N_EXP_MINUS, NIL, $2, NIL);}
	|PLUS cast_expression		    {$$=makeNode(N_EXP_PLUS, NIL, $2, NIL);}
	|SIZEOF_SYM unary_expression	{$$=makeNode(N_EXP_SIZE_EXP, NIL, $2, NIL);}
	|SIZEOF_SYM LP type_name RP	    {$$=makeNode(N_EXP_SIZE_TYPE, NIL, $3, NIL);}
	;
postfix_expression
	:primary_expression	{$$=$1;}
	|postfix_expression LB expression RB	            {$$=makeNode(N_EXP_ARRAY, $1, NIL, $3);}
	|postfix_expression LP arg_expression_list_opt RP	{$$=makeNode(N_EXP_FUNCTION_CALL, $1, NIL, $3);}
	|postfix_expression PERIOD IDENTIFIER	            {$$=makeNode(N_EXP_STRUCT, $1, NIL, $3);}
	|postfix_expression ARROW IDENTIFIER               	{$$=makeNode(N_EXP_ARROW, $1, NIL, $3);}
	|postfix_expression PLUSPLUS	                	{$$=makeNode(N_EXP_POST_INC, NIL, $1, NIL);}
	|postfix_expression MINUSMINUS	                    {$$=makeNode(N_EXP_POST_DEC, NIL, $1, NIL);}
	;		
primary_expression
	:IDENTIFIER     	{$$=makeNode(N_EXP_IDENT, NIL, getIdentifierDeclared($1), NIL);}
	|INTEGER_CONSTANT	{$$=makeNode(N_EXP_INT_CONST, NIL, $1, NIL);}
	|FLOAT_CONSTANT	    {$$=makeNode(N_EXP_FLOAT_CONST, NIL, $1, NIL);}
	|CHARACTER_CONSTANT	{$$=makeNode(N_EXP_CHAR_CONST, NIL, $1, NIL);}
	|STRING_LITERAL 	{$$=makeNode(N_EXP_STRING_LITERAL, NIL, $1, NIL);}
	|LP expression RP	{$$=$2;}
	;
type_name
	:declaration_specifiers abstract_declarator_opt	{$$=setTypeNameSpecifier($2, $1);}
	;

%%

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "y.tab.h"

//included from yacc
extern char *yytext;

FILE* fout;

void yyerror(char *s) {
	syntax_err++;
	printf("line %d: %s near %s \n", line_no, s, yytext);
}
int yywrap(void) {
	return(1);
}

int main()
{	
    fout=fopen("a.asm", "w");
	initialize();
    
	yyparse();
    if(syntax_err) exit(1);
	print_ast(root);
	printf("=========== syntax analysis fin\n");
	
	semantic_analysis(root);
    if(semantic_err) exit(1);
	print_sem_ast(root);
    printf("=========== semantic analysis fin\n");
	
    code_generation(root);
    printf("=========== code generation fin\n");

    fclose(fout);
	return 0;
}

//A4 Supporting Functions for Syntax Analysis

A_NODE* makeNode(NODE_NAME n, A_NODE* a, A_NODE* b, A_NODE* c) {
	//printf("makeNode called\n");
	A_NODE* m;
	m=(A_NODE*)malloc(sizeof(A_NODE));
	m->name=n;
	m->llink=a;
	m->clink=b;
	m->rlink=c;
	m->type=NIL;
	m->line=line_no;
	m->value=0;
	return(m);
}

A_NODE* makeNodeList(NODE_NAME n, A_NODE* a, A_NODE* b) {
	//printf("makeNodeList called\n");
	A_NODE *m, *k;
	k=a;
	while(k->rlink)
		k=k->rlink;
	m=(A_NODE*)malloc(sizeof(A_NODE));
	m->name=k->name;
	m->llink=NIL;
	m->clink=NIL;
	m->rlink=NIL;
	m->type=NIL;
	m->line=line_no;
	m->value=0;
	k->name=n;
	k->llink=b;
	k->rlink=m;
	return(a);
}

A_ID* makeIdentifier(char* s) {
	//printf("makeIdentifier called\n");
	A_ID *id;
	id=(A_ID*)malloc(sizeof(A_ID));
	id->name=s;
	id->kind=0;
	id->specifier=0;
	id->level=current_level;
	id->address=0;
	id->init=NIL;
	id->type=NIL;
	id->link=NIL;
	id->line=line_no;
	id->value=0;
	id->prev=current_id;
	current_id=id;
	return(id);
}

A_ID* makeDummyIdentifier() {
	//printf("makeDummyIdentifier called\n");
	A_ID *id;
	id=malloc(sizeof(A_ID));
	id->name="";
	id->kind=0;
	id->specifier=0;
	id->level=current_level;
	id->address=0;
	id->init=NIL;
	id->type=NIL;
	id->link=NIL;
	id->line=line_no;
	id->value=0;
	id->prev=0;
	return(id);
}

A_TYPE* makeType(T_KIND k) {
	//printf("makeType called\n");
	A_TYPE* t;
	t=malloc(sizeof(A_TYPE));
	t->kind=k;
	t->size=0;
	t->local_var_size=0;
	t->element_type=NIL;
	t->field=NIL;
	t->expr=NIL;
	t->check=FALSE;
	t->prt=FALSE;
	t->line=line_no;
	return(t);
}

A_SPECIFIER* makeSpecifier(A_TYPE* t, S_KIND s) {
	//printf("makeSpecifier called\n");
	A_SPECIFIER* p;
	p=malloc(sizeof(A_SPECIFIER));
	p->type=t;
	p->stor=s;
	p->line=line_no;
	return(p);
}

A_ID* searchIdentifier(char* s, A_ID* id) {
	//printf("searchIdentifier called\n");
	while(id) {
		if(strcmp(id->name, s)==0)
			break;
		id=id->prev;
	}
	return(id);
}

A_ID* searchIdentifierAtCurrentLevel(char* s, A_ID* id) {
	//printf("searchIdentifierAtCurrentLevel called\n");
	while(id) {
		if(id->level<current_level)
			return(NIL);
		if(strcmp(id->name, s)==0)
			break;
		id=id->prev;
	}
	return(id);
}

A_SPECIFIER* updateSpecifier(A_SPECIFIER* p, A_TYPE* t, S_KIND s) {
	//printf("updateSpecifier called\n");
	if(t) {
		if(p->type) {
			if(p->type==t) ;
			else syntax_error(24, 0);
		}
		else
			p->type=t;
	}
	if(s) {
		if(p->stor) {
			if(s==p->stor) ;
			else syntax_error(24, 0);
		}
		else
			p->stor=s;
	}
	return(p);
}
				
void checkForwardReference() {
	//printf("checkForwardReference called\n");
	A_ID* id;
	A_TYPE* t;
	id=current_id;
	while(id) {
		if(id->level<current_level)
			break;
		t=id->type;
		if(id->kind==ID_NULL)
			syntax_error(31, id->name);
		else if((id->kind==ID_STRUCT||id->kind==ID_ENUM)&&t->field==NIL)
			syntax_error(32, id->name);
		id=id->prev;
	}
}

void setDefaultSpecifier(A_SPECIFIER* p) {
	//printf("setDefaultSpecifier called\n");
	A_TYPE* t;
	if(p->type==NIL)
		p->type=int_type;
	if(p->stor==S_NULL)
		p->stor=S_AUTO;
}

A_ID* linkDeclaratorList(A_ID* id1, A_ID* id2) {
	//printf("linkDeclaratorList called\n");
	A_ID* m=id1;
	if(id1==NIL)
		return(id2);
	while(m->link)
		m=m->link;
	m->link=id2;
	return(id1);
}	

A_ID* getIdentifierDeclared(char* s) {
	//printf("getIdentifierDeclared called\n");
	A_ID* id;
	id=searchIdentifier(s, current_id);
	if(id==NIL)
		syntax_error(13, s);
	return(id);	
}

A_TYPE* getTypeOfStructOrEnumRefIdentifier(T_KIND k, char* s, ID_KIND kk) {
	//printf("getTypeOfStructOrEnumRefIdentifier called\n");
	A_TYPE* t;
	A_ID* id;
	id=searchIdentifier(s, current_id);
	if(id) {
		if(id->kind==kk && id->type->kind==k)
			return(id->type);
		else
			syntax_error(11, s);
	}
	t=makeType(k);
	id=makeIdentifier(s);
	id->kind=kk;
	id->type=t;
	return(t);
}

A_ID* setDeclaratorInit(A_ID* id, A_NODE* n) {
	//printf("setDeclaratorInit called\n");
	id->init=n;
	return(id);
}

A_ID* setDeclaratorKind(A_ID* id, ID_KIND k) {
	//printf("setDeclaratorKind called\n");
	A_ID* a;
	a=searchIdentifierAtCurrentLevel(id->name, id->prev);
	if(a)
		syntax_error(12, id->name);
	id->kind=k;
	return(id);
}	

A_ID* setDeclaratorType(A_ID* id, A_TYPE* t) {
	//printf("setDeclaratorType called\n");
	id->type=t;
	return(id);
}

A_ID* setDeclaratorElementType(A_ID* id, A_TYPE* t) {
	//printf("setDeclaratorElementType called\n");
	A_TYPE* tt;
	if(id->type==NIL)
		id->type=t;
	else {
		tt=id->type;
		while(tt->element_type)
			tt=tt->element_type;
		tt->element_type=t;
	}
	return(id);
}

A_ID* setDeclaratorTypeAndKind(A_ID* id, A_TYPE* t, ID_KIND k) {
	//printf("setDeclaratorTypeAndKind called\n");
	id=setDeclaratorElementType(id, t);
	id=setDeclaratorKind(id, k);
	return(id);
}

A_ID* setDeclaratorListSpecifier(A_ID* id, A_SPECIFIER* p) {
	//printf("setDeclaratorListSpecifier called\n");
	A_ID* a;
	setDefaultSpecifier(p);
	a=id;
	while(a) {
		if(strlen(a->name) && searchIdentifierAtCurrentLevel(a->name, a->prev))
			syntax_error(12, a->name);
		a=setDeclaratorElementType(a, p->type);
		if(p->stor==S_TYPEDEF)
			a->kind=ID_TYPE;
		else if(a->type->kind==T_FUNC)
			a->kind=ID_FUNC;
		else
			a->kind=ID_VAR;
		a->specifier=p->stor;
		if(a->specifier==S_NULL)
			a->specifier=S_AUTO;
		a=a->link;
	}
	return(id);
}

A_ID* setFunctionDeclaratorSpecifier(A_ID* id, A_SPECIFIER* p) {
	//printf("setFunctionDeclaratorSpecifier called\n");
	A_ID* a;
	if(p->stor)
		syntax_error(25, 0);
	setDefaultSpecifier(p);
	if(id->type->kind!=T_FUNC) {
		syntax_error(21, 0);
		return(id);
	}
	else {
		id=setDeclaratorElementType(id, p->type);
		id->kind=ID_FUNC;
	}
	a=searchIdentifierAtCurrentLevel(id->name, id->prev);
	if(a) {
		if(a->kind!=ID_FUNC || a->type->expr)
			syntax_error(12, id->name);
		else {
			if(isNotSameFormalParameters(a->type->field, id->type->field))
				syntax_error(22, id->name);
			if(isNotSameType(a->type->element_type, id->type->element_type))
				syntax_error(26, a->name);
		}
	}
	a=id->type->field;
	while(a) {
		if(strlen(a->name))
			current_id=a;
		else if(a->type)
			syntax_error(23, 0);
		a=a->link;
	}
	return(id);
}

A_ID* setFunctionDeclaratorBody(A_ID* id, A_NODE* n) {
	//printf("setFunctionDeclaratorBody called\n");
	id->type->expr=n;
	return(id);
}

A_ID* setParameterDeclaratorSpecifier(A_ID* id, A_SPECIFIER* p) {
	//printf("setParameterDeclaratorSpecifier called\n");
	if(searchIdentifierAtCurrentLevel(id->name, id->prev))
		syntax_error(12, id->name);
	if(p->stor || p->type==void_type)
		syntax_error(14, 0);
	setDefaultSpecifier(p);
	id=setDeclaratorElementType(id, p->type);
	id->kind=ID_PARM;
	return(id);
}

A_ID* setStructDeclaratorListSpecifier(A_ID* id, A_TYPE* t) {
	//printf("setStructDeclaratorListSpecifier called\n");
	A_ID *a;
	a=id;
	while(a) {
		if(searchIdentifierAtCurrentLevel(a->name, a->prev))
			syntax_error(12, a->name);
		a=setDeclaratorElementType(a, t);
		a->kind=ID_FIELD;
		a=a->link;
	}
	return(id);
}

A_TYPE* setTypeNameSpecifier(A_TYPE* t, A_SPECIFIER* p) {
	//printf("setTypeNameSpecifier called\n");
	if(p->stor)
		syntax_error(20, 0);
	setDefaultSpecifier(p);
	t=setTypeElementType(t, p-> type);
	return(t);
}

A_TYPE* setTypeElementType(A_TYPE* t, A_TYPE* s) {
	//printf("setTypeElementType called\n");
	A_TYPE* q;
	if(t==NIL)
		return(s);
	q=t;
	while(q->element_type)
		q=q->element_type;
	q->element_type=s;
	return(t);
}

A_TYPE* setTypeField(A_TYPE* t, A_ID* n) {
	//printf("setTypeField called\n");
	t->field=n;
	return(t);
}

A_TYPE* setTypeExpr(A_TYPE* t, A_NODE* n) {
	//printf("setTypeExpr called\n");
	t->expr=n;
	return(t);
}

A_TYPE* setTypeAndKindOfDeclarator(A_TYPE* t, ID_KIND k, A_ID* id) {
	//printf("setTypeAndKindOfDeclarator called\n");
	if(searchIdentifierAtCurrentLevel(id->name, id->prev))
		syntax_error(12, id->name);
	id->type=t;
	id->kind=k;
	return(t);
}

A_TYPE* setTypeStructOrEnumIdentifier(T_KIND k, char* s, ID_KIND kk) {
	//printf("setTypeStructOrEnumIdentifier called\n");
	A_TYPE* t;
	A_ID *id, *a;
	a=searchIdentifierAtCurrentLevel(s, current_id);
	if(a) {
		if(a->kind==kk && a->type->kind==k) {
			if(a->type->field)
				syntax_error(12, s);
			else
				return(a->type);
		}
		else
			syntax_error(12, s);
	}
	id=makeIdentifier(s);
	t=makeType(k);
	id->type=t;
	id->kind=kk;
	return(t);
}

BOOLEAN isNotSameFormalParameters(A_ID* a, A_ID* b) {
	//printf("isNotSameFormalParameters called\n");
	if(a==NIL)
		return(FALSE);
	while(a) {
		if(b==NIL || isNotSameType(a->type, b->type))
			return(TRUE);
		a=a->link;
		b=b->link;
	}
	if(b)
		return(TRUE);
	else
		return(FALSE);	
}

BOOLEAN isNotSameType(A_TYPE* t1, A_TYPE* t2) {
	//printf("isNotSameType called\n");
	if(isPointerOrArrayType(t1) || isPointerOrArrayType(t2))
		return(isNotSameType(t1->element_type, t2->element_type));
	else
		return(t1!=t2);
}


void initialize() {
	int_type=setTypeAndKindOfDeclarator(makeType(T_ENUM), ID_TYPE, makeIdentifier("int"));
	float_type=setTypeAndKindOfDeclarator(makeType(T_ENUM), ID_TYPE, makeIdentifier("float"));
	char_type=setTypeAndKindOfDeclarator(makeType(T_ENUM), ID_TYPE, makeIdentifier("char"));
	void_type=setTypeAndKindOfDeclarator(makeType(T_VOID), ID_TYPE, makeIdentifier("void"));
	string_type=setTypeElementType(makeType(T_POINTER), char_type);
	int_type->size=4;	int_type->check=TRUE;
	float_type->size=4;	float_type->check=TRUE;
	char_type->size=1;	char_type->check=TRUE;
	void_type->size=0;	void_type->check=TRUE;
	string_type->size=4;	string_type->check=TRUE;
	setDeclaratorTypeAndKind(
		makeIdentifier("printf"), 
		setTypeField(
			setTypeElementType(makeType(T_FUNC), void_type), 
			linkDeclaratorList(
				setDeclaratorTypeAndKind(makeDummyIdentifier(), string_type, ID_PARM),
				setDeclaratorKind(makeDummyIdentifier(), ID_PARM))), 
		ID_FUNC);
	setDeclaratorTypeAndKind(
		makeIdentifier("scanf"), 
		setTypeField(
			setTypeElementType(makeType(T_FUNC), void_type), 
			linkDeclaratorList(
				setDeclaratorTypeAndKind(makeDummyIdentifier(), string_type, ID_PARM),
				setDeclaratorKind(makeDummyIdentifier(), ID_PARM))), 
		ID_FUNC);
	setDeclaratorTypeAndKind(
		makeIdentifier("malloc"), 
		setTypeField(
			setTypeElementType(makeType(T_FUNC), string_type), 
			setDeclaratorTypeAndKind(makeDummyIdentifier(), int_type, ID_PARM)),
		ID_FUNC);		
}

void syntax_error(int i, char* s) {
	syntax_err++;
	printf("line %d: syntax error: ", line_no);
	switch(i) {
		case 11: printf("illegal referencing struct or union identifier %s", s); break;
		case 12: printf("redeclaration of identifier %s", s); break;
		case 13: printf("undefined identifier %s", s); break;
		case 14: printf("illegal type specifier in formal parameter"); break;
		case 20: printf("illegal storage class in type specifiers"); break;
		case 21: printf("illegal function declarator"); break;
		case 22: printf("conflicting parameter type in prototype function %s", s); break;
		case 23: printf("empty parameter name"); break;
		case 24: printf("illegal declaration specifiers"); break;
		case 25: printf("illegal function specifiers"); break;
		case 26: printf("illegal or conflicting return type in function %s", s); break;
		case 31: printf("undefined type for identifier %s", s); break;
		case 32: printf("incomplete forward reference for identifier %s", s); break;
		default: printf("unknown"); break;
	}
	if(strlen(yytext)==0)
		printf(" at end\n");
	else
		printf(" near %s\n", yytext);
}

////////////////////////////// print syntax tree

char * node_name[] = {
	"N_NULL",
	"N_PROGRAM",
	"N_EXP_IDENT",
	"N_EXP_INT_CONST",
	"N_EXP_FLOAT_CONST",
	"N_EXP_CHAR_CONST",
	"N_EXP_STRING_LITERAL",
	"N_EXP_ARRAY",
	"N_EXP_FUNCTION_CALL",
	"N_EXP_STRUCT",	
    "N_EXP_ARROW",
	"N_EXP_POST_INC",
	"N_EXP_POST_DEC",
	"N_EXP_PRE_INC",
	"N_EXP_PRE_DEC",
	"N_EXP_AMP",
	"N_EXP_STAR",
	"N_EXP_NOT",
	"N_EXP_PLUS",
	"N_EXP_MINUS",	
    "N_EXP_SIZE_EXP",
	"N_EXP_SIZE_TYPE",
	"N_EXP_CAST",
	"N_EXP_MUL",
	"N_EXP_DIV",
	"N_EXP_MOD",
	"N_EXP_ADD",
	"N_EXP_SUB",
	"N_EXP_LSS",
	"N_EXP_GTR",	
    "N_EXP_LEQ",
	"N_EXP_GEQ",
	"N_EXP_NEQ",
	"N_EXP_EQL",
	"N_EXP_AND",
	"N_EXP_OR",
	"N_EXP_ASSIGN",
	"N_ARG_LIST",
	"N_ARG_LIST_NIL",
	"N_STMT_LABEL_CASE",	
    "N_STMT_LABEL_DEFAULT",
	"N_STMT_COMPOUND",
	"N_STMT_EMPTY",
	"N_STMT_EXPRESSION",
	"N_STMT_IF",
	"N_STMT_IF_ELSE",
	"N_STMT_SWITCH",
	"N_STMT_WHILE",
	"N_STMT_DO",
	"N_STMT_FOR",	
    "N_STMT_RETURN",
	"N_STMT_CONTINUE",
	"N_STMT_BREAK",
	"N_FOR_EXP",
	"N_STMT_LIST",
	"N_STMT_LIST_NIL",
	"N_INIT_LIST",
	"N_INIT_LIST_ONE",
	"N_INIT_LIST_NIL"};

void print_node(A_NODE *node, int s) {
	print_space(s);
	printf("%s (%x,%d)\n", node_name[node->name],node->type,node->value);
}
void print_space(int s)
{
	int i;
	for(i=1; i<=s; i++) printf("|  ");
}
void print_ast(A_NODE *node) 
{
	printf("==========  syntax tree  ==========\n");
	prt_program(node,0);
}
void prt_program(A_NODE *node, int s)
{
	print_node(node,s);
	switch(node->name) {
	   case N_PROGRAM:
		prt_A_ID_LIST(node->clink, s+1);
		break;
	   default :
		printf("****** syntax tree error ******");
	}
}
void prt_initializer(A_NODE *node, int s)
{
	print_node(node,s);
	switch(node->name) {
	   case N_INIT_LIST:
		prt_initializer(node->llink, s+1);
		prt_initializer(node->rlink, s+1);
		break;
	   case N_INIT_LIST_ONE:
		prt_expression(node->clink, s+1);
		break;
	   case N_INIT_LIST_NIL:
		break;
	   default :
		printf("****** syntax tree error ******");
	}
}
void prt_expression(A_NODE *node, int s)
{
	print_node(node,s);
	switch(node->name) {
	   case N_EXP_IDENT : 
		prt_A_ID_NAME(node->clink, s+1);
		break;
	   case N_EXP_INT_CONST :
		prt_integer(node->clink, s+1);
		break;
	   case N_EXP_FLOAT_CONST :
 		prt_STRING(node->clink, s+1);
		break;
	   case N_EXP_CHAR_CONST :
 		prt_integer(node->clink, s+1);
		break;
	   case N_EXP_STRING_LITERAL :
		prt_STRING(node->clink, s+1);
		break;
	   case N_EXP_ARRAY :
		prt_expression(node->llink, s+1);
		prt_expression(node->rlink, s+1);
		break;
	   case N_EXP_FUNCTION_CALL : 
		prt_expression(node->llink, s+1);
		prt_arg_expr_list(node->rlink, s+1);
		break;
	   case N_EXP_STRUCT : 
	   case N_EXP_ARROW : 
		prt_expression(node->llink, s+1);
		prt_STRING(node->rlink, s+1);
		break;
	   case N_EXP_POST_INC :
	   case N_EXP_POST_DEC :
	   case N_EXP_PRE_INC :
	   case N_EXP_PRE_DEC :
	   case N_EXP_AMP :
	   case N_EXP_STAR :
	   case N_EXP_NOT :
	   case N_EXP_PLUS :
	   case N_EXP_MINUS :
	   case N_EXP_SIZE_EXP :
		prt_expression(node->clink, s+1);
   		break;
	   case N_EXP_SIZE_TYPE :
		prt_A_TYPE(node->clink, s+1);
   		break;
	   case N_EXP_CAST :
		prt_A_TYPE(node->llink, s+1);
		prt_expression(node->rlink, s+1);
   		break;
	   case N_EXP_MUL :
	   case N_EXP_DIV :
	   case N_EXP_MOD :
	   case N_EXP_ADD :
	   case N_EXP_SUB : 
	   case N_EXP_LSS :
	   case N_EXP_GTR :
	   case N_EXP_LEQ :
	   case N_EXP_GEQ :
	   case N_EXP_NEQ :
	   case N_EXP_EQL :
	   case N_EXP_AND :
	   case N_EXP_OR :
	   case N_EXP_ASSIGN :
		prt_expression(node->llink, s+1);
		prt_expression(node->rlink, s+1);
   		break;
	   default : 
		printf("****** syntax tree error ******");
	}
}
void prt_arg_expr_list(A_NODE *node, int s)
{
	print_node(node,s);
	switch(node->name) {
	   case N_ARG_LIST : 
		prt_expression(node->llink, s+1);
		prt_arg_expr_list(node->rlink, s+1);
		break;
	   case N_ARG_LIST_NIL : 
		break;
	   default :
		printf("****** syntax tree error ******");
	}	
}
void prt_statement(A_NODE *node, int s)
{
	print_node(node,s);
	 
	switch(node->name) {
	   case N_STMT_LABEL_CASE :
		prt_expression(node->llink, s+1);
		prt_statement(node->rlink, s+1);
		break;
	   case N_STMT_LABEL_DEFAULT :
		prt_statement(node->clink, s+1);
		break;
	   case N_STMT_COMPOUND:
		if(node->llink) 
			prt_A_ID_LIST(node->llink, s+1);
		prt_statement_list(node->rlink, s+1);
		break;
	   case N_STMT_EMPTY:
		break;
	   case N_STMT_EXPRESSION:
		prt_expression(node->clink, s+1);
		break;
	   case N_STMT_IF_ELSE:
		prt_expression(node->llink, s+1);
		prt_statement(node->clink, s+1);
		prt_statement(node->rlink, s+1);
		break;
	   case N_STMT_IF:
	   case N_STMT_SWITCH:
		prt_expression(node->llink, s+1);
		prt_statement(node->rlink, s+1);
		break;
	   case N_STMT_WHILE:
		prt_expression(node->llink, s+1);
		prt_statement(node->rlink, s+1);
		break;
	   case N_STMT_DO:
		prt_statement(node->llink, s+1);
		prt_expression(node->rlink, s+1);
		break;
	   case N_STMT_FOR:
		prt_for_expression(node->llink, s+1);
		prt_statement(node->rlink, s+1);
		break;
	   case N_STMT_CONTINUE:
		break;
	   case N_STMT_BREAK:
		break;
	   case N_STMT_RETURN:
		if(node->clink) 
			prt_expression(node->clink, s+1);
		break;
	   default :
		printf("****** syntax tree error ******");
	}
}
void prt_statement_list(A_NODE *node, int s)
{
	print_node(node,s);
	switch(node->name) {
	case N_STMT_LIST:
		prt_statement(node->llink, s+1);
		prt_statement_list(node->rlink, s+1);
		break;
	case N_STMT_LIST_NIL:
		break;
	default :
		printf("****** syntax tree error ******");
		
	}
}
void prt_for_expression(A_NODE *node, int s)
{
	print_node(node,s);
	
	switch(node->name) {
		
	   case N_FOR_EXP :
		if(node->llink) 
			prt_expression(node->llink, s+1);
		if(node->clink) 
			prt_expression(node->clink, s+1);
		if(node->rlink) 
			prt_expression(node->rlink, s+1);
		break;
	   default :
		printf("****** syntax tree error ******");
	}
}
void prt_integer(int a, int s)
{
	print_space(s);
	printf("%d\n", a);
}
void prt_STRING(char *str, int s) {
	print_space(s);
	printf("%s\n", str);
}
char *type_kind_name[]={"NULL","ENUM","ARRAY","STRUCT","UNION","FUNC","POINTER","VOID"};
	
void prt_A_TYPE(A_TYPE *t, int s) 
{
	print_space(s);
	if (t==int_type) 
		printf("(int)\n");
	else if (t==float_type) 
		printf("(float)\n");
	else if (t==char_type) 
		printf("(char %d)\n",t->size);
	else if (t==void_type)
		printf("(void)\n");
	else if (t->kind==T_NULL)
		printf("(null)");
	else if (t->prt)
		printf("(DONE:%p)\n",t);
	else 
	   switch (t->kind) {
		case T_ENUM:
			t->prt=TRUE;
			printf("ENUM\n");
			print_space(s); printf("|  ENUMERATORS\n");
			prt_A_ID_LIST(t->field,s+2);
			break;
		case T_POINTER:
			t->prt=TRUE;
			printf("POINTER\n");
			print_space(s); printf("|  ELEMENT_TYPE\n");
			prt_A_TYPE(t->element_type,s+2);
			break;
		case T_ARRAY:
			t->prt=TRUE;
			printf("ARRAY\n");
			print_space(s); printf("|  INDEX\n");
			if (t->expr)
				prt_expression(t->expr,s+2);
			else {
				print_space(s+2); 
				printf("(none)\n");
			}
			print_space(s); printf("|  ELEMENT_TYPE\n");
			prt_A_TYPE(t->element_type,s+2);
			break;
		case T_STRUCT:
			t->prt=TRUE;
			printf("STRUCT\n");
			print_space(s); printf("|  FIELD\n");
			prt_A_ID_LIST(t->field,s+2);
			break;
		case T_UNION:
			t->prt=TRUE;
			printf("UNION\n");
			print_space(s); printf("|  FIELD\n");
			prt_A_ID_LIST(t->field,s+2);
			break;
		case T_FUNC:
			t->prt=TRUE;
			printf("FUNCTION\n");
			print_space(s); printf("|  PARAMETER\n");
			prt_A_ID_LIST(t->field,s+2);
			print_space(s); printf("|  TYPE\n");
			prt_A_TYPE(t->element_type,s+2);
			if (t->expr) {
				print_space(s); printf("|  BODY\n");
				prt_statement(t->expr,s+2);}
	   }
}
void prt_A_ID_LIST(A_ID *id, int s)
{
	while (id) {
		prt_A_ID(id,s);
		id=id->link;
	}
}
char *id_kind_name[]={"NULL","VAR","FUNC","PARM","FIELD","TYPE","ENUM", "STRUCT","ENUM_LITERAL"};
char *spec_name[]={"NULL","AUTO","STATIC","TYPEDEF"};
void prt_A_ID_NAME(A_ID *id, int s)
{
	print_space(s);
	printf("(ID=\"%s\") TYPE:%p KIND:%s SPEC=%s LEV=%d VAL=%d ADDR=%d \n", 
		id->name, id->type, id_kind_name[id->kind], spec_name[id->specifier], id->level, id->value, id->address);
}
void prt_A_ID(A_ID *id, int s)
{
	print_space(s);
	printf("(ID=\"%s\") TYPE:%p KIND:%s SPEC=%s LEV=%d VAL=%d ADDR=%d \n", 
		id->name, id->type,id_kind_name[id->kind], spec_name[id->specifier],id->level, id->value, id->address);
	if (id->type) {
		print_space(s);
		printf("|  TYPE\n");
		prt_A_TYPE(id->type,s+2);}
	if (id->init) {
		print_space(s);
		printf("|  INIT\n");
		if (id->kind==ID_ENUM_LITERAL)
			prt_expression(id->init,s+2);
		else 
			prt_initializer(id->init,s+2); }
}

// A6 semantic analyzer /////////////////////////////////////////////////

void semantic_analysis(A_NODE* node) {
    sem_program(node);
    set_literal_address(node);	
}

void set_literal_address(A_NODE* node) {
    int i;
    for(i=1; i<=literal_no; i++)
        literal_table[i].addr+=node->value;
    node->value+=literal_size;
}

void sem_program(A_NODE* node) {
    int i;
    switch(node->name) {
        case N_PROGRAM:
            i=sem_declaration_list(node->clink, 12);
            node->value=global_address;
            break;
        default:
            semantic_error(90, node->line, 0);
            break;
   }
}
int put_literal(A_LITERAL lit, int ll) {
    float ff;
    if(literal_no>=LIT_MAX) 
        semantic_error(93, ll, 0);
    else
        literal_no++;
    literal_table[literal_no]=lit;
    literal_table[literal_no].addr=literal_size;
    if(lit.type->kind==T_ENUM)
        literal_size+=4;
    else if(isStringType(lit.type))
        literal_size+=strlen(lit.value.s)+1;
    if(literal_size%4)
        literal_size=literal_size/4*4+4;
    return (literal_no);
}
A_TYPE* sem_expression(A_NODE* node) {
    A_TYPE* result=NIL, *t, *t1, *t2;
    A_ID *id;
    A_LITERAL lit;
    int i;
    BOOLEAN lvalue=FALSE;
    switch(node->name) {
        case N_EXP_IDENT:
            id=node->clink;
            switch(id->kind) {
                case ID_VAR:
                case ID_PARM:
                    result=id->type;
                    if(!isArrayType(result))
                        lvalue=TRUE;
                    break;
                case ID_FUNC:
                    result=id->type;
                    break;
                case ID_ENUM_LITERAL:
                    result=int_type;
                    break;
                default:
                    semantic_error(38, node->line, id->name);
                    break;
            }
            break;
        case N_EXP_INT_CONST:
            result=int_type;
            break;
        case N_EXP_FLOAT_CONST:
            lit.type=float_type;
            lit.value.f=atof(node->clink);
            node->clink=put_literal(lit, node->line); //index of literal table
            result=float_type;
            break;
        case N_EXP_CHAR_CONST:
            result=char_type;
            break;
        case N_EXP_STRING_LITERAL:
            lit.type=string_type;
            lit.value.s=node->clink;
            node->clink=put_literal(lit, node->line); //index of literal table
            result=string_type;
            break;
        case N_EXP_ARRAY:
            t1=sem_expression(node->llink);
            t2=sem_expression(node->rlink);
            //usual binary conversion
            t=convertUsualBinaryConversion(node);
            t1=node->llink->type;
            t2=node->rlink->type;
            if(isPointerOrArrayType(t1))
                result=t1->element_type;
            else   
                semantic_error(32, node->line, 0);
            if(!isIntegralType(t2))
                semantic_error(29, node->line, 0);
            if(!isArrayType(result))
                lvalue=TRUE;
            break;
        case N_EXP_STRUCT:
            t=sem_expression(node->llink);
            id=getStructFieldIdentifier(t, node->rlink);
            if(id) {
                result=id->type;
                if(node->llink->value && !isArrayType(result))
                    lvalue=TRUE;
            }
            else
                semantic_error(37, node->line, 0);
            node->rlink=id;
            break;
        case N_EXP_ARROW:
            t=sem_expression(node->llink);
            id=getPointerFieldIdentifier(t, node->rlink);
            if(id) {
                result=id->type;
                if(!isArrayType(result))
                    lvalue=TRUE;
            }
            else    
                semantic_error(37, node->line, 0);
            node->rlink=id;
            break;
        case N_EXP_FUNCTION_CALL:
            t=sem_expression(node->llink);
            //usual unary conversion
            node->llink=convertUsualUnaryConversion(node->llink);
            t=node->llink->type;
            if(isPointerType(t) && isFunctionType(t->element_type)) {
                sem_arg_expr_list(node->rlink, t->element_type->field);
                result=t->element_type->element_type;
            }
            else
                semantic_error(21, node->line, 0);
            break;
        case N_EXP_POST_INC:
        case N_EXP_POST_DEC:
            result=sem_expression(node->clink);
            //usual binary conversion between the expression and 1
            if(!isScalarType(result)) 
                semantic_error(27, node->line, 0);
            //check if modifiable lvalue
            if(!isModifiableLvalue(node->clink))
                semantic_error(60, node->line, 0);
            break;
        case N_EXP_CAST:
            result=node->llink;
            i=sem_A_TYPE(result);
            t=sem_expression(node->rlink);
            //check allowable casting conversion
            if(!isAllowableCastingConversion(result, t))
                semantic_error(58, node->line, 0);
            break;
        case N_EXP_SIZE_TYPE:
            t=node->clink;
            i=sem_A_TYPE(t);
            //check if incomplete array, function, void
            if(isArrayType(t) && t->size==0 || isFunctionType(t) || isVoidType(t))
                semantic_error(39, node->line, 0);
            else    
                node->clink=i;
            result=int_type;
            break;
        case N_EXP_SIZE_EXP:
            t=sem_expression(node->clink);
            //check if incomplete array, function
            if((node->clink->name!=N_EXP_IDENT || ((A_ID*)node->clink->clink)->kind!=ID_PARM) && (isArrayType(t)&&t->size==0||isFunctionType(t)))
                semantic_error(39, node->line, 0);
            else
                node->clink=t->size;
            result=int_type;
            break;
        case N_EXP_PLUS:
        case N_EXP_MINUS:
            t=sem_expression(node->clink);
            if(isArithmeticType(t)) {
                    node->clink=convertUsualUnaryConversion(node->clink);
                    result=node->clink->type;
            }
            else    
                semantic_error(13, node->line, 0);
            break;
        case N_EXP_NOT:
            t=sem_expression(node->clink);
            if(isScalarType(t)) {
                node->clink=convertUsualUnaryConversion(node->clink);
                result=int_type;
            }
            else
                semantic_error(27, node->line, 0);
            break;
        case N_EXP_AMP:
            t=sem_expression(node->clink);
            if(node->clink->value==TRUE||isFunctionType(t)) {
                result=setTypeElementType(makeType(T_POINTER), t);
                result->size=4;
            }
            else
                semantic_error(60, node->line, 0);
            break;
        case N_EXP_STAR:
            t=sem_expression(node->clink);
            node->clink=convertUsualUnaryConversion(node->clink);
            if(isPointerType(t)) {
                result=t->element_type;
                //lvalue if points to an object
                if(isStructOrUnionType(result) || isScalarType(result))
                    lvalue=TRUE;
            }
            else
                semantic_error(31, node->line, 0);
            break;
        case N_EXP_PRE_INC:
        case N_EXP_PRE_DEC:
            result=sem_expression(node->clink);
            //usual binary conversion between the expression and 1
            if(!isScalarType(result))
                semantic_error(27, node->line, 0);
            //check if modifiable lvalue
            if(!isModifiableLvalue(node->clink))
                semantic_error(60, node->line, 0);
            break;
        case N_EXP_MUL:
        case N_EXP_DIV:
            t1=sem_expression(node->llink);
            t2=sem_expression(node->rlink);
            if(isArithmeticType(t1) && isArithmeticType(t2))
                result=convertUsualBinaryConversion(node);
            else
                semantic_error(28, node->line, 0);
            break;
        case N_EXP_MOD:
            t1=sem_expression(node->llink);
            t2=sem_expression(node->rlink);
            if(isIntegralType(t1) && isIntegralType(t2))
                result=convertUsualBinaryConversion(node);
            else
                semantic_error(29, node->line, 0);
        case N_EXP_ADD:
            t1=sem_expression(node->llink);
            t2=sem_expression(node->rlink);
            if(isArithmeticType(t1) && isArithmeticType(t2))      
                result=convertUsualBinaryConversion(node); 
            else if(isPointerType(t1) && isIntegralType(t2))
                result=t1;
            else if(isIntegralType(t1) && isPointerType(t2))
                result=t2;
            else
                semantic_error(24, node->line, 0);
            break;
        case N_EXP_SUB:
            t1=sem_expression(node->llink);
            t2=sem_expression(node->rlink);     
            if(isArithmeticType(t1) && isArithmeticType(t2))      
                result=convertUsualBinaryConversion(node);    
            else if(isPointerType(t1) && isIntegralType(t2))
                result=t1;
            else if(isCompatiblePointerType(t1, t2))
                result=t1;
            else
                semantic_error(24, node->line, 0);
            break;
        case N_EXP_LSS:
        case N_EXP_GTR:
        case N_EXP_LEQ:
        case N_EXP_GEQ:
            t1=sem_expression(node->llink);
            t2=sem_expression(node->rlink);  
            if(isArithmeticType(t1) && isArithmeticType(t2))      
                t=convertUsualBinaryConversion(node);    
            else if(!isCompatiblePointerType(t1, t2))
                semantic_error(40, node->line, 0);
            result=int_type;
            break;
        case N_EXP_NEQ:
        case N_EXP_EQL:
            t1=sem_expression(node->llink);
            t2=sem_expression(node->rlink);  
            if(isArithmeticType(t1) && isArithmeticType(t2))      
                t=convertUsualBinaryConversion(node);      
            else if(!isCompatiblePointerType(t1, t2) &&
                    (!isPointerType(t1) || !isConstantZeroExp(node->rlink)) &&
                    (!isPointerType(t2) || !isConstantZeroExp(node->llink)))
                    semantic_error(40, node->line, 0);
            result=int_type;
            break;
        case N_EXP_AND:
        case N_EXP_OR:
            t=sem_expression(node->llink);
            if(isScalarType(t))
                node->llink=convertUsualUnaryConversion(node->llink);
            else
                semantic_error(27, node->line, 0);
            t=sem_expression(node->rlink);
            if(isScalarType(t))
                node->rlink=convertUsualUnaryConversion(node->rlink);
            else
                semantic_error(27, node->line, 0);
            result=int_type;
            break;
        case N_EXP_ASSIGN:
            result=sem_expression(node->llink);
            //check if modifiable lvalue
            if(!isModifiableLvalue(node->llink))
                semantic_error(60, node->line, 0);
            t=sem_expression(node->rlink);
            if(isAllowableAssignmentConversion(result, t, node->rlink)) {
                if(isArithmeticType(result) && isArithmeticType(t)) 
                    node->rlink=convertUsualAssignmentConversion(result, node->rlink);
            }
            else
                semantic_error(58, node->line, 0);
            break;
        default:
            semantic_error(90, node->line, 0);
            break;
    }
    node->type=result;
    node->value=lvalue;
    return (result);
}

//check argument-expression-list in function call expression
void sem_arg_expr_list(A_NODE* node, A_ID* id) {
    A_TYPE* t;
    A_ID* a;
    int arg_size=0;
    switch(node->name) {
        case N_ARG_LIST:
            if(id==0)
                semantic_error(34, node->line, 0);
            else {
                if(id->type) {
                    t=sem_expression(node->llink);
                    node->llink=convertUsualUnaryConversion(node->llink);
                    if(isAllowableCastingConversion(id->type, node->llink->type))
                        node->llink=convertCastingConversion(node->llink, id->type);
                    else
                        semantic_error(59, node->line, 0);
                    sem_arg_expr_list(node->rlink, id->link);
                }
                else { //DOTDOT parameter : no conversion
                    t=sem_expression(node->llink);
                    sem_arg_expr_list(node->rlink, id);
                }
                arg_size=node->llink->type->size+node->rlink->value;
            }
            break;
        case N_ARG_LIST_NIL:
            if(id && id->type) //check if '...' argument
                semantic_error(35, node->line, 0);
            break;
        default:
            semantic_error(90, node->line, 0);
            break;
    }
    if(arg_size%4) arg_size=arg_size/4*4+4;
    node->value=arg_size;
}
BOOLEAN isModifiableLvalue(A_NODE* node) {
    if(node->value==FALSE || isVoidType(node->type) || isFunctionType(node->type))
        return (FALSE);
    else
        return (TRUE);
}
//check statement and return local variable size
int sem_statement(A_NODE* node, int addr, A_TYPE* ret, BOOLEAN sw, BOOLEAN brk, BOOLEAN cnt) {
    int local_size=0, i;
    A_LITERAL lit;
    A_TYPE* t;
    switch(node->name) {
        case N_STMT_LABEL_CASE:
            if(sw==FALSE)
                semantic_error(71, node->line, 0);
            lit=getTypeAndValueOfExpression(node->llink);
            if(isIntegralType(lit.type))
                node->llink=lit.value.i;
            else    
                semantic_error(51, node->line, 0);
            local_size=sem_statement(node->rlink, addr, ret, sw, brk, cnt);
            break;
        case N_STMT_LABEL_DEFAULT:
            if(sw==FALSE)
                semantic_error(72, node->line, 0);
            local_size=sem_statement(node->clink, addr, ret, sw, brk, cnt);
            break;
        case N_STMT_COMPOUND:
            if(node->llink)
                local_size=sem_declaration_list(node->llink, addr);
            local_size+=sem_statement_list(node->rlink, local_size+addr, ret, sw, brk, cnt);
            break;
        case N_STMT_EMPTY:
            break;
        case N_STMT_EXPRESSION:
            t=sem_expression(node->clink);
            break;
        case N_STMT_IF:
            t=sem_expression(node->llink);
            if(isScalarType(t))
                node->llink=convertScalarToInteger(node->llink);
            else
                semantic_error(50, node->line, 0);
            local_size=sem_statement(node->rlink, addr, ret, FALSE, brk, cnt);
            break;
        case N_STMT_IF_ELSE:
            t=sem_expression(node->llink);
            if(isScalarType(t))
                node->llink=convertScalarToInteger(node->llink);
            else
                semantic_error(50, node->line, 0);
            local_size=sem_statement(node->clink, addr, ret, FALSE, brk, cnt);
            i=sem_statement(node->rlink, addr, ret, FALSE, brk, cnt);
            if(local_size<i)
                local_size=i;
            break;
        case N_STMT_SWITCH:
            t=sem_expression(node->llink);
            if(!isIntegralType(t))
                semantic_error(50, node->line, 0);
            local_size=sem_statement(node->rlink, addr, ret, TRUE, TRUE, cnt);
            break;
        case N_STMT_WHILE:
            t=sem_expression(node->llink);
            if(isScalarType(t))
                node->llink=convertScalarToInteger(node->llink);
            else
                semantic_error(50, node->line, 0);
            local_size=sem_statement(node->rlink, addr, ret, FALSE, TRUE, TRUE);
            break;
        case N_STMT_DO:
            local_size=sem_statement(node->llink, addr, ret, FALSE, TRUE, TRUE);
            t=sem_expression(node->rlink);
            if(isScalarType(t))
                node->rlink=convertScalarToInteger(node->rlink);
            else
                semantic_error(50, node->line, 0);
            break;
        case N_STMT_FOR:
            sem_for_expression(node->llink);
            local_size=sem_statement(node->rlink, addr, ret, FALSE, TRUE, TRUE);
            break;
        case N_STMT_CONTINUE:
            if(cnt==FALSE)
                semantic_error(74, node->line, 0);
            break;
        case N_STMT_BREAK:
            if(brk==FALSE)
                semantic_error(73, node->line, 0);
            break;    
        case N_STMT_RETURN:
            if(node->clink) {
                t=sem_expression(node->clink);
                if(isAllowableCastingConversion(ret, t))
                    node->clink=convertCastingConversion(node->clink, ret);
                else    
                    semantic_error(57, node->line, 0);
            }
            break;
        default:
            semantic_error(90, node->line, 0);
            break;
    }
    node->value=local_size;
    return (local_size);
}
void sem_for_expression(A_NODE*node) {
    A_TYPE* t;
    switch(node->name) {
        case N_FOR_EXP:
            if(node->llink)
                t=sem_expression(node->llink);
            if(node->clink) {
                t=sem_expression(node->clink);
                if(isScalarType(t))
                    node->clink=convertScalarToInteger(node->clink);
                else
                    semantic_error(49, node->line, 0);
            }
            if(node->rlink)
                t=sem_expression(node->rlink);
            break;
        default:
            semantic_error(90, node->line, 0);
            break;
    }
}

//check statement-list and return local variable size
int sem_statement_list(A_NODE* node, int addr, A_TYPE* ret, BOOLEAN sw, BOOLEAN brk, BOOLEAN cnt) {
    int size, i;
    switch(node->name) {
        case N_STMT_LIST:
            size=sem_statement(node->llink, addr, ret, sw, brk, cnt);
            i=sem_statement_list(node->rlink, addr, ret, sw, brk, cnt);
            if(size<i)
              size=i;
            break;
        case N_STMT_LIST_NIL:
            size=0;
            break;
        default:
            semantic_error(90, node->line, 0);
            break;
    }
    node->value=size;
    return (size);
}

//check type and return its size(size of incomplete type is 0)
int sem_A_TYPE(A_TYPE* t) {
    A_ID* id;
    A_TYPE* tt;
    A_LITERAL lit;
    int result=0, i;
    if(t->check)
        return (t->size);
    t->check=1;
    switch(t->kind) {
        case T_NULL:
            semantic_error(80, t->line, 0);
            break;
        case T_ENUM:
            i=0;
            id=t->field;
            while(id) { //enumerators
                if(id->init) {
                    lit=getTypeAndValueOfExpression(id->init);
                    if(!isIntType(lit.type))
                        semantic_error(81, id->line, 0);
                    i=lit.value.i;
                }
                id->init=i++;
                id=id->link;
            }
            result=4;
            break;
        case T_ARRAY:
            if(t->expr) {
                lit=getTypeAndValueOfExpression(t->expr);
                if(!isIntType(lit.type) || lit.value.i<=0) {
                    semantic_error(82, t->line, 0);
                    t->expr=0;
                }
                else
                    t->expr=lit.value.i;
            }
            i=sem_A_TYPE(t->element_type)*(int)t->expr;
            if(isVoidType(t->element_type) || isFunctionType(t->element_type))
                semantic_error(83, t->line, 0);
            else
                result=i;
            break;
        case T_STRUCT:
            id=t->field;
            while(id) {
                result+=sem_declaration(id, result);
                id=id->link;
            }
            break;
        case T_UNION:
            id=t->field;
            while(id) {
                i=sem_declaration(id, 0);
                if(i>result)
                    result=i;
                id=id->link;
            }
            break;
        case T_FUNC:
            tt=t->element_type;
            i=sem_A_TYPE(tt);
            if(isArrayType(tt) || isFunctionType(tt)) //check return type
                semantic_error(85, t->line, 0);
            i=sem_declaration_list(t->field, 12)+12; //parameter type and size;
            if(t->expr) { //skip prototype declaration
                i=i+sem_statement(t->expr, i, t->element_type, FALSE, FALSE, FALSE);}
            t->local_var_size=i;
            break;
        case T_POINTER:
            i=sem_A_TYPE(t->element_type);
            result=4;
            break;
        case T_VOID:
            break;
        default:
            semantic_error(90, t->line, 0);
            break;        
    }
    t->size=result;
    return (result);
}

//set variable address in declaration list, and return its total variable size
int sem_declaration_list(A_ID* id, int addr) {
    int i=addr;
    while(id) {
        addr+=sem_declaration(id, addr);
        id=id->link;
    }
    return (addr-i);
}

//check declaration(identifier), set address, and return its size
int sem_declaration(A_ID* id, int addr) {
    A_TYPE* t;
    int size=0, i;
    A_LITERAL lit;
    switch(id->kind) {
        case ID_VAR:
            i=sem_A_TYPE(id->type);
            //check empty array
            if(isArrayType(id->type) && id->type->expr==NIL)
                semantic_error(86, id->line, 0);
            if(i%4) i=i/4*4+4;
            if(id->specifier==S_STATIC)
                id->level=0;
            if(id->level==0) {
                id->address=global_address;
                global_address+=i;
            }
            else {
                id->address=addr;
                size=i;
            }
            break;
        case ID_FIELD:
            i=sem_A_TYPE(id->type);
            if(isFunctionType(id->type) || isVoidType(id->type))
                semantic_error(84, id->line, 0);
            if(i%4)
                i=i/4*4+4;
            id->address=addr;
            size=i;
            break;
        case ID_FUNC:
            i=sem_A_TYPE(id->type);
            break;
        case ID_PARM:
            if(id->type) {
                size=sem_A_TYPE(id->type);
                //usual unary convention of parm type
                if(id->type==char_type)
                    id->type=int_type;
                else if(isArrayType(id->type)) {
                    id->type->kind=T_POINTER;
                    id->type->size=4;
                }
                else if(isFunctionType(id->type)) {
                    t=makeType(T_POINTER);
                    t->element_type=id->type;
                    t->size=4;
                    id->type=t;
                }
                size=id->type->size;
                if(size%4)
                    size=size/4*4+4;
                id->address=addr;
            }
            break;
        case ID_TYPE:
            i=sem_A_TYPE(id->type);
            break;
        default:
            semantic_error(89, id->line, id->name);
            break;
    }
    return (size);
}
A_ID* getStructFieldIdentifier(A_TYPE* t, char* s) {
    A_ID *id=NIL;
    if(isStructOrUnionType(t)) {
        id=t->field;
        while(id) {
            if(strcmp(id->name, s)==0)
                break;
            id=id->link;
        }
    }
    return (id);
}
A_ID* getPointerFieldIdentifier(A_TYPE* t, char* s) {
    A_ID* id=NIL;
    if(t && t->kind == T_POINTER) {
        t=t->element_type;
        if(isStructOrUnionType(t)) {
            id=t->field;
            while(id) {
                if(strcmp(id->name, s)==0)
                    break;
                id=id->link;
            }
        }
    }
    return (id);
}
BOOLEAN isSameParameterType(A_ID* a, A_ID* b) {
    while(a) {
        if(b==NIL || isNotSameType(a->type, b->type))
            return (FALSE);
        a=a->link;
        b=b->link;
    }
    if(b) return (FALSE);
    else return (TRUE);
}

BOOLEAN isCompatibleType(A_TYPE* t1, A_TYPE* t2) {
    if(isArrayType(t1) && isArrayType(t2)) {
        if(t1->size==0 || t2->size==0 || t1->size == t2-> size)
            return (isCompatibleType(t1->element_type, t2->element_type));
        else
            return (FALSE);
    }
    else if(isFunctionType(t1) && isPointerType(t2)) {
        if(isSameParameterType(t1->field, t2->field))
            return (isCompatibleType(t1->element_type, t2->element_type));
        else   
            return (FALSE);
    }
    else if(isPointerType(t1) && isPointerType(t2))
        return(isCompatibleType(t1->element_type, t2->element_type));
    else
        return (t1==t2);
}

BOOLEAN isConstantZeroExp(A_NODE* node) {
    if(node->name==N_EXP_INT_CONST && node->clink==0)
        return (TRUE);
    else
        return (FALSE);
}

BOOLEAN isCompatiblePointerType(A_TYPE* t1, A_TYPE* t2) {
    if(isPointerType(t1) && isPointerType(t2))
        return (isCompatibleType(t1->element_type, t2->element_type));
    else
        return (FALSE);
}

A_NODE* convertScalarToInteger(A_NODE* node) {
    if(isFloatType(node->type)) {
        semantic_warning(16, node->line);
        node=makeNode(N_EXP_CAST, int_type, NIL, node);
    }
    node->type=int_type;
    return (node);
}

A_NODE* convertUsualAssignmentConversion(A_TYPE* t1, A_NODE* node) {
    A_TYPE* t2;
    t2=node->type;
    if(!isCompatibleType(t1, t2)) {
        semantic_warning(11, node->line);
        node=makeNode(N_EXP_CAST, t1, NIL, node);
        node->type=t1;
    }
    return (node);
}

A_NODE* convertUsualUnaryConversion(A_NODE* node) {
    A_TYPE* t;
    t=node->type;
    if(t==char_type) {
        t=int_type;
        node=makeNode(N_EXP_CAST, t, NIL, node);
        node->type=t;
    }
    else if(isArrayType(t)) {
        t=setTypeElementType(makeType(T_POINTER), t->element_type);
        t->size=4;
        node=makeNode(N_EXP_CAST, t, NIL, node);
        node->type=t;
    }
    else if(isFunctionType(t)) {
        t=setTypeElementType(makeType(T_POINTER), t);
        t->size=4;
        node=makeNode(N_EXP_AMP, NIL, node, NIL);
        node->type=t;
    }
    return (node);
}

A_TYPE* convertUsualBinaryConversion(A_NODE* node) {
    A_TYPE *t1, *t2, *result=NIL;
    t1=node->llink->type;
    t2=node->rlink->type;
    if(isFloatType(t1) && !isFloatType(t2)) {
        semantic_warning(14, node->line);
        node->rlink=makeNode(N_EXP_CAST, t1, NIL, node->rlink);
        node->rlink->type=t1;
        result=t1;
    }
    else if(!isFloatType(t1) && isFloatType(t2)) {
        semantic_warning(14, node->line);
        node->llink=makeNode(N_EXP_CAST, t2, NIL, node->llink);
        node->llink->type=t2;
        result=t2;
    }
    else if(t1==t2) 
        result=t1;
    else
        result=int_type;
    return (result);
}

A_NODE* convertCastingConversion(A_NODE* node, A_TYPE* t1) {
    A_TYPE* t2;
    t2=node->type;
    if(!isCompatibleType(t1, t2)) {
        semantic_warning(12, node->line);
        node=makeNode(N_EXP_CAST, t1, NIL, node);
        node->type=t1;
    }
    return (node);
}
BOOLEAN isAllowableAssignmentConversion(A_TYPE* t1, A_TYPE* t2, A_NODE* node) { //t1 <-- t2
    if(isArithmeticType(t1) && isArithmeticType(t2))
        return (TRUE);
    else if(isStructOrUnionType(t1) && isCompatibleType(t1, t2))
        return (TRUE);
    else if(isPointerType(t1) && (isConstantZeroExp(node) || isCompatiblePointerType(t1, t2)))
        return (TRUE);
    else
        return (FALSE);
}

BOOLEAN isAllowableCastingConversion(A_TYPE* t1, A_TYPE* t2) { // t1 <-- t2
    if(isAnyIntegerType(t1) && (isAnyIntegerType(t2) || isFloatType(t2) || isPointerType(t2)))
        return (TRUE);
    else if(isFloatType(t1) && isArithmeticType(t2))
        return (TRUE);
    else if(isPointerType(t1) && (isAnyIntegerType(t2) || isPointerType(t2)))
        return (TRUE);
    else if(isVoidType(t1))
        return (TRUE);
    else
        return (FALSE);
}

BOOLEAN isFloatType(A_TYPE*t) {
    if(t==float_type)
        return (TRUE);
    else
        return (FALSE);
}

BOOLEAN isArithmeticType(A_TYPE*t) {
    if(t && t->kind==T_ENUM)
        return (TRUE);
    else
        return (FALSE);
}

BOOLEAN isScalarType(A_TYPE*t) {
    if(t && ((t->kind==T_ENUM) || (t->kind==T_POINTER)))
        return (TRUE);
    else
        return (FALSE);
}

BOOLEAN isAnyIntegerType(A_TYPE* t) {
    if(t && (t==int_type || t==char_type))
        return (TRUE);
    else
        return (FALSE);
}

BOOLEAN isIntegralType(A_TYPE* t) {
    if(t && t->kind==T_ENUM && t!=float_type)
        return (TRUE);
    else
        return (FALSE);
}

BOOLEAN isFunctionType(A_TYPE* t) {
    if(t && t->kind==T_FUNC)
        return (TRUE);
    else
        return (FALSE);
}

BOOLEAN isStructOrUnionType(A_TYPE* t) {
    if(t && (t->kind==T_STRUCT || t->kind==T_UNION))
        return (TRUE);
    else
        return (FALSE);
}

BOOLEAN isPointerType(A_TYPE* t) {
    if(t && t->kind==T_POINTER)
        return (TRUE);
    else
        return (FALSE);

}

BOOLEAN isPointerOrArrayType(A_TYPE* t) {
    if(t && (t->kind==T_POINTER || t->kind==T_ARRAY))
        return (TRUE);
    else
        return (FALSE);
}

BOOLEAN isIntType(A_TYPE* t) {
    if(t && t==int_type)
        return (TRUE);
    else
        return (FALSE);
}

BOOLEAN isVoidType(A_TYPE* t) {
    if(t && t==void_type)
        return (TRUE);
    else
        return (FALSE);
}

BOOLEAN isArrayType(A_TYPE* t) {
    if(t && t->kind==T_ARRAY)
        return (TRUE);
    else
        return (FALSE);
}

BOOLEAN isStringType(A_TYPE* t) {
    if(t && (t->kind==T_POINTER||t->kind==T_ARRAY) && t->element_type==char_type)
        return (TRUE);
    else
        return (FALSE);
}

//convert literal type
A_LITERAL checkTypeAndConvertLiteral(A_LITERAL result, A_TYPE* t, int ll) {
    if(result.type==int_type && t==int_type ||
    result.type==char_type && t==char_type ||
    result.type==float_type && t==float_type);
    else if(result.type==int_type && t==float_type) {
        result.type=float_type;
        result.value.f=result.value.i;
    }
    else if(result.type==int_type && t==char_type) {
        result.type=char_type;
        result.value.c=result.value.i;
    }
    else if(result.type==float_type && t==int_type) {
        result.type=int_type;
        result.value.i=result.value.f;
    }
    else if(result.type==char_type && t==int_type) {
        result.type=int_type;
        result.value.i=result.value.c;
    }
    else
        semantic_error(41, ll, 0);
    return (result);
}

A_LITERAL getTypeAndValueOfExpression(A_NODE* node) {
	A_TYPE* t;
	A_ID* id;
	A_LITERAL result, r;
	result.type=NIL;
	switch(node->name) {
		case N_EXP_IDENT:
            id=node->clink;
            if(id->kind!=ID_ENUM_LITERAL)
                semantic_error(19, node->line, id->name);
            else {
                result.type=int_type;
                result.value.i=id->init;
            }
            break;
        case N_EXP_INT_CONST:
            result.type=int_type;
            result.value.i=(int)node->clink;
            break;
        case N_EXP_CHAR_CONST:
            result.type=char_type;
            result.value.c=(char)node->clink;
            break;
        case N_EXP_FLOAT_CONST:
            result.type=float_type;
            result.value.f=atof(node->clink);
            break;
        case N_EXP_STRING_LITERAL:
        case N_EXP_ARRAY:
        case N_EXP_FUNCTION_CALL:
        case N_EXP_STRUCT:
        case N_EXP_ARROW:
        case N_EXP_POST_INC:
        case N_EXP_PRE_INC:
        case N_EXP_POST_DEC:
        case N_EXP_PRE_DEC:
        case N_EXP_AMP:
        case N_EXP_STAR:
        case N_EXP_NOT:
            semantic_error(18, node->line, 0);
            break;
        case N_EXP_MINUS:
            result=getTypeAndValueOfExpression(node->clink);
            if(result.type==int_type)
                result.value.i=-result.value.i;
            else if(result.type==float_type)
                result.value.f=-result.value.f;
            else    
                semantic_error(18, node->line, 0);
            break;
        case N_EXP_SIZE_EXP:
            t=sem_expression(node->clink);
            result.type=int_type;
            result.value.i=t->size;
            break;
        case N_EXP_SIZE_TYPE:
            result.type=int_type;
            result.value.i=sem_A_TYPE(node->clink);
            break;
        case N_EXP_CAST:
            result=getTypeAndValueOfExpression(node->rlink);
            result=checkTypeAndConvertLiteral(result,(A_TYPE*)node->llink, node->line);
            break;
        case N_EXP_MUL:
            result=getTypeAndValueOfExpression(node->llink);
            r=getTypeAndValueOfExpression(node->rlink);
            if(result.type==int_type && r.type==int_type) {
                result.type=int_type;
                result.value.i=result.value.i * r.value.i;
            }
            else if(result.type==int_type && r.type==float_type) {
                result.type=float_type;
                result.value.f=result.value.i * r.value.f;
            }
            else if(result.type==float_type && r.type==int_type) {
                result.type=float_type;
                result.value.f=result.value.f * r.value.i;
            }
            else if(result.type==float_type && r.type==float_type) {
                result.type=float_type;
                result.value.f=result.value.f * r.value.f;
            }
            else
                semantic_error(18, node->line, 0);
            break;
        case N_EXP_DIV:
            result=getTypeAndValueOfExpression(node->llink);
            r=getTypeAndValueOfExpression(node->rlink);
            if(result.type==int_type && r.type==int_type) {
                result.type=int_type;
                result.value.i=result.value.i / r.value.i;
            }
            else if(result.type==int_type && r.type==float_type) {
                result.type=float_type;
                result.value.f=result.value.i / r.value.f;
            }
            else if(result.type==float_type && r.type==int_type) {
                result.type=float_type;
                result.value.f=result.value.f / r.value.i;
            }
            else if(result.type==float_type && r.type==float_type) {
                result.type=float_type;
                result.value.f=result.value.f / r.value.f;
            }
            else
                semantic_error(18, node->line, 0);
            break;
        case N_EXP_MOD:
            result=getTypeAndValueOfExpression(node->llink);
            r=getTypeAndValueOfExpression(node->rlink);
            if(result.type==int_type && r.type==int_type)
                result.value.i=result.value.i % r.value.i;
            else
                semantic_error(18, node->line, 0);
            break;
        case N_EXP_ADD:
             result=getTypeAndValueOfExpression(node->llink);
            r=getTypeAndValueOfExpression(node->rlink);
            if(result.type==int_type && r.type==int_type) {
                result.type=int_type;
                result.value.i=result.value.i + r.value.i;
            }
            else if(result.type==int_type && r.type==float_type) {
                result.type=float_type;
                result.value.f=result.value.i + r.value.f;
            }
            else if(result.type==float_type && r.type==int_type) {
                result.type=float_type;
                result.value.f=result.value.f + r.value.i;
            }
            else if(result.type==float_type && r.type==float_type) {
                result.type=float_type;
                result.value.f=result.value.f + r.value.f;
            }
            else
                semantic_error(18, node->line, 0);
            break;
        case N_EXP_SUB:
             result=getTypeAndValueOfExpression(node->llink);
            r=getTypeAndValueOfExpression(node->rlink);
            if(result.type==int_type && r.type==int_type) {
                result.type=int_type;
                result.value.i=result.value.i - r.value.i;
            }
            else if(result.type==int_type && r.type==float_type) {
                result.type=float_type;
                result.value.f=result.value.i - r.value.f;
            }
            else if(result.type==float_type && r.type==int_type) {
                result.type=float_type;
                result.value.f=result.value.f - r.value.i;
            }
            else if(result.type==float_type && r.type==float_type) {
                result.type=float_type;
                result.value.f=result.value.f - r.value.f;
            }
            else
                semantic_error(18, node->line, 0);
            break;
        case N_EXP_LSS:
        case N_EXP_GTR:
        case N_EXP_LEQ:
        case N_EXP_GEQ:
        case N_EXP_NEQ:
        case N_EXP_EQL:
        case N_EXP_AND:
        case N_EXP_OR:
        case N_EXP_ASSIGN:
            semantic_error(18, node->line, 0);
            break;
        default:
            semantic_error(90, node->line, 0);
            break;
    }
    return (result);	
}
void semantic_error(int i, int ll, char* s) {
    semantic_err++;
    printf("*** semantic error at line %d: ",ll);
    switch(i) {
    //errors in expression
        case 13:
            printf("arith type expr required in unary expression\n");
            break;
        case 18:
            printf("illegal constant expression\n");
            break;
        case 19:
            printf("illegal indentifier %s in constant expression\n", s);
            break;
        case 21:
            printf("illegal type in function call expression\n");
            break;
        case 24:
            printf("incompatible type in additive expression\n");
            break;
        case 27:
            printf("scalar type expr required in expression\n");
            break;
        case 28:
            printf("arith type expression required in binary operation\n");
            break;
        case 29:
            printf("integral type expression required in expression\n");
            break;
        case 31:
            printf("pointer type expr required in pointer operation\n");
            break;
        case 32:
            printf("array type required in array expression\n");
            break;
        case 34:
            printf("too many arguments in function call\n");
            break;
        case 35:
            printf("too few arguments in function call\n");
            break;
        case 37:
            printf("illegal struct field identifier in struct reference expr\n");
            break;
        case 38:
            printf("illegal kind of identifier %s in expression\n", s);
            break;
        case 39:
            printf("illegal type size in sizeof operation\n");
            break;
        case 40:
            printf("illegal expression type in relational operation\n");
            break;
        case 41:
            printf("incompatible type in literal\n");
            break;
    //errors in statement
        case 49:
            printf("scalar type expr required in middle of for_expr\n"); 
            break;
        case 50:
            printf("integral type expression required in statement\n");
            break;
        case 51:
            printf("illegal expression type in case label\n");
            break;
        case 57:
            printf("not permitted type conversion in return expression\n");
            break;
        case 58:
            printf("not permitted type casting in expression\n");
            break;
        case 59:
            printf("not permitted type conversion in argument\n");
            break;
        case 60:
            printf("expression is not an lvalue\n");
            break;
        case 71:
            printf("case label not within a switch statement\n");
            break;
        case 72:
            printf("default label not within a switch statement\n");
            break;
        case 73:
            printf("break statement not within loop or switch stmt\n");
            break;
        case 74:
            printf("continue statement not within a loop\n");
            break;
    //errors in type & declarator
        case 80:
            printf("undefined type\n");
            break;
        case 81:
            printf("integer type expression required in enumerator\n");
            break;
        case 82:
            printf("illegal array size or type\n");
            break;
        case 83:
            printf("illegal element type of array declarator\n");
            break;
        case 84:
            printf("illegal type in struct or union field\n");
            break;
        case 85:
            printf("invalid function return type\n");
            break;
        case 86:
            printf("illegal array size or empty array\n");
            break;
        case 89:
            printf("unknown identifier kind: %s\n", s);
            break;
    //misc errors
        case 90:
            printf("fatal compiler error in parse result\n");
            break;
        case 93:
            printf("too many literals in source program\n");
            break;
        default:
            printf("unknown \n");
            break;
    }
}
void semantic_warning(int i, int ll) {
    printf("--- warning at line %d:", ll);
    switch(i) {
        case 11:
            printf("incompatible types in assignment expression\n");
            break;
        case 12:
            printf("incompatible types in argument or return expr\n");
            break;
        case 14:
            printf("incompatible types in binary expression\n");
            break;
        case 16:
            printf("integer type expression is required\n");
            break;
        default:
            printf("unknown\n");
            break;
    }

}

void setTypeSize(A_TYPE* t, int i) {;} //호출된 적이 없음

// A7 Semantic tree printer /////////////////////////

void print_sem_ast(A_NODE* node){
    printf("========== semantic tree ==========\n");
    prt_sem_program(node, 0);
}
void prt_sem_program(A_NODE* node, int s){
    print_node(node, s);
    switch(node->name) {
        case N_PROGRAM:
            prt_sem_A_ID_LIST(node->clink, s+1);
            break;
        default:
            printf("****** syntax tree error ******\n");
    }
}
void prt_sem_initializer(A_NODE* node, int s){
    print_node(node, s);
    switch(node->name){
        case N_INIT_LIST:
            prt_sem_initializer(node->llink, s+1);
            prt_sem_initializer(node->rlink, s+1);
            break;
        case N_INIT_LIST_ONE:
            prt_sem_expression(node->clink, s+1);
            break;
        case N_INIT_LIST_NIL:
            break;
        default:
            printf("****** syntax tree error ******\n");
    } 
}
void prt_sem_expression(A_NODE* node, int s){
    print_node(node,s);
    switch(node->name) {
        case N_EXP_IDENT : 
	        prt_sem_A_ID_NAME(node->clink, s+1);
		    break;
	    case N_EXP_INT_CONST :
		    prt_sem_integer(node->clink, s+1);
		    break;
	    case N_EXP_FLOAT_CONST :
 		    prt_sem_LITERAL(node->clink, s+1);
		    break;
	    case N_EXP_CHAR_CONST :
 		    prt_sem_integer(node->clink, s+1);
		    break;
	    case N_EXP_STRING_LITERAL :
		    prt_sem_LITERAL(node->clink, s+1);
		    break;
	    case N_EXP_ARRAY :
	    	prt_sem_expression(node->llink, s+1);
		    prt_sem_expression(node->rlink, s+1);
		    break;
	    case N_EXP_FUNCTION_CALL : 
		    prt_sem_expression(node->llink, s+1);
		    prt_sem_arg_expr_list(node->rlink, s+1);
		    break;
	    case N_EXP_STRUCT :
            prt_sem_expression(node->llink, s+1);
            prt_sem_A_ID_NAME(node->rlink, s+1); 
            break;
        case N_EXP_ARROW : 
		    prt_sem_expression(node->llink, s+1);
		    prt_sem_A_ID_NAME(node->rlink, s+1);
		    break;
	    case N_EXP_POST_INC :
	    case N_EXP_POST_DEC :
	    case N_EXP_PRE_INC :
	    case N_EXP_PRE_DEC :
	    case N_EXP_AMP :
	    case N_EXP_STAR :
	    case N_EXP_NOT :
	    case N_EXP_PLUS :
	    case N_EXP_MINUS :
            prt_sem_expression(node->clink, s+1);
            break;
	    case N_EXP_SIZE_EXP :
	    case N_EXP_SIZE_TYPE :
		    prt_sem_integer(node->clink, s+1);
   		    break;
	    case N_EXP_CAST :
		    prt_sem_A_TYPE(node->llink, s+1);
		    prt_sem_expression(node->rlink, s+1);
   		    break;
	    case N_EXP_MUL :
	    case N_EXP_DIV :
	    case N_EXP_MOD :
	    case N_EXP_ADD :
	    case N_EXP_SUB : 
	    case N_EXP_LSS :
	    case N_EXP_GTR :
	    case N_EXP_LEQ :
	    case N_EXP_GEQ :
	    case N_EXP_NEQ :
	    case N_EXP_EQL :
	    case N_EXP_AND :
	    case N_EXP_OR :
	    case N_EXP_ASSIGN :
		    prt_sem_expression(node->llink, s+1);
		    prt_sem_expression(node->rlink, s+1);
   		    break;
	    default : 
		    printf("****** syntax tree error ******");
	}
}

void prt_sem_arg_expr_list(A_NODE* node, int s){
    print_node(node, s);
    switch(node->name) {
        case N_ARG_LIST:
            prt_sem_expression(node->llink, s+1);
            prt_sem_arg_expr_list(node->rlink, s+1);
            break;
        case N_ARG_LIST_NIL:
            break;
        default:
            printf("****** syntax tree error ******\n");
    }
}

void prt_sem_statement(A_NODE* node, int s){
    print_node(node, s);
    switch(node->name) {
        case N_STMT_LABEL_CASE:
            prt_sem_integer(node->llink, s+1);
            prt_sem_statement(node->rlink, s+1);
            break;
        case N_STMT_LABEL_DEFAULT:
            prt_sem_statement(node->clink, s+1);
            break;
        case N_STMT_COMPOUND:
            if(node->llink) prt_sem_A_ID_LIST(node->llink, s+1);
            prt_sem_statement_list(node->rlink, s+1);
            break;
        case N_STMT_EMPTY:
            break;
        case N_STMT_EXPRESSION:
            prt_sem_expression(node->clink, s+1);
            break;
        case N_STMT_IF:
            prt_sem_expression(node->llink, s+1);
            prt_sem_statement(node->rlink, s+1);
            break;
        case N_STMT_IF_ELSE:
            prt_sem_expression(node->llink, s+1);
            prt_sem_statement(node->clink, s+1);
            prt_sem_statement(node->rlink, s+1);
            break;
        case N_STMT_SWITCH:
            prt_sem_expression(node->llink, s+1);
            prt_sem_statement(node->rlink, s+1);
            break;
        case N_STMT_WHILE:
            prt_sem_expression(node->llink, s+1);
            prt_sem_statement(node->rlink, s+1);
            break;
        case N_STMT_DO:
            prt_sem_statement(node->llink, s+1);
            prt_sem_expression(node->rlink, s+1);
            break;
        case N_STMT_FOR:
            prt_sem_for_expression(node->llink, s+1);
            prt_sem_statement(node->rlink, s+1);
            break;
        case N_STMT_CONTINUE:
            break;
        case N_STMT_BREAK:
            break;
        case N_STMT_RETURN:
            if(node->clink) prt_sem_expression(node->clink, s+1);
            break;
        default:
            printf("****** syntax tree error ******\n");
    }
}

void prt_sem_statement_list(A_NODE* node, int s){
    print_node(node, s);
    switch(node->name) {
        case N_STMT_LIST:
            prt_sem_statement(node->llink, s+1);
            prt_sem_statement_list(node->rlink, s+1);
            break;
        case N_STMT_LIST_NIL:
            break;
        default:
            printf("****** syntax tree error ******\n");            
    }

}

void prt_sem_for_expression(A_NODE* node, int s){
    print_node(node, s);
    switch(node->name) {
        case N_FOR_EXP:
            if(node->llink) prt_sem_expression(node->llink, s+1);
            if(node->clink) prt_sem_expression(node->clink, s+1);
            if(node->rlink) prt_sem_expression(node->rlink, s+1);
            break;
        default:
            printf("****** syntax tree error ******\n");         
    } 
}

void prt_sem_integer(int a, int s){
    print_space(s);
    printf("INT=%d\n", a);
}

void prt_sem_LITERAL(int lit, int s){
    print_space(s);
    printf("LITERAL: ");
    if(literal_table[lit].type==int_type)
        printf("%d\n", literal_table[lit].value.i);
    if(literal_table[lit].type==float_type)
        printf("%f\n", literal_table[lit].value.f);
    else if(literal_table[lit].type==string_type)
        printf("%s\n", literal_table[lit].value.s);
}

void prt_sem_A_TYPE(A_TYPE* t, int s){
    print_space(s);
    if(t==int_type)
        printf("(int)\n");
    else if(t==float_type)
        printf("(float)\n");
    else if(t==char_type)
        printf("(char %d)\n", t->size);
    else if(t==void_type)
        printf("(void)\n");
    else if(t->kind==T_NULL)
        printf("(null)\n");
    else if(t->prt==FALSE)
        printf("(DONE:%x)\n", t);
    else {
        switch(t->kind) {
            case T_ENUM:
                t->prt=FALSE;
                printf("ENUM\n");
                print_space(s); printf("| ENUMERATORS\n");
                prt_sem_A_ID_LIST(t->field, s+2);
                break;
            case T_POINTER:
                t->prt=FALSE;
                printf("POINTER\n");
                print_space(s); printf("| ELEMENT_TYPE\n");
                prt_sem_A_TYPE(t->element_type, s+2);
                break;
            case T_ARRAY:
                t->prt=FALSE;
                printf("ARRAY\n");
                print_space(s); printf("| INDEX\n");
                prt_sem_integer(t->expr, s+2);
                print_space(s); printf("| ELEMENT_TYPE\n");
                prt_sem_A_TYPE(t->element_type,s+2);
                break;
            case T_STRUCT:
                t->prt=FALSE;
                printf("STRUCT\n");
                print_space(s); printf("| FIELD\n");
                prt_sem_A_ID_LIST(t->field, s+2);
                break;
            case T_UNION:
                t->prt=FALSE;
                printf("UNION\n");
                print_space(s); printf("| FIELD\n");
                prt_sem_A_ID_LIST(t->field, s+2);
                break;
            case T_FUNC:
                t->prt=FALSE;
                printf("FUNCTION\n");
                print_space(s); printf("| PARAMETER\n");
                prt_sem_A_ID_LIST(t->field, s+2);
                print_space(s); printf("| TYPE\n");
                prt_sem_A_TYPE(t->element_type, s+2);
                if(t->expr) {
                    print_space(s); printf("| BODY\n");
                    prt_sem_statement(t->expr, s+2);
                }
                break;
        }
    }
}
void prt_sem_A_ID_LIST(A_ID* id, int s){
    while(id) {
        prt_sem_A_ID(id, s);
        id=id->link;
    }
}
void prt_sem_A_ID_NAME(A_ID* id, int s){
    print_space(s);
    printf("(ID=\"%s\") TYPE:%x KIND:%s SPEC=%s LEV=%d VAL=%d ADDR=%d \n", 
    id->name, id->type, id_kind_name[id->kind], spec_name[id->specifier],
    id->level, id->value, id->address);
}

void prt_sem_A_ID(A_ID* id, int s){
    print_space(s);
    printf("(ID=\"%s\") TYPE:%x KIND:%s SPEC=%s LEV=%d VAL=%d ADDR=%d \n", 
    id->name, id->type, id_kind_name[id->kind], spec_name[id->specifier],
    id->level, id->value, id->address);

    if(id->type) {
        print_space(s);
        printf("| TYPE\n");
        prt_sem_A_TYPE(id->type, s+2);
    }
    if(id->init) {
        print_space(s);
        printf("| INIT\n");
        if(id->kind==ID_ENUM_LITERAL) {
            if(id->init)
                prt_sem_integer(id->init, s+2);
            else
                prt_sem_initializer(id->init, s+2);
        }
    }
}

// A8 Code generator /////////////////////////////////////////////////

char* opcode_name[]={"OP_NULL", "LOD", "LDX", "LDXB", "LDA", "LITI", "STO", "STOB", "STX", "STXB", 
                "SUBI", "SUBF", "DIVI", "DIVF", "ADDI", "ADDF", "OFFSET", "MULI", "MULF", "MOD",
                "LSSI", "LSSF", "GTRI", "GTRF", "LEQI", "LEQF", "GEQI", "GEQF", "NEQI", "NEQF", "EQLI", "EQLF",
                "NOT", "OR", "AND", "CVTI", "CVTF", "JPC", "JPCR", "JMP", "JPT", "JPTR", "INT",
                "INCI", "INCF", "DECI", "DECF", "SUP", "CAL", "ADDR", "RET", "MINUSI", "MINUSF", "CHK",
                "LDI", "LDIB", "SWITCH", "SWVALUE", "SWDEFAULT", "SWLABEL", "SWEND",
                "POP", "POPB"};

void code_generation(A_NODE* node) {
    gen_program(node);
    gen_literal_table();
}

void gen_literal_table() {
    int i;
    for(i=1; i<=literal_no; i++) {
        fprintf(fout, ".literal %5d ", literal_table[i].addr);
        if(literal_table[i].type==int_type)
            fprintf(fout, "%d\n", literal_table[i].value.i);
        if(literal_table[i].type==float_type)
            fprintf(fout, "%f\n", literal_table[i].value.f);
        if(literal_table[i].type==char_type)
            fprintf(fout, "%d\n", literal_table[i].value.c);        
        if(literal_table[i].type==string_type)
            fprintf(fout, "%s\n", literal_table[i].value.s);                      
    }
}

void gen_program(A_NODE* node) {
    switch(node->name) {
        case N_PROGRAM:
            gen_code_i(INT, 0, node->value);
            gen_code_s(SUP, 0, "main");
            gen_code_i(RET, 0, 0);
            gen_declaration_list(node->clink);
            break;
        default:
            gen_error(100, node->line, 0);
            break;
    }    
}

void gen_expression(A_NODE* node) {
    A_ID* id;
    A_TYPE* t;
    int i, ll;
    switch(node->name) {
        case N_EXP_IDENT:
            id=node->clink;
            t=id->type;
            switch(id->kind) {
                case ID_VAR:
                case ID_PARM:
                    switch(t->kind) {
                        case T_ENUM:
                        case T_POINTER:
                            gen_code_i(LOD, id->level, id->address);
                            break;
                        case T_ARRAY:
                            if(id->kind==ID_VAR)
                                gen_code_i(LDA, id->level, id->address);
                            else
                                gen_code_i(LOD, id->level, id->address);
                            break;
                        case T_STRUCT:
                        case T_UNION:
                            gen_code_i(LDA, id->level, id->address);
                            i=id->type->size;
                            gen_code_i(LDI, 0, i%4?i/4+1:i/4);
                            break;
                        default:
                            gen_error(11, id->line, 0);
                            break;
                    }
                    break;
                case ID_ENUM_LITERAL:
                    gen_code_i(LITI, 0, id->init);
                    break;
                default:
                    gen_error(11, node->line, 0);
                    break;
            }
            break;
        case N_EXP_INT_CONST:
            gen_code_i(LITI, 0, node->clink);
            break;
        case N_EXP_FLOAT_CONST:
            i=node->clink;
            gen_code_i(LOD, 0, literal_table[i].addr);
            break;
        case N_EXP_CHAR_CONST:
            gen_code_i(LITI, 0, node->clink);
            break;
        case N_EXP_STRING_LITERAL:
            i=node->clink;
            gen_code_i(LDA, 0, literal_table[i].addr);
            break;
        case N_EXP_ARRAY:
            gen_expression(node->llink);
            gen_expression(node->rlink);
            //gen_code_i(CHK, 0, node->llink->type->expr);
            if(node->type->size>1) {
                gen_code_i(LITI, 0, node->type->size);
                gen_code_i(MULI, 0, 0);
            }
            gen_code_i(OFFSET, 0, 0);
            if(!isArrayType(node->type)) {
                i=node->type->size;
                if(i==1)
                    gen_code_i(LDIB, 0, 0);
                else
                    gen_code_i(LDI, 0, i%4?i/4+1:i/4);
            }
            break;
        case N_EXP_FUNCTION_CALL:
            t=node->llink->type;
            i=t->element_type->element_type->size;
            if(i%4) i=i/4*4+4;
            if(node->rlink) {
                gen_code_i(INT, 0, 12+i);
                gen_arg_expression(node->rlink);
                gen_code_i(POP, 0, node->rlink->value/4+3);
            }
            else
                gen_code_i(INT, 0, i);
            gen_expression(node->llink);
            gen_code_i(CAL, 0, 0);
            break;
        case N_EXP_STRUCT:
            gen_expression_left(node->llink);
            id=node->rlink;
            if(id->address>0) {
                gen_code_i(LITI, 0, id->address);
                gen_code_i(OFFSET, 0, 0);
            }
            if(!isArrayType(node->type)) {
                i=node->type->size;
                if(i==1)
                    gen_code_i(LDIB, 0, 0);
                else
                    gen_code_i(LDI, 0, i%4?i/4+1:i/4);
            }
            break;
        case N_EXP_ARROW:
            gen_expression(node->llink);
            id=node->rlink;
            if(id->address>0) {
                gen_code_i(LITI, 0, id->address);
                gen_code_i(OFFSET, 0, 0);
            }
            if(!isArrayType(node->type)) {
                i=node->type->size;
                if(i==1)
                    gen_code_i(LDIB, 0, 0);
                else
                    gen_code_i(LDI, 0, i%4?i/4+1:i/4);
            }
            break;
        case N_EXP_POST_INC:
            gen_expression(node->clink);
            gen_expression_left(node->clink);
            t=node->type;
            if(node->type->size==1)
                gen_code_i(LDXB, 0, 0);
            else
                gen_code_i(LDX, 0, 1);
            if(isPointerOrArrayType(node->type)) {
                gen_code_i(LITI, 0, node->type->element_type->size);
                gen_code_i(ADDI, 0, 0);
            }
            else if(isFloatType(node->type))
                gen_code_i(INCF, 0, 0);
            else
                gen_code_i(INCI, 0, 0);
            if(node->type->size==1)
                gen_code_i(STOB, 0, 0);
            else
                gen_code_i(STO, 0, 1);
            break;
        case N_EXP_POST_DEC:
            gen_expression(node->clink);
            gen_expression_left(node->clink);
            t=node->type;
            if(node->type->size==1)
                gen_code_i(LDXB, 0, 0);
            else
                gen_code_i(LDX, 0, 1);
            if(isPointerOrArrayType(node->type)) {
                gen_code_i(LITI, 0, node->type->element_type->size);
                gen_code_i(SUBI, 0, 0);
            }
            else if(isFloatType(node->type))
                gen_code_i(DECF, 0, 0);
            else
                gen_code_i(DECI, 0, 0);
            if(node->type->size==1)
                gen_code_i(STOB, 0, 0);
            else
                gen_code_i(STO, 0, 1);
            break;        
        case N_EXP_PRE_INC:
            gen_expression_left(node->clink);
            t=node->type;
            if(node->type->size==1)
                gen_code_i(LDXB, 0, 0);
            else
                gen_code_i(LDX, 0, 1);
            if(isPointerOrArrayType(node->type)) {
                gen_code_i(LITI, 0, node->type->element_type->size);
                gen_code_i(ADDI, 0, 0);
            }
            else if(isFloatType(node->type))
                gen_code_i(INCF, 0, 0);
            else
                gen_code_i(INCI, 0, 0);
            if(node->type->size==1)
                gen_code_i(STXB, 0, 0);
            else
                gen_code_i(STX, 0, 1);
            break;            
        case N_EXP_PRE_DEC:
            gen_expression_left(node->clink);
            t=node->type;
            if(node->type->size==1)
                gen_code_i(LDXB, 0, 0);
            else
                gen_code_i(LDX, 0, 1);
            if(isPointerOrArrayType(node->type)) {
                gen_code_i(LITI, 0, node->type->element_type->size);
                gen_code_i(SUBI, 0, 0);
            }
            else if(isFloatType(node->type))
                gen_code_i(DECF, 0, 0);
            else
                gen_code_i(DECI, 0, 0);
            if(node->type->size==1)
                gen_code_i(STXB, 0, 0);
            else
                gen_code_i(STX, 0, 1);
            break; 
        case N_EXP_NOT:
            gen_expression(node->clink);
            gen_code_i(NOT, 0, 0);
            break;
        case N_EXP_PLUS:
            gen_expression(node->clink);
            break;
        case N_EXP_MINUS:
            gen_expression(node->clink);
            if(isFloatType(node->clink))
                gen_code_i(MINUSF, 0, 0);
            else
                gen_code_i(MINUSI, 0, 0);
            break;
        case N_EXP_AMP:
            gen_expression_left(node->clink);
            break;
        case N_EXP_STAR:
            gen_expression(node->clink);
            i=node->type->size;
            if(i==1)
                gen_code_i(LDIB, 0, 0);
            else
                gen_code_i(LDI, 0, i%4?i/4+1:i/4);
            break;
        case N_EXP_SIZE_EXP:
            gen_code_i(LITI, 0, node->clink);
            break;
        case N_EXP_SIZE_TYPE:
            gen_code_i(LITI, 0, node->clink);
            break;
        case N_EXP_CAST:
            gen_expression(node->rlink);
            if(node->type!=node->rlink->type)
                if(isFloatType(node->type))
                    gen_code_i(CVTF, 0, 0);
                else if(isFloatType(node->rlink->type))
                    gen_code_i(CVTI, 0, 0);
            break;
        case N_EXP_MUL:
            gen_expression(node->llink);
            gen_expression(node->rlink);
            if(isFloatType(node->type))
                gen_code_i(MULF, 0, 0);
            else
                gen_code_i(MULI, 0, 0);
            break;
        case N_EXP_DIV:
            gen_expression(node->llink);
            gen_expression(node->rlink);
            if(isFloatType(node->type))
                gen_code_i(DIVF, 0, 0);
            else
                gen_code_i(DIVI, 0, 0);
            break;
        case N_EXP_MOD:
            gen_expression(node->llink);
            gen_expression(node->rlink);
            gen_code_i(MOD, 0, 0);
            break;
        case N_EXP_ADD:
            gen_expression(node->llink);
            if(isPointerOrArrayType(node->rlink->type)) {
                gen_code_i(LITI, 0, node->rlink->type->element_type->size);
                gen_code_i(MULI, 0, 0);
            }
            gen_expression(node->rlink);
            if(isPointerOrArrayType(node->llink->type)) {
                gen_code_i(LITI, 0, node->llink->type->element_type->size);
                gen_code_i(MULI, 0, 0);
            }
            if(isFloatType(node->type))
                gen_code_i(ADDF, 0, 0);
            else
                gen_code_i(ADDI, 0, 0);
            break;
        case N_EXP_SUB:
            gen_expression(node->llink);
            gen_expression(node->rlink);
            if(isPointerOrArrayType(node->llink->type) && !isPointerOrArrayType(node->rlink->type)) {
                    gen_code_i(LITI, 0, node->llink->type->element_type->size);
                    gen_code_i(MULI, 0, 0);
                }
            if(isFloatType(node->type))
                gen_code_i(SUBF, 0, 0);
            else
                gen_code_i(SUBI, 0, 0);
            break;
        case N_EXP_LSS:
            gen_expression(node->llink);
            gen_expression(node->rlink);
            if(isFloatType(node->llink->type))
                gen_code_i(LSSF, 0, 0);
            else
                gen_code_i(LSSI, 0, 0);
            break;
        case N_EXP_GTR:
            gen_expression(node->llink);
            gen_expression(node->rlink);
            if(isFloatType(node->llink->type))
                gen_code_i(GTRF, 0, 0);
            else
                gen_code_i(GTRI, 0, 0);
            break;            
        case N_EXP_LEQ:
            gen_expression(node->llink);
            gen_expression(node->rlink);
            if(isFloatType(node->llink->type))
                gen_code_i(LEQF, 0, 0);
            else
                gen_code_i(LEQI, 0, 0);
            break;
        case N_EXP_GEQ:
            gen_expression(node->llink);
            gen_expression(node->rlink);
            if(isFloatType(node->llink->type))
                gen_code_i(GEQF, 0, 0);
            else
                gen_code_i(GEQI, 0, 0);
            break;
        case N_EXP_NEQ:
            gen_expression(node->llink);
            gen_expression(node->rlink);
            if(isFloatType(node->llink->type))
                gen_code_i(NEQF, 0, 0);
            else
                gen_code_i(NEQI, 0, 0);
            break;
        case N_EXP_EQL:
            gen_expression(node->llink);
            gen_expression(node->rlink);
            if(isFloatType(node->llink->type))
                gen_code_i(EQLF, 0, 0);
            else
                gen_code_i(EQLI, 0, 0);
            break;        
        case N_EXP_AND:
            gen_expression(node->llink);
            gen_code_l(JPCR, 0, i=get_label());
            gen_expression(node->rlink);
            gen_label_number(i);
            break;
        case N_EXP_OR:
            gen_expression(node->llink);
            gen_code_l(JPCR, 0, i=get_label());
            gen_expression(node->rlink);
            gen_label_number(i);
            break;
        case N_EXP_ASSIGN:
            gen_expression_left(node->llink);
            gen_expression(node->rlink);
            i=node->type->size;
            if(i==1)
                gen_code_i(STXB, 0, 0);
            else
                gen_code_i(STX, 0, i%4?i/4+1:i/4);
            break;
        default:
            gen_error(100, node->line, 0);
            break;
    }
}

void gen_expression_left(A_NODE* node) {
    A_ID* id;
    A_TYPE* t;
    int result;
    switch(node->name) {
        case N_EXP_IDENT:
            id=node->clink;
            t=id->type;
            switch(id->kind) {
                case ID_VAR:
                case ID_PARM:
                    switch(t->kind) {
                        case T_ENUM:
                        case T_POINTER:
                        case T_STRUCT:
                        case T_UNION:
                            gen_code_i(LDA, id->level, id->address);
                            break;                             
                        case T_ARRAY:                    
                            if(id->kind==ID_VAR)
                                gen_code_i(LDA, id->level, id->address);
                            else
                                gen_code_i(LOD, id->level, id->address);
                            break;
                        default:
                            gen_error(13, node->line, id->name);
                            break;
                    }
                    break;
                case ID_FUNC:
                    gen_code_s(ADDR, 0, id->name);
                    break;
                default:
                    gen_error(13, node->line, id->name);
                    break;
            }
            break;
        case N_EXP_ARRAY:
            gen_expression(node->llink);
            gen_expression(node->rlink);
            //gen_code_i(CHK, 0, node->llink->type->expr);
            if(node->type->size>1) {
                gen_code_i(LITI, 0, node->type->size);
                gen_code_i(MULI, 0, 0);
            }
            gen_code_i(OFFSET, 0, 0);
            break;
        case N_EXP_STRUCT:
            gen_expression_left(node->llink);
            id=node->rlink;
            if(id->address>0) {
                gen_code_i(LITI, 0, id->address);
                gen_code_i(OFFSET, 0, 0);
            }         
            break;            
        case N_EXP_ARROW:
            gen_expression(node->llink);
            id=node->rlink;
            if(id->address>0) {
                gen_code_i(LITI, 0, id->address);
                gen_code_i(OFFSET, 0, 0);
            }
            break;
        case N_EXP_STAR:
            gen_expression(node->clink);
            break;   
        case N_EXP_INT_CONST: 
        case N_EXP_FLOAT_CONST:
        case N_EXP_CHAR_CONST:
        case N_EXP_STRING_LITERAL:
        case N_EXP_FUNCTION_CALL:
        case N_EXP_POST_INC:
        case N_EXP_POST_DEC:
        case N_EXP_PRE_INC:
        case N_EXP_PRE_DEC:
        case N_EXP_NOT:
        case N_EXP_MINUS:
        case N_EXP_SIZE_EXP:
        case N_EXP_SIZE_TYPE:
        case N_EXP_CAST:
        case N_EXP_MUL:
        case N_EXP_DIV:
        case N_EXP_MOD:
        case N_EXP_ADD:
        case N_EXP_SUB:
        case N_EXP_LSS:
        case N_EXP_GTR:
        case N_EXP_LEQ:
        case N_EXP_GEQ:
        case N_EXP_NEQ:
        case N_EXP_EQL:
        case N_EXP_AMP:
        case N_EXP_AND:
        case N_EXP_OR:
        case N_EXP_ASSIGN:
            gen_error(12, node->line, 0);
            break;
        default:
            gen_error(100, node->line, 0);
            break;
    }
}

void gen_arg_expression(A_NODE* node) {
    A_NODE* n;
    switch(node->name) {
        case N_ARG_LIST:
            gen_expression(node->llink);
            gen_arg_expression(node->rlink);
            break;
        case N_ARG_LIST_NIL:
            break;
        default:
            gen_error(100, node->line, 0);
            break;
    }
}

int get_label() {
    label_no++;
    return(label_no);
}

void gen_statement(A_NODE* node, int cont_label, int break_label, A_SWITCH sw[], int* sn) {
    A_SWITCH switch_table[100];
    int switch_no=0;
    A_NODE* n;
    int i, l1, l2, l3;
    switch(node->name) {
        case N_STMT_LABEL_CASE:
            if(sw) {
                *sn=*sn+1;
                sw[*sn].kind=SW_VALUE;
                sw[*sn].val=node->llink;
                sw[*sn].label=l1=get_label();
                gen_label_number(l1);
            }
            else
                gen_error(21, node->line, 0);
            gen_statement(node->rlink, cont_label, break_label, sw, sn);
            break;
        case N_STMT_LABEL_DEFAULT:
            if(sw) {
                *sn=*sn+1;
                sw[*sn].kind=SW_DEFAULT;
                sw[*sn].label=l1=get_label();
                gen_label_number(l1); 
            }
            else
                gen_error(20, node->line, 0);
            gen_statement(node->clink, cont_label, break_label, sw, sn);
            break;           
        case N_STMT_COMPOUND:
            if(node->llink)
                gen_declaration_list(node->llink);
            gen_statement_list(node->rlink, cont_label, break_label, sw, sn);
            break;
        case N_STMT_EMPTY:
            break;
        case N_STMT_EXPRESSION:
            n=node->clink;
            gen_expression(n);
            i=n->type->size;
            if(i)
                gen_code_i(POP, 0, i%4?i/4+1:i/4);
            break;
        case N_STMT_IF:
            gen_expression(node->llink);
            gen_code_l(JPC,0, l1=get_label());
            gen_statement(node->rlink, cont_label, break_label, 0, 0);
            gen_label_number(l1);
            break;
        case N_STMT_IF_ELSE:
            gen_expression(node->llink);
            gen_code_l(JPC,0, l1=get_label());
            gen_statement(node->clink, cont_label, break_label, 0, 0);
            gen_code_l(JMP, 0, l2=get_label());
            gen_label_number(l1);
            gen_statement(node->rlink, cont_label, break_label, 0, 0);
            gen_label_number(l2);
            break;
        case N_STMT_SWITCH:
            gen_expression(node->llink);
            gen_code_l(SWITCH, 0, l1=get_label());
            gen_code_l(JMP, 0, l2=get_label());
            gen_statement(node->rlink, cont_label, l2, switch_table, &switch_no);
            gen_label_number(l1);
            for(i=1; i<=switch_no; i++) {
                if(switch_table[i].kind==SW_VALUE)
                    gen_code_i(SWVALUE, 0, switch_table[i].val);
                else
                    gen_code_i(SWDEFAULT, 0, 0);
                gen_code_l(SWLABEL, 0, switch_table[i].label);
            }
            gen_code_i(SWEND, 0, 0);
            gen_label_number(l2);
            break;
        case N_STMT_WHILE:
            l3=get_label();
            gen_label_number(l1=get_label());
            gen_expression(node->llink);
            gen_code_l(JPC, 0, l2=get_label());
            gen_statement(node->rlink, l3, l2, 0, 0);
            gen_label_number(l3);
            gen_code_l(JMP, 0, l1);
            gen_label_number(l2);
            break;
        case N_STMT_DO:
            l3=get_label();
            l2=get_label();
            gen_label_number(l1=get_label());
            gen_statement(node->llink, l2, l3, 0, 0);
            gen_label_number(l2);
            gen_expression(node->rlink);
            gen_code_l(JPT, 0, l1);
            gen_label_number(l3);
            break;
        case N_STMT_FOR:
            n=node->llink;
            l3=get_label();
            if(n->llink) {
                gen_expression(n->llink);
                i=n->llink->type->size;
                if(i)
                    gen_code_i(POP, 0, i%4?i/4+1:i/4);
            }
            gen_label_number(l1=get_label());
            l2=get_label();
            if(n->clink) {
                gen_expression(n->clink);
                gen_code_l(JPC, 0, l2);
            }
            gen_statement(node->rlink, l3, l2, 0, 0);
            gen_label_number(l3);
            if(n->rlink) {
                gen_expression(n->rlink);
                i=n->rlink->type->size;
                if(i)
                    gen_code_i(POP, 0, i%4?i/4+1:i/4);
            }
            gen_code_l(JMP, 0, l1);
            gen_label_number(l2);
            break;
        case N_STMT_CONTINUE:
            if(cont_label)
                gen_code_l(JMP, 0, cont_label);
            else
                gen_error(22, node->line, 0);
            break;
        case N_STMT_BREAK:
            if(break_label)
                gen_code_l(JMP, 0, break_label);
            else
                gen_error(23, node->line, 0);
            break;
        case N_STMT_RETURN:
            n=node->clink;
            if(n) {
                i=n->type->size;
                if(i%4) i=i/4*4+4;
                gen_code_i(LDA, 1, -i);
                gen_expression(n);
                gen_code_i(STO, 0, i/4);
            }
            gen_code_i(RET, 0, 0);
            break;
        default:
            gen_error(100, node->line, 0);
            break;
    }
}

void gen_statement_list(A_NODE* node, int cont_label, int break_label, A_SWITCH sw[], int* sn) {
    switch(node->name) {
        case N_STMT_LIST:
            gen_statement(node->llink, cont_label, break_label, sw, sn);
            gen_statement_list(node->rlink, cont_label, break_label, sw, sn);
            break;
        case N_STMT_LIST_NIL:
            break;
        default:
            gen_error(100, node->line, 0);
            break;
    }
}

void gen_initializer_global(A_NODE* node, A_TYPE* t, int addr) {
    ;
}

void gen_initializer_local(A_NODE* node, A_TYPE* t, int addr) {
    ;
}

void gen_declaration_list(A_ID* id) {
    while(id) {
        gen_declaration(id);
        id=id->link;
    }
}

void gen_declaration(A_ID* id) {
    int i;
    A_NODE* node;
    switch(id->kind) {
        case ID_VAR:
            if(id->init) {
                if(id->level==0)
                    gen_initializer_global(id->init, id->type, id->address);
                else
                    gen_initializer_local(id->init, id->type, id->address);
            }
            break;                
        case ID_FUNC:
            if(id->type->expr) {
                gen_label_name(id->name);
                gen_code_i(INT, 0, id->type->local_var_size);
                gen_statement(id->type->expr, 0, 0, 0, 0);
                gen_code_i(RET, 0, 0);
            }
            break;
        case ID_PARM:
        case ID_TYPE:
        case ID_ENUM:
        case ID_STRUCT:
        case ID_FIELD:
        case ID_ENUM_LITERAL:
        case ID_NULL:
            break;
        default:
            gen_error(100, id->line, 0);
            break;
    }
}

void gen_error(int i, int ll, char*s) {
    gen_err++;
    printf("*** error at line %d: ", ll);
    switch(i) {
        case 11:
            printf("illegal identifier in expression \n");
            break;
        case 12:
            printf("illegal l-value expression \n");
            break;
        case 13:
            printf("identifier %s not l-value expression \n", s);
            break;
        case 20:
            printf("illegal default label in switch statement \n");
            break;
        case 21:
            printf("illegal case label in switch statement \n");
            break;
        case 22:
            printf("no destination for continue statement \n");
            break;
        case 23:
            printf("no destination for break statement \n");
            break;
        case 100:
            printf("fatal compiler error during code generation \n");
            break;
        default:
            printf("unknown \n");
            break;
    }
}

void gen_code_i(OPCODE op, int l, int a) {
    fprintf(fout, "\t%9s  %d, %d\n", opcode_name[op], l, a);
}

void gen_code_f(OPCODE op, int l, float a) {
    fprintf(fout, "\t%9s  %d, %f\n", opcode_name[op], l, a);
}

void gen_code_s(OPCODE op, int l, char* a) {
    fprintf(fout, "\t%9s  %d, %s\n", opcode_name[op], l, a);
}

void gen_code_l(OPCODE op, int l, int a) {
    fprintf(fout, "\t%9s  %d, L%d\n", opcode_name[op], l, a);
}

void gen_label_number(int i) {
    fprintf(fout, "L%d:\n", i);
} 

void gen_label_name(char* s) {
    fprintf(fout, "%s:\n", s);
}                