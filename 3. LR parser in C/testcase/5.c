#include<stdio.h>

void func1(char, int);
int func2(void);
char* func3(const int*);

int main() {
	int x;
	char* c;
	func1('a', 3);
	x = func2();
	c = func3(&x);
	return 0;
}

void func1(char p1, int p2) { ; }
int func2(void) { return 100; }
char* func3(const int* p3) { return (char*)p3; }
