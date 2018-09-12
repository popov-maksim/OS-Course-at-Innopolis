#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PLACEHOLDER ">"
#define MAX 100

void getCommand(char cmd[], char str[]) {
    int i;
    for (i = 0; i < strlen(str) && str[i] != ' '; ++i) {
        cmd[i] = str[i];
    }
    cmd[i] = '\0';
}

void getParams(char *params[], char str[], int startInd) {
    for (int i = startInd, s = 1, col = 0; i < strlen(str); ++i) {
        if (str[i] == ' ') {
            params[col] = 0;
            col = 0;
            s++;
        }
        else {
            params[s][col] = str[i];
            col++;
        }
    }
}

void processStr(char cmd[], char *params[], char str[]) {
    getCommand(cmd, str);
    if (strchr(str, ' ')) {
        getParams(params, str, strchr(str, ' ') - str + 1);
    }
}

int main() {
    // env variables for child process
    char *env = {NULL};

    printf("Welcome to maxSH\nTo exit use Ctrl-C\n");

    // main cycle
    while (1) {
        printf(PLACEHOLDER);

        // getting and processing string, result is cmd and params
        char str[MAX], cmd[MAX], params[MAX][MAX];
        // zeroing of all parameters
        for (int i = 0; i < MAX; ++i) {
            params[i][0] = 0;
        }
        fgets(str, 100, stdin);
        processStr(cmd, params, str);

        // execution of a command
        if (strchr(str, '&')) { // process in background
            pid_t pid = fork();
            if (pid == 0) { // child process
                execve(cmd, params, env);
                printf("\n");
                break;
            }
        }
        else {
            int status = system(cmd);
            if (status) {
                printf("Wrong command!");
            }
            printf("\n");
        }
    }

    return 0;
}