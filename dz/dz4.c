#include <stdio.h>
#include <math.h>

int
main(void) {
    int x;
    scanf("%d", &x);
    int reversed = 0;
    while (x > 0) {
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }
    printf("%d\n", reversed);
    return 0;
}