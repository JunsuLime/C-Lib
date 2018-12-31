#include "queue.h"
#include "common.h"
#include "test/verify.h"

#define DUMMY_SIZE 1024

void test_length_empty_and_clear(queue *queue) {
    int e = 1;

    queue_op.enqueue(queue, &e);
    VERIFY(queue_op.length(queue), 1);

    queue_op.dequeue(queue);
    VERIFY(queue_op.length(queue), 0);
    VERIFY(queue_op.empty(queue), TRUE);
}

void test_enqueue_and_dequeue(queue *queue) {
    int i;
    int array[DUMMY_SIZE];

    for (i = 0; i < DUMMY_SIZE; i++) {
        array[i] = i;
        queue_op.enqueue(queue, &array[i]);
    }

    for (i = 0; i < DUMMY_SIZE; i++) {
        VERIFY(*(int*)queue_op.dequeue(queue), array[i]);
    }
}

int main() {
    queue queue;
    queue_op.init(&queue);

    test_length_empty_and_clear(&queue);
    test_enqueue_and_dequeue(&queue);

    queue_op.free(&queue);

    return 0;
}
