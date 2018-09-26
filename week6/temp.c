#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    // fd[0] for using read end, fd[1] for using write end
    int fd1[2];
    int fd2[2];

    char str1[] = "Hello, World!\n";
    char str2[20];

    pid_t p;

    if (pipe(fd1) == -1) {
        fprintf(stderr, "Pipe#1 Failed");
        return 1;
    }
    if (pipe(fd2) == -1) {
        fprintf(stderr, "Pipe#2 Failed");
        return 1;
    }
    p = fork();

    if (p < 0) {
        fprintf(stderr, "Fork Failed");
        return 1;
    }
    else if (p == 0) { // child process
        close(fd1[1]); // close writing end
        close(fd2[0]); // close reading end 

        // get to str2 from parent
        read(fd1[0], str2, 20);
        // give str2 to parent
        write(fd2[1], str2, strlen(str2) + 1); 

        close(fd1[0]);
        close(fd2[1]);

        exit(0);
    }
    else { // parent process
        close(fd1[0]); // close reading end
        close(fd2[1]); // close writing end

        // give to child str1
        write(fd1[1], str1, strlen(str1) + 1);

        // wait for child to send a string
        wait(NULL);

        // get str2 from child and put it to str2
        read(fd2[0], str2, 20);
        // show the result on the screen
        printf("%s", str2);

        close(fd1[1]);
        close(fd2[0]);
    }

    // "Hello, World!" on the screen is expected
}