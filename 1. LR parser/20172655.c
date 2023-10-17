//20172655 LEE KANG SAN
//UTF-8
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <math.h>

typedef struct {
	enum {INT, FLOAT}type;
    union {int i; float f;}value;
}NUM; //정수, 실수를 저장하기 위한 NUM타입 구조체
NUM num;

enum {Null, NUMBER, PLUS, MINUS, STAR, DIVIDE, LP, RP, END}token;

char temptok='\0'; //숫자 get_token() 시 꺼내어진 다른 토큰 임시 저장용 변수
int cur=0; //longnum 배열 가리키는 커서
char longnum[100]; //문자열을 숫자로 변환하기 전 저장될 버퍼

NUM expression();
NUM term();
NUM factor();
NUM calcul_NUM(NUM result, NUM func, char); //NUM타입 변수 간 사칙연산 수행
void get_token();
void error(int);

void main() {
	NUM result;
	result.type=INT;
	result.value.i=0;

	printf("***** Recursive-Descent Parser for simple mathematical expression *****\n\n");
	printf("Available Input : NUMBERs greater than or equal to 0, +, -, *, /, (, )\n\n");
	printf(">> : "); 
	
	get_token();
	result=expression();
	if(token!=END)
		error(3);
	else {
		if(result.type==INT)
			printf("   = %d\n\n", result.value.i);
		else
			printf("   = %.3f\n\n", result.value.f);
	}

}

NUM expression() {
	NUM result;
	result=term();
	while(token==PLUS||token==MINUS) { //가감연산 수행
		if(token==PLUS) {
			get_token();
			result=calcul_NUM(result, term(), '+');
		}
		else if(token==MINUS) { 
			get_token();
			result=calcul_NUM(result, term(), '-');
		}
	}
	return result;
}

NUM term() {
	NUM result;
	result=factor();
	while(token==STAR||token==DIVIDE) { //승제연산 수행
		if(token==STAR) {
			get_token();
			result=calcul_NUM(result, factor(), '*');
		}
		else if(token==DIVIDE) {
			get_token();
			result=calcul_NUM(result, factor(), '/');
		}
	}
	return result;
}

NUM factor() {
	NUM result;
	if(token==NUMBER) {
		result=num; 
		get_token();
	}
	else if(token==LP) {
		get_token();
		result=expression();
		if(token==RP)
			get_token();
		else
			error(2); //열린 괄호 닫지 않을 시 에러
	}
	else
		error(1); //숫자나 여는 괄호로 시작하지 않을 시 에러
	return result;
}

NUM calcul_NUM(NUM result, NUM func, char op) {
	NUM temp;
	float a, b;
	if(result.type==INT && func.type==INT) //두 숫자 모두 정수일 시 결과 타입 정수
		temp.type=INT;
	else //그 외의 경우 각각의 숫자를 float 변수에 저장
	{
		temp.type=FLOAT;
		if(result.type==INT)
			a=result.value.i;
		else
			a=result.value.f;
		if(func.type==INT)
			b=func.value.i;
		else
			b=func.value.f;
	}
	switch(op) { //사칙연산
		case '+':
			if(temp.type==INT)
				temp.value.i=result.value.i+func.value.i;
			else
				temp.value.f=a+b;
			break;
		case '*':
			if(temp.type==INT)
				temp.value.i=result.value.i*func.value.i;
			else	
				temp.value.f=a*b;
			break;
		case '-':
			if(temp.type==INT)
				temp.value.i=result.value.i-func.value.i;
			else	
				temp.value.f=a-b;
			break;
		case '/':
			if(temp.type==INT) {
				if(func.value.i==0)
					error(6); //0으로 나누는 경우 에러
				temp.value.i=result.value.i/func.value.i;
			}
			else {
				if(fabsf(b-0.0f)<=FLT_EPSILON)
					error(6); //0으로 나누는 경우 에러
				temp.value.f=a/b;
			break;
			}
	}	
	return temp;
}

