#include <stdio.h>

int
main(void) {
    int n;
    scanf("%d", &n);
    int ids[n];
    int scores[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &ids[i], &scores[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            int need_swap = 0;

            if (scores[j] < scores[j + 1]) {
                need_swap = 1;
            } else if (scores[j] == scores[j + 1] && ids[j] > ids[j + 1]) {
                need_swap = 1;
            }

            if (need_swap) {
                int t_id = ids[j];
                ids[j] = ids[j + 1];
                ids[j + 1] = t_id;

                int t_score = scores[j];
                scores[j] = scores[j + 1];
                scores[j + 1] = t_score;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d %d\n", ids[i], scores[i]);
    }

    return 0;
}