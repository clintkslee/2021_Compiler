//20172655 LEE KANG SAN
//UTF-8

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NUMBER 256
#define PLUS 257
#define STAR 258
#define LPAREN 259
#define RPAREN 260
#define END 261
#define EXPRESSION 0
#define TERM 1
#define FACTOR 2
#define ACC 999

//action table : {n, +, *, (, ), $}
int action[12][6]={ //shift > 0, reduce < 0, error=0  
	{5,0,0,4,0,0}, {0,6,0,0,0,ACC}, {0,-2,7,0,-2,-2}, 
	{0,-4,-4,0,-4,-4}, {5,0,0,4,0,0}, {0,-6,-6,0,-6,-6}, 
	{5,0,0,4,0,0}, {5,0,0,4,0,0}, {0,6,0,0,11,0}, 
	{0,-1,7,0,-1,-1}, {0,-3,-3,0,-3,-3}, {0,-5,-5,0,-5,-5}};

//goto table : {E, T, F}
int go_to[12][3]={ 
	{1,2,3}, {0,0,0}, {0,0,0}, {0,0,0}, 
	{8,2,3}, {0,0,0}, {0,9,3}, {0,0,10},
	{0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}};

//left side of grammar
int prod_left[7]={0,EXPRESSION,EXPRESSION,TERM,TERM,FACTOR,FACTOR};

//length of right side of grammar for REDUCE
int prod_length[7]={0,3,1,3,1,3,1};

int stack[1000]; //LR파싱을 위한 stack
int value[1000]; //현재 stack에 숫자가 push되었을 경우 같은 index 위치에 값을 저장 
char yytext[32]; //yylex()에서 숫자 입력 시 atoi() 위해 저장되는 배열
int yylval; //토큰이 숫자일 경우 값 임시 저장
int top=-1; //stack을 가리키는 index
int sym; //stack top의 symbol

void yyparse();
void push(int); //top을 1 증가시키고 stack에 상태번호 push
void shift(int i); //shift : stack, value에 값 저장
void reduce(int); //reduce : 규칙 번호에 따라 stack, value배열 연산
void yyerror(); //syntax error 시 호출되는 함수
int yylex(); //입력된 토큰 구분
void lex_error(); //지정되지 않은 토큰 입력 시 호출되는 함수

void main() {
	printf(">>> Simple LR Parser <<<\n");
	printf("Available input : 0, natural number, +, *, (, )\n");
	printf("Expression must be ended with '$'(DOLLAR)\n");
	printf(">> ");
	yyparse();
}

void yyparse() {
	int i;
	stack[++top]=0; //initial top value : -1, 스택에 0 넣고 시작
	sym=yylex();
	printf("====================\n");
	do {
		i=action[stack[top]][sym-256];
		if(i==ACC) { //accept
			printf("====================\n");
			printf("Success! The answer is %d\n", value[top]);
		}
		else if(i>0) { //shift i
			printf("shift  %3d\n", i);
			shift(i);
		}
		else if(i<0) { //reduce i
			printf("reduce %3d\n", -i);
			reduce(-i);
		}
		else //error
			yyerror();
	}while(i!=ACC);
}

void push(int i) { //insert at stack
	top++;
	stack[top]=i;
}

void shift(int i) {
	push(i);
	value[top]=yylval;
	sym=yylex(); //다음 토큰 읽기
}

void reduce(int i) {
	int old_top; 
	old_top=top;
	top=top-prod_length[i]; //remove 2|a| from stack
	push(go_to[stack[top]][prod_left[i]]); //reduce 후 새로운 stack top 위치에 push 
	switch (i) {//reduce에 따른 value 계산
		case 1: //E -> E + T
			value[top]=value[old_top]+value[old_top-2];
			break;
		case 2: //E -> T
			value[top]=value[old_top];
			break;
		case 3: //T -> T * F
			value[top]=value[old_top]*value[old_top-2];
			break;
		case 4: //T -> F
			value[top]=value[old_top];
			break;
		case 5: //F -> ( E )
			value[top]=value[old_top-1];
			break;
		case 6: //F -> n
			value[top]=value[old_top];
			break;
		default:
			printf("====================\n");
			printf("Error! parsing table error\n");
			exit(1);
			break;
	}
}

void yyerror() {
	printf("====================\n");
	printf("Error! syntax error\n");
	exit(1);
}

int yylex() {
	static char ch=' ';
	int i=0;
	while(ch==' '||ch=='\t'||ch=='\n') ch=getchar(); //remove white space
	if(isdigit(ch)) { //첫 입력이 숫자일 경우 
		do {
			yytext[i++]=ch; //yytext에 숫자 저장
			ch=getchar();
		}while(isdigit(ch)); //입력이 숫자가 아닐 떄까지 반복
		yytext[i]=0;
		yylval=atoi(yytext);
		return NUMBER;
	}
	else if(ch=='+') {
		ch=getchar();
		return PLUS;
	}
	else if(ch=='*') {
		ch=getchar();
		return STAR;
	}
	else if(ch=='(') {
		ch=getchar();
		return LPAREN;
	}
	else if(ch==')') {
		ch=getchar();
		return RPAREN;
	}
	else if(ch=='$') //Expression must be ended with DOLLAR
		return END;
	else
		lex_error();
}

void lex_error() {
	printf("====================\n");
	printf("Error! illegal token\n");
	exit(1);
}
