#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

#define TRUE 1

void handler_SIGINT(int signum) {
    printf("Caught signal %d, I'm going to quit\nBuy!\n", signum);
    exit(0);
}

int main() {
    signal(SIGINT, handler_SIGINT);
    while(TRUE) {
        printf("I'm thinking about good things ...\n");
        sleep(1);
    }
    return 0;
}