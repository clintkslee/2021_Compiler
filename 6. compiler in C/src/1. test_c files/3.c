int main() {
	int i;
	int a;
	a=0;
	for(i=0; i<10; i++)
		a++;
	a=a%2;
	switch (a) {
		case 0: 
			i=13; 
			break;
		case 1: 
			i=-13; 
			break;
	}
	printf("a:%d i:%d\n", a, i);
}
