#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define STRING_TO_WRITE "This is a nice day\0"

int main() {
    int fd = open("ex1.txt", O_RDWR);
    char *string = STRING_TO_WRITE;

    struct stat file_stat;
    stat("ex1.txt", &file_stat);

    char *file_addr = mmap(NULL, file_stat.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    memcpy(file_addr, string, strlen(string));
    msync(file_addr, strlen(string), MS_SYNC);
    munmap(file_addr, file_stat.st_size);

    printf("Done!\n");
    close(fd);

    return 0;
}