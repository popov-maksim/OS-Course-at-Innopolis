#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
	int intVar = INT_MAX;
	float floatVar = FLT_MAX;
	double doubleVar = DBL_MAX;

	printf("Size of int variable: %li\n", sizeof(intVar));
	printf("Max value of int variable: %d\n", intVar);

	printf("Size of float variable: %li\n", sizeof(floatVar));
	printf("Max value of float variable: %f\n", floatVar);

	printf("Size of double variable: %li\n", sizeof(doubleVar));
	printf("Max value of double variable: %f\n", doubleVar);

	

	return 0;
}
