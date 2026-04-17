#include <stdio.h>
#include <stdlib.h>

int
main(void) {
    int n, k;
    scanf("%d %d", &n, &k);

    int *arr = calloc(n, sizeof(int));
    int *l = calloc(n, sizeof(int));
    int *r = calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++) {
        if (i % k == 0) {
            l[i] = arr[i];
        } else {
            l[i] = (arr[i] < l[i - 1]) ? arr[i] : l[i - 1];
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        if (i == n - 1 || (i + 1) % k == 0) {
            r[i] = arr[i];
        } else {
            r[i] = (arr[i] < r[i + 1]) ? arr[i] : r[i + 1];
        }
    }

    for (int i = 0; i <= n - k; i++) {
        int j = i + k - 1;
        if (i / k == j / k) {
            printf("%d\n", l[j]);
        } else {
            int m1 = r[i];
            int m2 = l[j];
            printf("%d\n", (m1 < m2) ? m1 : m2);
        }
    }

    free(arr);
    free(l);
    free(r);
    return 0;
}