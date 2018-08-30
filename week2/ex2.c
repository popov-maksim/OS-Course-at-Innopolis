#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int main() {
	char str[MAX_LEN + 1];
	int i = 0;

	scanf("%s", str);

	for (int i = strlen(str) - 1; i > -1; --i) {
		printf("%c", str[i]);
	}
	printf("\n");

	return 0;
}
