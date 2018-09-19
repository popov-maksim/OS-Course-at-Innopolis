#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PLACEHOLDER ">"
#define MAX 100
#define MAX_PARAMS 10

void processStr(char **cmd, char *params[], char *str) {
    // geting command
    *cmd = strtok(str, " ");
    
    // geting params
    char *param;
    int i = 1;
    while ((param = strtok(NULL, " &\n")) && i < MAX_PARAMS) {
        params[i] = param;
        ++i;
    }
    params[i] = NULL;
}

int main() {
    printf("Welcome to maxSH\nTo exit use Ctrl-C\n");

    // main cycle
    while (1) {
        printf(PLACEHOLDER);

        // getting and processing string, result is cmd and params
        char str[MAX];
        char *cmd;
        char * params[MAX_PARAMS];
        int isBackGr;
        fgets(str, 100, stdin);
        strchr(str, '&') ? isBackGr = 1 : 0;
        processStr(&cmd, params, str);
        params[0] = cmd;

        // execution of a command
        if (isBackGr) { // process in background
            pid_t pid = fork();
            if (pid == 0) { // child process
                printf("%s", cmd);
                execvp(cmd, params);
                perror("Error: ");
                printf("\n");
                exit(0);
            }
        }
        else {
            printf("%s", cmd);
            execvp(cmd, params);
            perror("Error: ");
            printf("\n");
        }
    }

    return 0;
}