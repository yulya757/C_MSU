#include <stdio.h>

int
main(void) {
    double x, y;
    const double EPS = 1e-7;
    scanf("%lf %lf", &x, &y);
    double total = x;
    double current = x;
    int days = 1;
    while (total < y - EPS) {
        current *= 1.7;
        total += current;
        days++;
    }
    printf("%d\n", days);
    return 0;
}