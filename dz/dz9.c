#include <stdio.h>
#include <stdlib.h>
void
quickSort(long long *arr, int l, int r) {
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
remove_duplicates(long long *arr, int n) {
    if (n == 0) {
        return 0;
    }
    int j = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }
    return j + 1;
}

int
main(void) {
    int n1, n2;
    scanf("%d", &n1);
    long long *arr1 = calloc(n1, sizeof(long long));
    for (int i = 0; i < n1; i++) {
        scanf("%lld", &arr1[i]);
    }
    scanf("%d", &n2);
    long long *arr2 = calloc(n2, sizeof(long long));
    for (int i = 0; i < n2; i++) {
        scanf("%lld", &arr2[i]);
    }
    quickSort(arr1, 0, n1 - 1);
    quickSort(arr2, 0, n2 - 1);

    int unique1 = remove_duplicates(arr1, n1);
    int unique2 = remove_duplicates(arr2, n2);

    int similar = 1;

    if (unique1 != unique2) {
        similar = 0;
    } else {
        for (int i = 0; i < unique1; i++) {
            if (arr1[i] != arr2[i]) {
                similar = 0;
                break;
            }
        }
    }
    if (similar) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    free(arr1);
    free(arr2);
    return 0;
}