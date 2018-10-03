#include <stdio.h>
#include <stdlib.h>

int * init_malloc(size_t size) {
    int *arr = malloc(size * sizeof(int));
    printf("Memory was allocated\n");
    for (int i = 0; i < size; ++i) {
        arr[i] = i;
    }
    printf("Allocated space was initialized\n");

    return arr;
}

int main() {
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    int *arr = init_malloc(n); // allocation and initialization of array

    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr); // dealocating memory
    printf("Memory was freed up\n");

    return 0;
}