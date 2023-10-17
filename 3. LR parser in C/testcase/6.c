#include<stdio.h>

int main() {
	int a=3;
	char value;
	if(a>5) 
		value='A';
	else
		value='a';
	
	switch (value) {
		case 'A': value=value+32; break;
		case 'a': value=value-32; break;
		default: break; 
	}
	return 0;
}
