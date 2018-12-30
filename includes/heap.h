#ifndef __HEAP_H__
#define __HEAP_H__

#include "arraylist.h"

#define PARENT_IDX(c) (c - 1) / 2
#define L_CHILD_IDX(p) 2 * p + 1
#define R_CHILD_IDX(p) 2 * p + 2

struct __heap {
    arraylist list;
    int (*compare)(void *e1, void *e2);
};

typedef struct __heap heap;

struct __heap_op {
    void (*init)(heap *heap, int (*compare)(void *e1, void *e2));
    void (*push)(heap *heap, void *e);
    void *(*pop)(heap *heap);
    void (*clear)(heap *heap);
    int (*empty)(heap *heap);
    void (*free)(heap *heap);
    void (*free_foreach)(heap *heap, void (*func)(void *e));
};

typedef struct __heap_op __heap_op;

extern const __heap_op heap_op;

#endif // __HEAP_H__
