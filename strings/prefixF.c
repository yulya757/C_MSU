#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *
prefix(const char *s) {
    int n = strlen(s);
    int *res = (int*)calloc(n, sizeof(*res));
    
    for (int i = 1; i < n; ++i) {
        int cand = res[i - 1];
        while (cand > 0 && s[i] != s[cand]) {
            cand = res[cand - 1];
        }
        if (s[i] == s[cand]) {
            ++cand;
        }
        res[i] = cand;
    }
    
    return res;
}

int
main(void) {
    int n;
    scanf("%d", &n);
    getchar();
    char *s = (char*)calloc(n + 2, sizeof(*s));
    fgets(s, n + 1, stdin);
    int *arr = prefix(s);
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");
    free(s);
    free(arr);
    return 0;
}