#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char *dir = "./tmp/";
    DIR* dirp = opendir(dir);
    if (dirp == NULL) {
        printf("Error. Could not open the directory");
        return -1;
    }

    struct dirent *dent;
    while ((dent = readdir(dirp)) != NULL) {
        char *name = dent->d_name;
        if (name[0] != '.') {
            struct stat st;
            char path[50];
            strcpy(path, dir);
            strcat(path, name);
            stat(path, &st);
            if (st.st_nlink > 1) {
                printf("File: %s - %d links\n", name, st.st_nlink);
                char cmd[100];
                strcpy(cmd, "find -L -samefile ");
                strcat(cmd, path);
                system(cmd);
            }
        }
    }

    return 0;
}