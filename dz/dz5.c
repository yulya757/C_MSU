#include <stdio.h>

int
main(void) {
    int n;
    scanf("%d", &n);
    long long arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }
    for (int i = 0; i < n; i++) {
        printf("%lld ", arr[i]);
    }
    printf("\n");
    return 0;
}