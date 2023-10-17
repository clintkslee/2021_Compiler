typedef struct _s{
	int a;
	float b;
}mystruct;

int main() {
	int arr[3];
	mystruct s;
	scanf("%d", &arr[0]);
	scanf("%f", &s.b);
	printf("%d %f\n", arr[0], s.b);
}
