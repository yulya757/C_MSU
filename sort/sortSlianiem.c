#include <stdio.h>
#include <stdlib.h>

void
merge(long long *arr, long long l, long long m, long long r) {
    long long n1 = m - l + 1;
    long long n2 = r - m;
    long long *l_arr = (long long *)calloc(n1, sizeof(long long));
    long long *r_arr = (long long *)calloc(n2, sizeof(long long));
    for (long long i = 0; i < n1; i++) {
        l_arr[i] = arr[l + i];
    }
    for (long long i = 0; i < n2; i++) {
        r_arr[i] = arr[m + 1 + i];
    }
    long long i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (l_arr[i] <= r_arr[j]) {
            arr[k] = l_arr[i];
            i++;
        } else {
            arr[k] = r_arr[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = l_arr[i];
        k++;
        i++;
    }
    while (j < n2) {
        arr[k] = r_arr[j];
        k++;
        j++;
    }
    free(l_arr);
    free(r_arr);
}
void
merge_sort(long long *arr, long long l, long long r) {
    if (l < r) {
        long long m = (r + l) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
int
main(void) {
    long long n;
    scanf("%lld", &n);
    long long *arr = (long long *)calloc(n, sizeof(long long));
    for (long long i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }
    merge_sort(arr, 0, n - 1);
    for (long long i = 0; i < n; i++) {
        printf("%lld ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}