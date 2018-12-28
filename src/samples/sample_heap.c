#include "heap.h"
#include "test/verify.h"

#define DUMMY_SIZE 1024

void test_push_and_pop_and_empty(heap *heap) {
    int i;
    int array[DUMMY_SIZE];
    
    for (i = 0; i < DUMMY_SIZE; i++) {
        array[i] = DUMMY_SIZE - 1 - i;
    }

    for (i = 0; i < DUMMY_SIZE; i++) {
        heap_op.push(heap, &array[i]);
    }

    VERIFY(heap_op.empty(heap), FALSE);

    for (i = 0; i < DUMMY_SIZE; i++) {
        VERIFY(*(int*)heap_op.pop(heap), i);
    }

    VERIFY(heap_op.empty(heap), TRUE);
}

int compare(void *e1, void *e2) {

}

int main() {
    heap heap;
    heap_op.init(&heap, compare);

    test_push_and_pop_and_empty(&heap);

    heap_op.free(&heap);

    return 0;
}
