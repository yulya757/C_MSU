#include <stdio.h>

int
main(void) {
    int n;
    scanf("%d", &n);
    long long arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }
    for (int i = n - 1; i > 0; i--) {
        int max_index = 0;
        for (int j = 1; j <= i; j++) {
            if (arr[j] > arr[max_index]) {
                max_index = j;
            }
        }
        long long t = arr[i];
        arr[i] = arr[max_index];
        arr[max_index] = t;
    }
    for (int i = 0; i < n; i++) {
        printf("%lld ", arr[i]);
    }
    printf("\n");
    return 0;
}