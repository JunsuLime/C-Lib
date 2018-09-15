#ifndef __QUEUE_H__
#define __QUEUE_H__

#define BUNDLE_SIZE 32

struct bundle {
    void *array[BUNDLE_SIZE];
    int head;
    int tail;
    struct bundle *next;
};

struct queue {
    struct bundle *head;
    struct bundle *tail;
};

struct queueop {
    struct queue *(*instance)();
    void (*enqueue)(struct queue *queue, void *element);
    void *(*dequeue)(struct queue *queue);
    int (*empty)(struct queue *queue);
    void (*foreach)(struct queue *queue, void (*function)(void *data));
    void (*free)(struct queue *queue);
    void (*free_with_items)(struct queue *queue);
};

extern const struct queueop queueop;

#endif  // __QUEUE_H__
