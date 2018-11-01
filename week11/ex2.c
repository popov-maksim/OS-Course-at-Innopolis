#include <stdio.h>
#include <unistd.h>

int main() {
    int buf_size = 6;
    setvbuf(stdout, NULL, _IOLBF, buf_size);

    sleep(1);    
    printf("H");
    sleep(1);
    printf("e");
    sleep(1);
    printf("l");
    sleep(1);
    printf("l");
    sleep(1);
    printf("o\n");

    return 0;
}