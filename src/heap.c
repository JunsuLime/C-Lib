#include <stdlib.h>

#include "arraylist.h"
#include "heap.h"

void __heap_init(heap *heap, int (*compare)(void *e1, void *e2)) {
    arraylist_op.init(&heap->list);
    heap->compare = compare;
}

void __heap_push(heap *heap, void *e) {

}

void *__heap_pop(heap *heap) {
    return NULL;
}

void __heap_clear(heap *heap) {
    arraylist_op.clear(&heap->list);
}

int __heap_empty(heap *heap) {
    return arraylist_op.empty(&heap->list);
}

void __heap_free(heap *heap) {
    arraylist_op.free(&heap->list);
}

void __heap_free_foreach(heap *heap, void (*func)(void *e)) {
    arraylist_op.foreach(&heap->list, func);
    __heap_free(heap);
}

const struct __heap_op heap_op = {
    .init = __heap_init,
    .push = __heap_push,
    .pop = __heap_pop,
    .clear = __heap_clear,
    .empty = __heap_empty,
    .free = __heap_free,
    .free_foreach = __heap_free_foreach,
};
