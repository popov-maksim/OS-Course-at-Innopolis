#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    // for our pipe
    // fd[0] - read end
    // fd[1] - write end
    int fd[2];

    char s1[] = "Hello, Maxim!\n";
    char s2[20];

    if (pipe(fd) == -1) {
        fprintf(stderr, "Pipe Failed");
        return 1;
    }

    // write s1 to the pipe
    write(fd[1], s1, strlen(s1) + 1);

    // read s1 to s2 from the pipe
    read(fd[0], s2, 20);

    close(fd[0]); // close read end
    close(fd[1]); // close write end

    // show the result on the screen
    printf("%s", s2);
    // "Hello, Maxim!" is expected to shown on the screen

    return 0;
}