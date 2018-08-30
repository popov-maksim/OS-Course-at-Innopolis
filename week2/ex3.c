#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int width = 2 * n - 1;

	for (int i = 1; i <= width; i += 2) {
		int spaceAmount = width / 2 - i / 2;
		for (int j = 0; j < spaceAmount; ++j) {
			printf(" ");
		}
		for (int j = 0; j < i; ++j) {
			printf("*");
		}

		printf("\n");
	}

	return 0;
}
