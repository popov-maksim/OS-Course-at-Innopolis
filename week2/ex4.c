#include <stdio.h>

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main() {
	int a, b;

	printf("Enter the first number: ");
	scanf("%d", &a);

	printf("Enter the second number: ");
	scanf("%d", &b);

	swap(&a, &b);

	printf("The first number is %d\n", a);
	printf("The second number is %d\n", b);

	return 0;
}
