#include <stdio.h>
#include <errno.h>
#include "vector.h"

int
main(void) {
    Vector v = vector_init(1);
    int cur, err;
    err = scanf("%d", &cur);
    if (err != 1) {
        perror("Too few arguments for scanf\n");
        exit(1);
    }
    while (cur != 0) {
        err = vector_push_back(&v, cur);
        if (err) {
            errno = err;
            perror(NULL);
            exit(1);
        }
        err = scanf("%d", &cur);
        if (err != 1) {
            perror("Too few arguments for scanf\n");
            exit(1);
        }
    }
    err = vector_resize(&v, 0);
    if (err) {
        errno = err;
        perror(NULL);
        exit(1);
    }

    Vector sorted = vector_init(1);
    vector_resize(&sorted, v.size);
    for (int i = 0; i < v.size; ++i) {
        int flag = 0;
        for (int j = 0; j < i; ++j) {
            if (vector_get(&sorted, j) > vector_get(&v, i)) {
                vector_insert(&sorted, j, vector_get(&v, i));
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            vector_push_back(&sorted, vector_get(&v, i));
        }
    }
    printf("%d\n", vector_get(&sorted, v.size / 2));
    vector_destroy(&v);
    vector_destroy(&sorted);
    return 0;
}
