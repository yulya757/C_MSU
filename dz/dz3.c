#include <stdio.h>

int
main(void) {
    int x, p, y;
    scanf("%d%d%d", &x, &p, &y);
    int year = 0;
    int cur = 100 * x;
    y *= 100;
    while (cur < y) {
        year++;
        cur = (int)(cur * (1 + p / 100.0));
    }
    printf("%d\n", year);
    return 0;
}