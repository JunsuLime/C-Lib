#include <stdio.h>
#include "common.h"
#include "linkedlist.h"

void print_function(void *data) { printf("%d, ", *((int *)data)); }

int Equals(void *compared, void *item) { return *((int *)compared) == *((int *)item); }

int main(int argc, char **argv) {
    struct listop op = listop;
    struct list *list;

    int element1 = 1;
    int element2 = 2;
    int element3 = 3;
    int element4 = 4;

    int same_as_e2 = 2;

    list = op.instance();
    op.append(list, &(element1));
    op.append(list, &(element2));
    op.append(list, &(element3));
    op.foreach(list, print_function);
    printf("\n");

    // result: 1, 2, 3,

    int *data = (int *)op.find(list, &element1, Equals);
    printf("Found Data: %d\n", *data);

    // result: Found Data: 1

    op.delete(list, &(same_as_e2), Equals);
    op.prepend(list, &(element4));
    op.foreach(list, print_function);
    printf("\n");

    // result: 4, 1, 3

    op.free(list);

    return 0;
}
