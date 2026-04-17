#include <stdio.h>

int
main(void) {
    int n, k, max = 100000;
    scanf("%d%d", &n, &k);
    long long a[max];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int q = 0; q < k; q++) {
        long long x;
        scanf("%lld", &x);
        int l = 0, r = n - 1;
        while (r - l > 2) {
            int m1 = l + (r - l) / 3;
            int m2 = r - (r - l) / 3;
            long long diff1 = a[m1] - x;
            long long diff2 = a[m2] - x;
            if (diff1 < 0) {
                diff1 = -diff1;
            }
            if (diff2 < 0) {
                diff2 = -diff2;
            }
            if (diff1 > diff2) {
                l = m1;
            } else {
                r = m2;
            }
        }
        int best = l;
        for (int i = l + 1; i <= r; i++) {
            long long diff_i = a[i] - x;
            long long diff_best = a[best] - x;
            if (diff_i < 0) {
                diff_i = -diff_i;
            }
            if (diff_best < 0) {
                diff_best = -diff_best;
            }
            if (diff_i < diff_best || (diff_i == diff_best && a[i] < a[best])) {
                best = i;
            }
        }
        printf("%lld\n", a[best]);
    }
    return 0;
}