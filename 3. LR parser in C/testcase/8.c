#include<stdio.h>

int main() {
	int a=10, b=20, c=30;
	int x=1, y=0;
	a=a<<1;
	a=a>>1;
	b=a>c?a:c;
	a++;
	--b;
	c=sizeof(c);
	if(b!=a) b=a;
	if(x&&y) printf("x and y both 1\n");
	if(x||y) printf("either x or y is 1\n");
	return 0;
}
