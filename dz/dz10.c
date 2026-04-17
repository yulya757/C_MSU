#include <stdio.h>
#include <stdlib.h>

int
main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    int **arr = calloc(n, sizeof(*arr));
    for (int i = 0; i < n; i++) {
        arr[i] = calloc(m, sizeof(int));
    }
    int num = 0;
    for (int d = 0; d < n + m - 1; d++) {
        int start_j = (d < m) ? d : m - 1;
        int start_i = d - start_j;
        for (int i = start_i, j = start_j; i < n && j >= 0; i++, j--) {
            arr[i][j] = num++;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%3d", arr[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);
    return 0;
}