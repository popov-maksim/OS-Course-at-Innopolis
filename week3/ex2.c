#include <stdio.h>

#define MAX 1000

void swap(int* x, int* y) {
    *x = *x ^ *y;
    *y = *y ^ *x;
    *x = *y ^ *x;
}

void bubble_sort(int* a, int n) {
    char wasSwap = 1;
    while (wasSwap) {
        wasSwap = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (a[i + 1] < a[i]) {
                swap(a + i, a + i + 1);
                wasSwap = 1;
            }
        }
    }
}

int main() {
    int n;
    int arr[MAX];

    printf("Enter count of numbers: ");
    scanf("%d", &n);

    printf("Enter numbers\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", arr + i);
    }

    bubble_sort(arr, n);

    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
