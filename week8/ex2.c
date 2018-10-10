#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MEM_SIZE 10 * 1024 * 1024

int main() {
    for (int i = 0; i < 10; ++i) {
        void* ptr = malloc(MEM_SIZE); // allecating memory
        memset(ptr, 0, MEM_SIZE); // filling by zeros

        sleep(1);
    }

    return 0;
}