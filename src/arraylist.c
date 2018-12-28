#include <stdlib.h>

#include "arraylist.h"

void __init(arraylist *list) {
    list->size = INIT_ARRAY_SIZE;
    list->array = (void **)malloc(sizeof(void*) * INIT_ARRAY_SIZE);
    list->length = 0;
}

void __append(arraylist *list, void *e) {
    if (list->length == list->size) {
        list->size <<= 1;
        list->array = (void**)realloc(list->array, sizeof(void*) * list->size);
    }
    list->array[list->length++] = e;
}

void *__pop(arraylist *list) {
    if (list->size != INIT_ARRAY_SIZE && list->length == list->size >> 2) {
        list->size >>= 1;
        list->array = (void**)realloc(list->array, sizeof(void*) * list->size);
    }
    return list->array[--list->length];
}

void *__get(arraylist *list, int i) {
    return list->array[i];
}

void __clear(arraylist *list) {
    list->size = INIT_ARRAY_SIZE;
    list->array = (void*)realloc(list->array, sizeof(void*) * INIT_ARRAY_SIZE);
    list->length = 0;
}

int __empty(arraylist *list) {
    return list->length == 0;
}

int __length(arraylist *list) {
    return list->length;
}

void __foreach(arraylist *list, void (*func)(void *e)) {
    int i;
    for (i = 0; i < list->length; i++) {
        func(list->array[i]);
    }
}

void __free(arraylist *list) {
    free(list->array);
}

void __free_foreach(arraylist *list, void (*func)(void *e)) {
   __foreach(list, func);
   __free(list);
}

void __iterator(arraylist *list, arraylist_iter *iter) {
    iter->list = list;
    iter->index = 0;
}

int __has_next(arraylist_iter *iter) {
    return iter->index != iter->list->length;
}

void *__next(arraylist_iter *iter) {
    return iter->list->array[iter->index++];
}

const struct __arraylist_op arraylist_op = {
    .init = __init,
    .append = __append,
    .pop = __pop,
    .get = __get,
    .clear = __clear,
    .empty = __empty,
    .length = __length,
    .foreach = __foreach,
    .free = __free,
    .free_foreach = __free_foreach,

    .iterator = __iterator,
    .has_next = __has_next,
    .next = __next,
};
