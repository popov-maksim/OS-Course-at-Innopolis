#include <stdio.h>
#include <unistd.h>

int main() {
    int n = 10;
    int f = fork();
    if (f < 0) {
        printf("Error during fork!\n");
    }
    else if (f == 0) {
        printf("Hello from child [%d-%d]\n", getpid(), n);
    }
    else {
        printf("Hello from parent [%d-%d]\n", getpid(), n);
    }

    return 0;
}