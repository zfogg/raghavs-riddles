#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "../src/one.h"

#include "test_one.h"


int main(int argc, const char* argv[]) {
    srand(time(NULL));
    printf("\n");
    printf("median: %d\n", median(list, 19));
    return 0;
}


