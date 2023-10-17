#include<stdio.h>

enum color { white, red=10, green=11, blue, black } c1;
enum color c2;
int main() {
	c1=white;
	c2=green;
	return 0;
}
