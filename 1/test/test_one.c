#include <stdlib.h>
#include <stdio.h>

#include "../src/one.h"

#include "test_one.h"


int main(int argc, const char* argv[]) {
    printf("\n");
    printf("median: %d", median(list, sizeof(list) / sizeof(int)));
    printf("\n");
    return 0;
}


