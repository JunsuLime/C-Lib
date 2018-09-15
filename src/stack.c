#include "stack.h"
#include <stdlib.h>

struct stack *__instance() {
    struct stack *stack = (struct stack *)malloc(sizeof(struct stack *));
    stack->array = (void **)malloc(sizeof(void *) * INIT_STACK_SIZE);
    stack->length = 0;
    stack->array_size = INIT_STACK_SIZE;

    return stack;
}

void __push(struct stack *stack, void *element) {
    if (stack->length == stack->array_size) {
        stack->array = (void **)realloc(
            stack->array, sizeof(void *) * (stack->array_size << 1));
        stack->array_size = stack->array_size << 1;
    }

    stack->array[stack->length++] = element;
}

void *__pop(struct stack *stack) {
    if (stack->length > INIT_STACK_SIZE &&
        stack->length < (stack->array_size >> 2)) {
        stack->array = (void **)realloc(
            stack->array, sizeof(void *) * (stack->array_size >> 1));
        stack->array_size = stack->array_size >> 1;
    }
    return stack->array[--stack->length];
}

int __empty(struct stack *stack) { return stack->length == 0; }

void __foreach(struct stack *stack, void (*function)(void *data)) {
    int i;
    for (i = 0; i < stack->length; i++) {
        function(stack->array[i]);
    }
}

void __free(struct stack *stack) {
    free(stack->array);
    free(stack);
}

void __free_with_items(struct stack *stack) {
    int i;
    for (i = 0; i < stack->length; i++) {
        free(stack->array[i]);
    }
    free(stack);
}

const struct stackop stackop = {
    .instance = __instance,
    .push = __push,
    .pop = __pop,
    .empty = __empty,
    .foreach = __foreach,
    .free = __free,
    .free_with_items = __free_with_items,
};
