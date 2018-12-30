#ifndef __TEST_VERIFY_H__
#define __TEST_VERIFY_H__

#include <stdio.h>
#include <stdlib.h>

#include "common.h"


#define VERIFY(x, y)   \
    if (x != y) {  \
        printf("[%s:%d] TEST FAILURE: compare %d and %d\n", __FILE__, __LINE__, x, y); \
        exit(EXIT_FAILURE); \
    }

#endif // __TEST_VERIFY_H__
