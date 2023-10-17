#include<stdio.h>

struct my_struct{ int b[3]; float c; }
typedef union{ int b; float c; }my_union;
int main() {
	struct my_struct s1, s2;
	s1.c=3.14;
	my_union.b=3;
	return 0;
}
