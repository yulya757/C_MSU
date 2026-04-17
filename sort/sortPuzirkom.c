#include <stdio.h>

int
main(void) {
    int n;
    scanf("%d", &n);
    long long arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }
    for (int i = n; i > 1; i--) {
        for (int j = 0; j < i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                long long temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%lld ", arr[i]);
    }
    printf("\n");
    return 0;
}