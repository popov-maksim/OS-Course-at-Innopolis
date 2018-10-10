#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

#define MEM_SIZE 10 * 1024 * 1024

int main() {
    for (int i = 0; i < 10; ++i) {
        void* ptr = malloc(MEM_SIZE); // allecating memory
        memset(ptr, 0, MEM_SIZE); // filling by zeros
        struct rusage *usage = malloc(sizeof(struct rusage));
        getrusage(RUSAGE_SELF, usage);
        printf("%ld KB\n", usage->ru_maxrss);

        sleep(1);
    }

    return 0;
}