void get_token() { //stdin 버퍼로부터 토큰 하나씩 getchar() 하여 parsing 수행
	char tok; //읽은 토큰 하나 저장
	if(temptok=='\0') 
		tok=getchar(); 
	else { //이전에 NUM 불러오면서 미리 불러온 token이 있다면 그대로 사용
		tok=temptok;
		temptok='\0';
	}
	while(tok==' ') //공백 예외처리
		tok=getchar(); 
	if(tok=='\n') //stdin 내의 개행문자로 입력 종료 판단
		token=END;

	else if('0'<=tok && tok<='9' || tok=='.') { //0, 십진수 자연수, 양의 실수만 인식
		num.type=INT; 
		cur=0; //두자리 이상 정수, 실수 임시 저장 버퍼에 사용되는 커서 초기화
		longnum[cur]=tok;

		if(tok=='.') {// .으로 시작하는 실수 인식(.5, .37 ...)
			num.type=FLOAT;
			tok=getchar(); //소수점 바로 다음 자리 읽어보기
			if('0' > tok || tok > '9')  //소수점 바로 다음에 숫자 안오면 에러
				error(4); //소수점 바로 뒤에 숫자가 나오지 않은 경우 에러
			longnum[++cur]=tok; //소수점 바로 다음 자리가 숫자면 계속 읽기
			while('0'<=tok && tok<='9') { //숫자가 아닌 토큰 입력 시 탈출
				tok=getchar();
				longnum[++cur]=tok; 
			}
			if(tok=='.')
				error(4); //소수점이 두 번 나온 경우 에러
			temptok=tok; //숫자와 관련 없는 토큰 다음 수행에 사용 위해 저장
			longnum[cur]='\0';
			num.value.f=atof(longnum);
			cur=0;
		}
		else if(tok=='0') { //0으로 시작하는 수(정수 0, 0.3, 0.75 ...)
			int cnt=0; //소수점 개수 카운터
			tok=getchar();
			if(tok=='.') {
				cnt++;
				num.type=FLOAT;
				longnum[++cur]=tok; 
				while('0'<=tok && tok<='9' || tok=='.') {
					if(cnt<1)
						error(4); //소수점이 두 번 나온 경우 에러
					tok=getchar();
					longnum[++cur]=tok;
				}
				temptok=tok; //숫자와 관련 없는 토큰 다음 수행에 사용 위해 저장
				longnum[cur]='\0';
				num.value.f=atof(longnum);
				cur=0;
			}
			else if('0'<=tok && tok<='9')
				error(5); //8진수 정수 예외처리

			else {//그냥 정수 0인 경우 - 첫 0 직후 숫자나 소수점 이외의 문자
				temptok=tok;
				num.value.i=0;
			}
		}
		else { //1이상의 자연수로 시작하는 수(자연수, 1이상 실수)
			int cnt=0; //소수점 개수 카운터
			while('0'<=tok && tok<='9' || tok=='.') {
				if(cnt>1)
					error(4); //소수점이 두 번 나온 경우 에러
				tok=getchar();
				longnum[++cur]=tok;
				if(tok=='.') {
					num.type=FLOAT;
					cnt++;
				}
			}
			temptok=tok; //숫자와 관련 없는 토큰 다음 수행에 사용 위해 저장
			longnum[cur]='\0';
			if(num.type==INT)
				num.value.i=atoi(longnum);
			else
				num.value.f=atof(longnum);
			cur=0;
		}
		token=NUMBER;
	}
	else if(tok=='+')
		token=PLUS;
	else if(tok=='-')
		token=MINUS;
	else if(tok=='*')
		token=STAR;
	else if(tok=='/')
		token=DIVIDE;
	else if(tok=='(')
		token=LP;
	else if(tok==')')
		token=RP;
	else
		token=Null;
}

void error(int i) {
	switch(i) {
		case 1: 
			printf(">>>>> An error occurs! incorrect expression!\n\n");
			break;
		case 2: 
			printf(">>>>> An error occurs! ) is expected!\n\n");
			break; 
		case 3: 
			printf(">>>>> An error occurs! wrong end!\n\n");
			break;
		case 4:
			printf(">>>>> An error occurs! wrong float!\n\n");
			break;
		case 5:
			printf(">>>>> An error occurs! octal number is not allowed!\n\n");
			break;
		case 6:
			printf(">>>>> An error occurs! divide with zero is not defined!\n\n");
			break;
	}
	exit(1);
}
