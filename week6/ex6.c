#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>

#define True 1

int main() {
    pid_t p1;
    int fd[2]; // for pipe

    if (pipe(fd) == -1) {
        fprintf(stderr, "Pipe Failed\n");
        return 1;
    }

    p1 = fork();

    if (p1 < 0) {
        fprintf(stderr, "Fork#1 Failed\n");
        return 1;
    }
    else if (p1 > 0) { // parent process
        printf("Parent process(-- %d --)\n", getpid());

        pid_t p2;
        p2 = fork();

        if (p2 < 0) {
            fprintf(stderr, "Fork#2 Failed\n");
            return 1;
        }
        else if (p2 == 0) { // child#2 process
            printf("Child#2(-- %d --) was created. My parent is -- %d --\n", getpid(), getppid());

            while (True) {
                printf("Child#2: I'm alive!\n");
                sleep(1);
            }

            exit(0);
        }
        else { // parent process
            // sending pid of child#2 to child#1
            close(fd[0]); // close read end
            write(fd[1], &p2, sizeof(p2));
            close(fd[1]); // close write end

            // waiting changing status in child#2
            int status;
            printf("Parent(-- %d --) is wating for child#2(-- %d --)\n", getpid(), p2);
            waitpid(p2, &status, 0);

            printf("Status of child#2 is %d\n", status);

            return 0;
        }
    }
    else { // child#1 process
        printf("Child#1(-- %d --) was created. My parent is -- %d --\n", getpid(), getppid());

        pid_t p2;

        // getting pid of child#2
        close(fd[1]); // close write end
        read(fd[0], &p2, sizeof(p2));
        close(fd[0]); // close read end

        printf("Child#1 has got pid of child#2 - (-- %d --)\n", p2);

        sleep(2);
        printf("Child#1: sending a signal to the child#2\n");
        kill(p2, SIGSTOP); // the parent process doesn't get anything
        //kill(p2, SIGKILL); // the parent process gets needed info

        exit(0);
    }
}