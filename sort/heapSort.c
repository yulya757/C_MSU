#include <stdio.h>
#include <stdlib.h>

void
heapDown(int *arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }
    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }
    if (largest != i) {
        int tmp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = tmp;
        heapDown(arr, n, largest);
    }
}

void
heapSort(int *arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapDown(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        int t = arr[0];
        arr[0] = arr[i];
        arr[i] = t;

        heapDown(arr, i, 0);
    }
}

int
main(void) {
    int n;
    scanf("%d", &n);
    int *arr = calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    heapSort(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}