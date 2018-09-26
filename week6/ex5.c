#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>

#define True 1

int main() {
    pid_t p;
    p = fork();

    if (p < 0) {
        fprintf(stderr, "Fork Failed\n");
        return 1;
    }
    else if (p == 0) { // child process
        printf("#Child process(%d) is created#\n", getpid());
        printf("Parent's id is (%d)\n", getppid());
        while (True) {
            printf("I'm alive ...\n");
            sleep(1);
        }
        exit(0);
    }
    else { // parent process
        sleep(10);
        printf("Parent process(%d)\nSending signall SIGTERM to the child(%d)\n", getpid(), p);
        kill(p, SIGTERM);
    }

    return 0;
}