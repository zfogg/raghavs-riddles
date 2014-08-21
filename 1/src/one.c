#include <stdlib.h>
#include <stdio.h>

#include "one.h"


int partition(int* list, int left, int right, int pivotIndex) {
    int pivotValue = list[pivotIndex];
    int temp = list[right];
    list[right] = list[pivotIndex];
    list[pivotIndex] = temp;
    int storeIndex = left;
    for (int i = left; i < right; i++) {
        if (list[i] < pivotValue) {
            temp = list[i];
            list[i] = list[storeIndex];
            list[storeIndex] = temp;
            storeIndex++;
        }
    }
    temp = list[storeIndex];
    list[storeIndex] = list[right];
    list[right] = temp;
    return storeIndex;
}


int select(int* list, int left, int right, int n) { if (left == right) return list[left];
    while (1) {
        int pivotIndex = right / 2 - left / 2;
        pivotIndex = partition(list, left, right, pivotIndex);
        if (n == pivotIndex)
            return list[n];
        else if (n < pivotIndex)
            right = pivotIndex - 1;
        else
            left = pivotIndex - 1;
    }
    return 0;
}


int median(int* list, int size) {
    return select(list, 0, size, size / 2);
}

