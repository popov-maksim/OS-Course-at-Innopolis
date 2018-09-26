#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>

int main() {
    int fd[2];

    char s1[] = "Hi, Maxim!\n";
    char s2[20];

    if (pipe(fd) == -1) {
        fprintf(stderr, "Pipe Failed\n");
    }

    pid_t p = fork();

    if (p < 0) {
        fprintf(stderr, "Fork Failed\n");
    }
    else if (p == 0) { // child process
        close(fd[1]); // close write end

        read(fd[0], s2, 20);
        printf("%s", s2);

        close(fd[0]); // close read end

        exit(0);
    }
    else { // parent process
        close(fd[0]); // close read end

        write(fd[1], s1, strlen(s1) + 1);

        close(fd[1]); // close write end
    }

    // expected to see "Hi, Maxim!" on the screen
    return 0;
}