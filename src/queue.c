#include "queue.h"
#include "common.h"
#include <stdlib.h>

static struct bundle *new_bundle() {
    struct bundle *bundle = (struct bundle *)malloc(sizeof(struct bundle));
    bundle->head = 0;
    bundle->tail = 0;
    bundle->next = NULL;

    return bundle;
}

static void free_bundle(struct bundle *bundle) {
    free(bundle);
}

struct queue *__instance() {
    struct queue *queue = (struct queue *)malloc(sizeof(struct queue));
    queue->head = new_bundle();
    queue->tail = queue->head;

    return queue;
}

void __enqueue(struct queue *queue, void *element) {
    struct bundle *tail_bundle = queue->tail;
    if (tail_bundle->tail != BUNDLE_SIZE) {
        tail_bundle->array[tail_bundle->tail++] = element;
        return;
    }

    queue->tail = new_bundle();
    tail_bundle->next = queue->tail;
    tail_bundle = tail_bundle->next;
    tail_bundle->array[tail_bundle->tail++] = element;
}

void *__dequeue(struct queue *queue) {
    struct bundle *head_bundle = queue->head;

    void *data = head_bundle->array[head_bundle->head++];
    if (head_bundle->head == BUNDLE_SIZE) {
        if (queue->head == queue->tail) {
            head_bundle->head = 0;
            head_bundle->tail = 0;
        } else {
            queue->head = head_bundle->next;
            free_bundle(head_bundle);
        }
    }
    return data;
}

int __empty(struct queue *queue) {
    return queue->head == queue->tail && queue->head->head == queue->head->tail;
}

void __foreach(struct queue *queue, void (*function)(void *data)) {
    int i;
    struct bundle *current = queue->head;

    while (current) {
        for (i = current->head; i < current->tail; i++) {
            function(current->array[i]);
        }
        current = current->next;
    }
}

void __free(struct queue *queue) {
    struct bundle *current = queue->head;
    struct bundle *next;

    while (current) {
        next = current->next;
        free(current);
        current = next;
    }
}

void __free_with_items(struct queue *queue) {
    int i;
    struct bundle *current = queue->head;
    struct bundle *next;

    while (current) {
        next = current->next;
        for (i = current->head; i < current->tail; i++) {
            free(current->array[i]);
        }
        free(current);
        current = next;
    }
}

const struct queueop queueop = {
    .instance = __instance,
    .enqueue = __enqueue,
    .dequeue = __dequeue,
    .empty = __empty,
    .foreach = __foreach,
    .free = __free,
    .free_with_items = __free_with_items,
};
