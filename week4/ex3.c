#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Welcome to maxSH\nTo exit use Ctrl-C\n");
    while (1) {
        printf(">");
        char cmd[100];
        fgets(cmd, 100, stdin);
        int i;
        for (i = 0; i < strlen(cmd) && cmd[i] != ' '; ++i) {}
        cmd[i] = '\0';
        int status = system(cmd);
        if (status) {
            printf("Wrong command!\n");
        }
        printf("\n");
    }

    return 0;
}