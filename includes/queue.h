#ifndef __QUEUE_H__
#define __QUEUE_H__

struct __node {
    struct __node *next;
    void *element;
};

typedef struct __node __node;

struct __queue {
    __node *head;
    __node *tail;
    int length;
};

typedef struct __queue queue;

struct __queue_op {
    void (*init)(queue *queue);
    void (*enqueue)(queue *queue, void *e);
    void *(*dequeue)(queue *queue);
    int (*length)(queue *queue);
    int (*empty)(queue *queue);
    void (*clear)(queue *queue);
    void (*free)(queue *queue);
    void (*free_foreach)(queue *queue, void (*func)(void *e));
};

typedef struct __queue_op __queue_op;

extern const __queue_op queue_op;

#endif // __QUEUE_H__
