#include<stdio.h>
int main() {
	int a=3, i;
	while(a>0) { 
		a++; 
		if(a==25) break;
	}
	for(i=0; i<10; i++) {
		if(i%3==0) continue;
		printf("%d\n", i); 
	}
	return 0;
}
