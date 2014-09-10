#ifndef ONE_H
#define ONE_H


#ifndef SWAP
#define SWAP(a, b) \
    do { \
        int t = a; \
        a = b; \
        b = t; \
    } while (0);
#endif


static int partition(int* list, int left, int right, int pivotIndex);

static int select(int* list, int left, int right, int n);


int randBetween(int min, int max);

int median(int* list, int size);


#endif /* ONE_H */

