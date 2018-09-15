#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

void print_function(void* data) {
    printf("%d ,", *(int*)data);
}

#define ITERATION 512

int main() {

    struct queueop op = queueop;

    int i;

    int element1 = 1;
    int element2 = 2;

    int *array = (int*)malloc(sizeof(int)*ITERATION);
    for (i = 0; i < ITERATION; i++) {
        array[i] = i;
    }

    struct queue *queue = op.instance();

    printf("isempty: %d\n", op.empty(queue));

    // result: isempty: 1

    op.enqueue(queue, &element1);
    op.enqueue(queue, &element2);

    printf("isempty: %d\n", op.empty(queue));

    // result: isempty: 0

    printf("dequeue: %d\n", *(int*)op.dequeue(queue));
    printf("dequeue: %d\n", *(int*)op.dequeue(queue));

    // result:
    //  dequeue: 1
    //  dequeue: 2

    for (i = 0; i < ITERATION; i++) {
        op.enqueue(queue, &array[i]);
    }

    op.foreach(queue, print_function);
    printf("\n");

    // result: 0, 1, 2, 3, 4, ... 511

    for (i = 0; i < ITERATION; i++) {
        printf("%d ,", *(int*)op.dequeue(queue));
    }
    printf("\n");

    // result: 0, 1, 2, 3, 4, ... 511

    printf("isempty: %d\n", op.empty(queue));

    // result: isempty: 1

    op.free(queue);

    return 0;
}
