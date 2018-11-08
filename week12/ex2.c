#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define NUM 20

int main(int argc, char **argv) {
    if (argc < 2) {
        exit(1);
    }

    char *first_argv = argv[1];

    char mode[1] = "w";
    int start = 1;
    if (strcmp(first_argv, "-a") == 0) {
        mode[0] = 'a';
        ++start;
    }

    FILE *out_files[NUM];
    int len = 0;
    for (int i = start; i < argc; ++i, ++len) { // open all files
        out_files[len] = fopen(argv[i], mode);
    }

    char buf;
    while (fscanf(stdin, "%c", &buf) != EOF) {
        printf("%c", buf);

        for (int i = 0; i < len; ++i) { // output to every file
            fwrite(&buf, 1, 1, out_files[i]);
        }
    }

    for (int i = 0; i < len; ++i) { // close every file
        fclose(out_files[i]);
    }

    return 0;
}