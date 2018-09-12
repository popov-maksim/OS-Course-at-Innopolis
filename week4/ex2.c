#include <stdio.h>
#include <unistd.h>

#define TIMES 3

int main() {
    for (int i = 0; i < TIMES; ++i) {
        fork();
    }
    sleep(5);

    return 0;
}