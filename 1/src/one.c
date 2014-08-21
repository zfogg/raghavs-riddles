#include <stdlib.h>
#include <stdio.h>

#include "one.h"


int randRange(int min, int max) {
    int diff = max - min;
    return (int) (((double)(diff+1)/RAND_MAX) * rand() + min);
}


int partition(int* list, int left, int right, int pivotIndex) {
    int tmp;
    #define SWAP(a, b) { tmp = list[a]; list[a] = list[b]; list[b] = tmp; }
    int pivotValue = list[pivotIndex];
    SWAP(pivotIndex, right);
    int storeIndex = left;
    for (int i = left; i < right; i++) {
        if (list[i] < pivotValue) {
            SWAP(storeIndex, i);
            storeIndex++;
        }
    }
    SWAP(right, storeIndex);
    return storeIndex;
}


int select(int* list, int left, int right, int n) {
    if (left == right)
        return list[left];
    while (1) {
        int pivotIndex = partition(list, left, right, randRange(left, right));
        if (n == pivotIndex) {
            return list[n];
        } else if (n < pivotIndex) {
            right = pivotIndex - 1;
        } else {
            left = pivotIndex;
        }
    }
}


int median(int* list, int size) {
    return select(list, 0, size, size / 2);
}

