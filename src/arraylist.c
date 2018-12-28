#include <stdlib.h>

#include "arraylist.h"

void __arraylist_init(arraylist *list) {
    list->size = INIT_ARRAY_SIZE;
    list->array = (void **)malloc(sizeof(void*) * INIT_ARRAY_SIZE);
    list->length = 0;
}

void __arraylist_append(arraylist *list, void *e) {
    if (list->length == list->size) {
        list->size <<= 1;
        list->array = (void**)realloc(list->array, sizeof(void*) * list->size);
    }
    list->array[list->length++] = e;
}

void *__arraylist_pop(arraylist *list) {
    if (list->size != INIT_ARRAY_SIZE && list->length == list->size >> 2) {
        list->size >>= 1;
        list->array = (void**)realloc(list->array, sizeof(void*) * list->size);
    }
    return list->array[--list->length];
}

void *__arraylist_get(arraylist *list, int i) {
    return list->array[i];
}

void __arraylist_set(arraylist *list, int i, void *e) {
    list->array[i] = e;
}

void __arraylist_swap(arraylist *list, int i1, int i2) {
    void *tmp;
    tmp = list->array[i1];
    list->array[i1] = list->array[i2];
    list->array[i2] = tmp;
}

void __arraylist_clear(arraylist *list) {
    list->size = INIT_ARRAY_SIZE;
    list->array = (void*)realloc(list->array, sizeof(void*) * INIT_ARRAY_SIZE);
    list->length = 0;
}

int __arraylist_empty(arraylist *list) {
    return list->length == 0;
}

int __arraylist_length(arraylist *list) {
    return list->length;
}

void __arraylist_foreach(arraylist *list, void (*func)(void *e)) {
    int i;
    for (i = 0; i < list->length; i++) {
        func(list->array[i]);
    }
}

void __arraylist_free(arraylist *list) {
    free(list->array);
}

void __arraylist_free_foreach(arraylist *list, void (*func)(void *e)) {
   __arraylist_foreach(list, func);
   __arraylist_free(list);
}

void __arraylist_iterator(arraylist *list, arraylist_iter *iter) {
    iter->list = list;
    iter->index = 0;
}

int __arraylist_has_next(arraylist_iter *iter) {
    return iter->index != iter->list->length;
}

void *__arraylist_next(arraylist_iter *iter) {
    return iter->list->array[iter->index++];
}

const struct __arraylist_op arraylist_op = {
    .init = __arraylist_init,
    .append = __arraylist_append,
    .pop = __arraylist_pop,
    .get = __arraylist_get,
    .set = __arraylist_set,
    .swap = __arraylist_swap,
    .clear = __arraylist_clear,
    .empty = __arraylist_empty,
    .length = __arraylist_length,
    .foreach = __arraylist_foreach,
    .free = __arraylist_free,
    .free_foreach = __arraylist_free_foreach,

    .iterator = __arraylist_iterator,
    .has_next = __arraylist_has_next,
    .next = __arraylist_next,
};
