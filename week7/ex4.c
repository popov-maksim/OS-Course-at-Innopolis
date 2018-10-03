#include <stdio.h>
#include <stdlib.h>

void *my_realloc(void *ptr, size_t size) {
    if (!ptr && size != 0) {
        ptr = malloc(size);
    }
    else if (size == 0) {
        free(ptr);
    }
    else {
        void *new = malloc(size);
        for (int i = 0; i < size; ++i) {
            *((char*)new + i) = *((char *)ptr + i);
        }
        free(ptr);
        ptr = new;
    }

    return ptr;
}

int main() {

    // example
    int *ex1 = my_realloc(NULL, 10 * sizeof(int));
    for (int i = 0; i < 10; ++i) {
        ex1[i] = i;
        printf("%d ", ex1[i]);
    }
    printf("\n");

    ex1 = my_realloc(ex1, 5 * sizeof(int)); // there should be old values
    for (int i = 0; i < 5; ++i) {
        printf("%d ", ex1[i]);
    }
    printf("\n");

    ex1 = my_realloc(ex1, 10 * sizeof(int)); // there should be old values and rubbish
    for (int i = 0; i < 10; ++i) {
        printf("%d ", ex1[i]);
    }
    printf("\n");

    free(ex1);

    return 0;
}