#include <stdlib.h>

#include "queue.h"

void __queue_init(queue *queue) {
    queue->head = (__node*)malloc(sizeof(__node));
    queue->tail = queue->head;

    queue->length = 0;
}

void __queue_init_node(__node *node, void *e) {
    node->element = e;
    node->next = NULL;
} 

void __queue_free_node(__node *node) {
    free(node);
}

void __queue_enqueue(queue *queue, void *e) {
    __node *new_node = (__node*)malloc(sizeof(__node));
    __queue_init_node(new_node, e);
    
    queue->tail->next = new_node;
    queue->tail = new_node;

    queue->length++;
}

void *__queue_dequeue(queue *queue) {
    __node *first = queue->head->next;
    queue->head->next = first->next;
    if (queue->tail == first) {
        queue->tail = queue->head;
    }

    void *e = first->element;
    __queue_free_node(first);

    queue->length--;
    return e;
}

int __queue_length(queue *queue) {
    return queue->length;
}

int __queue_empty(queue *queue) {
    return queue->length == 0;
}

void __queue_node_foreach(queue *queue, void (*func)(__node *node)) {
    __node *curr = queue->head->next;
    __node *next;

    while (curr) {
        next = curr->next;
        func(curr);
        curr = next;
    }
}

void __queue_clear(queue *queue) {
    __queue_node_foreach(queue, __queue_free_node);
    queue->head->next = NULL;
    queue->tail = queue->head;
    queue->length = 0;
}

void __queue_free(queue *queue) {
    __queue_clear(queue);
    __queue_free_node(queue->head);
}

void __queue_free_foreach(queue *queue, void (*func)(void *e)) {
    __node *curr = queue->head->next;
    __node *next;

    while (curr) {
        next = curr->next;
        free(curr->element);
        __queue_free_node(curr);
        curr = next;
    }
    __queue_free_node(queue->head);
}

const struct __queue_op queue_op = {
    .init = __queue_init,
    .enqueue = __queue_enqueue,
    .dequeue = __queue_dequeue,
    .length = __queue_length,
    .empty = __queue_empty,
    .clear = __queue_clear,
    .free = __queue_free,
    .free_foreach = __queue_free_foreach,
};
