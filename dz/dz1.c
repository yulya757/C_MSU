#include <stdio.h>

int
main(void) {
    int n;
    scanf("%d", &n);
    printf("The next number for the number %d is %d.\n", n, n + 1);
    printf("The previous number for the number %d is %d.\n", n, n - 1);
    return 0;
}