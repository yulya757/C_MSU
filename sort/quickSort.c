#include <stdio.h>
#include <stdlib.h>
void
quickSort(int *arr, int l, int r) {
    if (l >= r) {
        return;
    }
    int pivot = arr[r];
    int m = (l + r) / 2;
    int t = arr[r];
    arr[r] = arr[m];
    arr[m] = t;
    int i = l;
    int j = r;
    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    quickSort(arr, l, j);
    quickSort(arr, i, r);
}
int
main(void) {
    int n;
    scanf("%d", &n);
    int *arr = calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}
