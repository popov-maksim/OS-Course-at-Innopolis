#include <stdio.h>
#include <unistd.h>

#define NUM 20

int main() {
    FILE *f = fopen("/dev/random", "r");
    for (int i = 0; i < NUM; ++i) {
        char in;
        fread(&in, 1, 1, f);
        printf("%c", in);
    }

    printf("\n");
    fclose(f);

    return 0;
}