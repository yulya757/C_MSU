#include <stdio.h>

int
main(void) {
    long long M, N, x, y;
    scanf("%lld %lld %lld %lld", &M, &N, &x, &y);
    if (x > 1) {
        printf("%lld %lld\n", x - 1, y);
    }
    if (x < M) {
        printf("%lld %lld\n", x + 1, y);
    }
    if (y > 1) {
        printf("%lld %lld\n", x, y - 1);
    }
    if (y < N) {
        printf("%lld %lld\n", x, y + 1);
    }
    return 0;
}