#ifndef __STACK_H__
#define __STACK_H__

#define INIT_STACK_SIZE 16

struct stack {
    void **array;
    int length;
    int array_size;
};

struct stackop {
    struct stack *(*instance)();
    void (*push)(struct stack *stack, void *element);
    void *(*pop)(struct stack *stack);
    int (*empty)(struct stack *stack);
    void (*foreach)(struct stack *stack, void (*function)(void *data));
    void (*free)(struct stack *stack);
    void (*free_with_items)(struct stack *stack);
};

extern const struct stackop stackop;

#endif  // __STACK_H__
