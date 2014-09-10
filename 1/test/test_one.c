#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "../src/one.h"

#include "test_one.h"


void shuffle(int *list, size_t size) {
    if (size > 1)
        for (size_t i = 0; i < size - 1; i++) {
            size_t j = i + rand() / (RAND_MAX / (size - i) + 1);
            int t = list[j];
            list[j] = list[i];
            list[i] = t;
        }
}


int main(int argc, const char* argv[]) {
    srand(time(NULL));
    int size = sizeof list / sizeof list[0];

    shuffle(list, size);

    printf("\nknown median: %d", median(list, size));

    printf("\nlist: [");
    for (int i = 0; i < size; i++)
        printf("%d%s", list[i], i < size - 1 ? ", " : "");
    printf("]");

    printf("\nfound median: %d", median(list, size));

    printf("\n\n");
    return 0;
}

