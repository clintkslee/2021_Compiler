#pragma warning(disable: 4996)
// 20172655 이강산 //
#include <stdio.h>
#include <ctype.h>
/* Global declarations */
/* Variables */
int charClass;
char lexeme[100];
char nextChar;
int lexLen;
int nextToken;
FILE* in_fp;

/* reserved word lookup table */
char* reserved_word[13] = { "for", "if", "else", "while", "do", "int", "float", "switch", "char", "case", "break", "continue", "default" };
#define RESERVED_WORD_CNT 13

/* var for check float and increment operation */
int float_check = 0; //set float_check if current lexeme is float
int incre_check = 0; //set incre_check if current lexeme is increment operation

/* Function declarations */
int lookup(char);
int lookup_ident(char);
void addChar();
void getChar();
void getNonBlank();
int lex();

/* Character classes */
#define LETTER 0 //A-Z, a-z
#define DIGIT 1 //number
#define UNKNOWN 99 //not included in LETTER and DIGIT

/* Token codes */
#define INT_LIT 10 //integer literal
#define FLOAT_LIT 62 //float literal
#define IDENT 11 //identifier

#define ASSIGN_OP 20 //=
#define ADD_OP 21 //+
#define SUB_OP 22 //-
#define MULT_OP 23 //*
#define DIV_OP 24 ///
#define MOD_OP 63 //%
#define INCRE_OP 64 //++
#define CMPRIGHT_OP 65 //<
#define CMPLEFT_OP 66 //>
#define LEFT_PAREN 25 //(
#define RIGHT_PAREN 26 //)
#define LEFT_BRACE 60 //{
#define RIGHT_BRACE 61 //}
#define QUOTES 67 //'
#define COLON 68 //:
#define SEMICOLON 69 //;

/* reserved words */
#define FOR_CODE 30 //for       
#define IF_CODE 31 //if         
#define ELSE_CODE 32 //else         
#define WHILE_CODE 33 //while          
#define DO_CODE 34 //do           
#define SWITCH_CODE 37 //switch        
#define INT_CODE 35 //int
#define FLOAT_CODE 36 //float  
#define CHAR_CODE 38 //char
#define CASE_CODE 39 //case 
#define BREAK_CODE 40 //break 
#define CONTINUE_CODE 41 //continue
#define DEFAULT_CODE 42 //default
/******************************************************/
int main() {
	if ((in_fp = fopen("front01.c", "r")) == NULL)
		printf("ERROR - cannot open front.in \n");
	else {
		getChar(); //get first character from data file.
		do {
			lex();
		} while (nextToken != EOF);

		system("pause");
		return 0;
	}
}
/*****************************************************/
/* lookup - a function to lookup operators and parentheses
and return the token */
int lookup(char ch) {
	switch (ch) {
	case '=':
		addChar();
		nextToken = ASSIGN_OP;
		break;
	case '+':
		addChar();
		if (incre_check == 1) nextToken = INCRE_OP;
		else nextToken = ADD_OP;
		break;
	case '-':
		addChar();
		nextToken = SUB_OP;
		break;
	case '*':
		addChar();
		nextToken = MULT_OP;
		break;
	case '/':
		addChar();
		nextToken = DIV_OP;
		break;
	case '%':;
		addChar();
		nextToken = MOD_OP;
		break;
	case '<':
		addChar();
		nextToken = CMPRIGHT_OP;
		break;
	case '>':
		addChar();
		nextToken = CMPLEFT_OP;
		break;
	case '(':
		addChar();
		nextToken = LEFT_PAREN;
		break;
	case ')':
		addChar();
		nextToken = RIGHT_PAREN;
		break;
	case '{':
		addChar();
		nextToken = LEFT_BRACE;
		break;
	case '}':		
		addChar();
		nextToken = RIGHT_BRACE;
		break;
	case '\'':
		addChar();
		nextToken = QUOTES;
		break;
	case ':':		
		addChar();
		nextToken = COLON;
		break;
	case ';':
		addChar();
		nextToken = SEMICOLON;
		break;
	default:
		addChar();
		nextToken = EOF;
		break;
	}
	return nextToken;
}
/*****************************************************/
/* lookup_ident - a function to check whether current lexeme(ident) is a reserved word */
int lookup_ident() {
	int i;
	for (i = 0; i < RESERVED_WORD_CNT; i++)
	{
		if (strcmp(lexeme, reserved_word[i]) == 0)
		{
			nextToken = i + 30; //예약어의 TOKEN CODE와 reserved_word_lookup_table의 index 가 30 차이나도록 설계
			return nextToken;
		}
	}
	nextToken = IDENT;
	return nextToken;
}
/*****************************************************/
/* addChar - a function to add nextChar to lexeme */
void addChar() {
	if (lexLen <= 98) {
		lexeme[lexLen++] = nextChar;
		lexeme[lexLen] = 0;
	}
	else
		printf("Error - lexeme is too long \n");
}
/*****************************************************/
/* getChar - a function to get the next character of input and determine its character class */
void getChar() {
	if ((nextChar = getc(in_fp)) != EOF) { //읽어온 게 EOF 아니면 수행
		if (isalpha(nextChar)||nextChar=='_') //A-Z:1, a-z:2, 알파벳 아닐 시 0, 변수명에 _(언더바)포함 고려
			charClass = LETTER;
		else if (isdigit(nextChar) || nextChar == '.')//읽어온 문자가 숫자로 변경 가능하면 1, 아니면 0, .(소수점)은 float 판별 위해 추가
		{
			if (nextChar == '.') float_check = 1;
			charClass = DIGIT;
		}
		else charClass = UNKNOWN; //알파벳, 숫자 아닌 문자들
	}
	else //File End
		charClass = EOF;
}
/*****************************************************/
/* getNonBlank - a function to call getChar until it returns a non-whitespace character */
void getNonBlank() {
	while (isspace(nextChar)) //공백이면 1, 아니면 0
		getChar();            //읽어온 문자가 공백 아닐 때까지 반복
}
/*****************************************************/
/* lex - a simple lexical analyzer for arithmetic
expressions */
int lex() {
	lexLen = 0;
	getNonBlank();
	switch (charClass) { //최초 getChar()로 얻은 charClass로 시작
		/* Parse identifiers */
	case LETTER:
		addChar();
		getChar();
		while (charClass == LETTER || charClass == DIGIT) {
			addChar();
			getChar();
		}
		lookup_ident();
		break;
		/* Parse integer literals */
	case DIGIT:
		addChar();
		getChar();
		while (charClass == DIGIT) {
			addChar();
			getChar();
		}
		if(float_check==1)	nextToken = FLOAT_LIT;
		else nextToken = INT_LIT;
		break;
		/* Parentheses and operators */
	case UNKNOWN:
		lookup(nextChar);
		getChar();
		if (nextChar == '+')
		{
			incre_check = 1;
			lookup(nextChar);
			getChar();
		}
		else;
		break;
		/* EOF */
	case EOF:
		nextToken = EOF;
		lexeme[0] = 'E';
		lexeme[1] = 'O';
		lexeme[2] = 'F';
		lexeme[3] = 0;
		break;
	} /* End of switch */
	float_check = 0;
	printf("Next token is: %d, Next lexeme is %s\n", nextToken, lexeme);
	return nextToken;
} /* End of function lex */