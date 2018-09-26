#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#define True 1

void handler(int);

int main() {
    signal(SIGKILL, handler);
    signal(SIGSTOP, handler);
    signal(SIGUSR1, handler);

    while (True) {
        sleep(1);
    }

    return 0;
}

void handler(int signum) {
    printf("Caught %d", signum);
    if (signum == SIGKILL) {
        printf(" - SIGKILL\n");
    }
    else if (signum == SIGUSR1) {
        printf(" - SIGUSR1\n");
    }
    else if (signum == SIGSTOP) {
        printf(" - SIGSTOP\n");
    }
    exit(0);
}