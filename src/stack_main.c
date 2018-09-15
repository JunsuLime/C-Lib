#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void print_function(void *data) { printf("%d ,", *(int *)data); }

int main() {
    struct stackop op = stackop;

    int i;
    int element1 = 1;
    int element2 = 2;
    int element3 = 3;
    int element4 = 4;

    int *array = (int *)malloc(sizeof(int) * 1000);

    struct stack *stack = op.instance();

    printf("isempty: %d\n", op.empty(stack));

    // result: isempty: 1

    op.push(stack, &(element1));
    op.push(stack, &(element2));
    op.push(stack, &(element3));
    void *data = op.pop(stack);
    printf("top: %d\n", *(int *)data);

    // result: top: 3

    op.push(stack, &(element4));
    op.foreach(stack, print_function);
    printf("\n");

    // result: 1, 2, 4

    printf("isempty: %d\n", op.empty(stack));

    // result: isempty: 0

    for (i = 0; i < 1000; i++) {
        op.push(stack, &array[i]);
    }

    for (i = 0; i < 1000; i++) {
        op.pop(stack);
    }

    printf("top: %d\n", *(int *)op.pop(stack));

    // result: top: 4

    op.free(stack);

    return 0;
}
