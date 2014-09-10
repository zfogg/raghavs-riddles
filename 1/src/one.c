#include <stdlib.h>
#include <stdio.h>

#include "one.h"


int randBetween(int min, int max) {
    int diff = max - min;
    return (int) (((double)(diff+1)/RAND_MAX) * rand() + min);
}


int partition(int* list, int left, int right, int pivotIndex) {
    int pivotValue = list[pivotIndex];
    int storeIndex = left;

    SWAP(list[pivotIndex], list[right]);

    for (int i = left; i < right; i++)
        if (list[i] < pivotValue) {
            SWAP(list[storeIndex], list[i]);
            storeIndex++;
        }

    SWAP(list[right], list[storeIndex]);
    return storeIndex;
}


int select(int* list, int left, int right, int n) {
    if (left == right)
        return list[left];

    while (1) {
        int randomIndex = randBetween(left, right),
            pivotIndex  = partition(list, left, right, randomIndex);
        if (n == pivotIndex)
            return list[n];
        else if (n < pivotIndex)
            right = pivotIndex - 1;
        else
            left = pivotIndex;
    }
}


int median(int* list, int size) {
    return select(list, 0, size, size / 2);
}

