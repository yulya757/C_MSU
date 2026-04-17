#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *
prefix(const char *s, int n) {
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
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    getchar();
    char *s1 = calloc(n1 + 2, sizeof(*s1));
    fgets(s1, n1 + 1, stdin);
    getchar();
    char *s2 = calloc(n2 + 2, sizeof(*s2));
    fgets(s2, n2 + 1, stdin);
    char *s = calloc(n1 + n2 + 2, sizeof(*s));
    strcpy(s, s1);
    s[n1] = '\0';
    strcpy(s + n1 + 1, s2);
    int n = n1 + n2 + 1;
    int *arr = prefix(s, n);
    for (int i = n1; i < n; ++i) {
        if (arr[i] == n1) {
            printf("%d", i - 2 * n1);
            return 0;
        }
    }
    printf("NO");
    free(s1);
    free(s2);
    free(s);
    free(arr);
    return 0;
}