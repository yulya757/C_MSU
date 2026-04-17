#include <stdio.h>

int
main(void) {
    int n;
    scanf("%d", &n);
    long long arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }
    for (int i = 1; i < n; i++) {
        long long current = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > current) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }
    for (int i = 0; i < n; i++) {
        printf("%lld ", arr[i]);
    }
    printf("\n");
    return 0;
}