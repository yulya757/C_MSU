#include <stdio.h>
#include <stdlib.h>

void
radixSort(int *arr, int n) {
    unsigned int *a = calloc(n, sizeof(unsigned int));
    unsigned int *b = calloc(n, sizeof(unsigned int));

    for (int i = 0; i < n; i++) {
        a[i] = (unsigned int)arr[i] ^ 0x80000000;
    }

    unsigned int *src = a;
    unsigned int *dst = b;

    for (int shift = 0; shift < 32; shift += 8) {
        int count[256] = {0};

        for (int i = 0; i < n; i++) {
            count[(src[i] >> shift) & 0xFF]++;
        }

        int pos[256];
        pos[0] = 0;

        for (int i = 1; i < 256; i++) {
            pos[i] = pos[i - 1] + count[i - 1];
        }

        for (int i = 0; i < n; i++) {
            dst[pos[(src[i] >> shift) & 0xFF]++] = src[i];
        }

        unsigned int *tmp = src;
        src = dst;
        dst = tmp;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = (int)(src[i] ^ 0x80000000);
    }

    free(a);
    free(b);
}

int
main(void) {
    int n;
    scanf("%d", &n);
    int *arr = calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    radixSort(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}