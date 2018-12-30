#include <stdlib.h>

#include "arraylist.h"
#include "heap.h"
#include "common.h"

void __heap_init(heap *heap, int (*compare)(void *e1, void *e2)) {
    arraylist_op.init(&heap->list);
    heap->compare = compare;
}

void __heap_push(heap *heap, void *e) {
    arraylist *list = &heap->list;
    int parent_idx, child_idx;
    
    arraylist_op.append(list, e);

    child_idx = list->length - 1;
    parent_idx = PARENT_IDX(child_idx);
   
    while (heap->compare(
                arraylist_op.get(list, child_idx), 
                arraylist_op.get(list, parent_idx)) == ASCENDING) {
        arraylist_op.swap(list, child_idx, parent_idx);

        parent_idx = PARENT_IDX(parent_idx);
        child_idx = PARENT_IDX(child_idx);
    }
}

void *__heap_pop(heap *heap) {
    arraylist *list = &heap->list;

    void *e;
    void *l_val, *r_val, *p_val;
    int parent_idx, l_child_idx, r_child_idx;

    arraylist_op.swap(list, 0, list->length - 1);
    e = arraylist_op.pop(&heap->list);

    parent_idx = 0;
    l_child_idx = L_CHILD_IDX(parent_idx);
    r_child_idx = R_CHILD_IDX(parent_idx);

    while (TRUE) {
        if (l_child_idx < list->length && r_child_idx < list->length) {
            l_val = arraylist_op.get(list, l_child_idx);
            r_val = arraylist_op.get(list, r_child_idx);
            p_val = arraylist_op.get(list, parent_idx);
            
            if (heap->compare(p_val, l_val) != DESCENDING && 
                    heap->compare(p_val, r_val) != DESCENDING) {
                break;  // stable;
            }
            else if (heap->compare(l_val, r_val) == ASCENDING) {
                arraylist_op.swap(list, l_child_idx, parent_idx);
                parent_idx = l_child_idx;
            }
            else {
                arraylist_op.swap(list, r_child_idx, parent_idx);
                parent_idx = r_child_idx;
            }
        }

        else if (l_child_idx < list->length) {
            if (heap->compare(
                        arraylist_op.get(list, l_child_idx),
                        arraylist_op.get(list, parent_idx)) == ASCENDING) {
                arraylist_op.swap(list, l_child_idx, parent_idx);
                parent_idx = l_child_idx;
            }
            else {
                break;  // stable;
            }
        }

        else if (r_child_idx < list->length) {
            if (heap->compare(
                        arraylist_op.get(list, r_child_idx),
                        arraylist_op.get(list, parent_idx)) == ASCENDING) {
                arraylist_op.swap(list, r_child_idx, parent_idx);
                parent_idx = r_child_idx;
            }
            else {
                break;  // stable;
            }
        }
        else {
            break;  // Leaf node
        }

        l_child_idx = L_CHILD_IDX(parent_idx);
        r_child_idx = R_CHILD_IDX(parent_idx);
    }

    return e;
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
