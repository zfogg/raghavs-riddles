#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../src/one.h"

#include "test_one.h"


static void shuffle(int *list, int size) {
    if (size > 1)
        for (int i = 0; i < size * 2; i++) {
            int j1 = randBetween(0, size), j2;
            do
                j2 = randBetween(0, size);
            while (j2 == j1);
            SWAP(list[j1], list[j2]);
        }
}


int main(int argc, const char* argv[]) {
    srand(time(NULL));
    int size = sizeof list / sizeof list[0];

    shuffle(list, size);

    printf("\nlist size: %d", size);
    printf("\nlist: [");
    for (int i = 0; i < size; i++)
        printf("%d%s", list[i], i < size - 1 ? ", " : "");
    printf("]");

    printf("\nknown median: %d", 3);
    printf("\nfound median: %d", median(list, size));

    printf("\n\n");
    return 0;
}

