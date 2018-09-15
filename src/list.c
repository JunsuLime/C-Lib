#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include "common.h"

static struct node *new_node(void *data) {
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->next = NULL;

    return node;
}

struct list *__instance() {
    struct list *list =
        (struct list *)malloc(sizeof(struct list));
    list->head = new_node(NULL);
    list->tail = list->head;

    return list;
}

void __append(struct list *list, void *element) {
    struct node *node = new_node(element);
    list->tail->next = node;
    list->tail = node;
}

void __prepend(struct list *list, void *element) {
    struct node *node = new_node(element);
    node->next = list->head->next;
    list->head->next = node;
}

void *__delete(struct list *list, void *element,
            int (*equals)(void *compared, void *item)) {
    struct node *prev = list->head;
    struct node *current = prev->next;
    void *data;

    while (current) {
        if (equals(element, current->data)) {
            prev->next = current->next;
            data = current->data;
            free(current);
            return data;
        }
        prev = current;
        current = current->next;
    }
    return NULL;
}

void *__find(struct list *list, void *element,
           int (*equals)(void* compared, void* item)) {
    struct node *current = list->head->next;
    while (current) {
        if (equals(element, current->data))
            return current->data;
        current = current->next;
    }
    return NULL;
}

void __foreach(struct list *list, void (*function)(void *data)) {
    struct node *current = list->head->next;
    while (current) {
        function(current->data);
        current = current->next;
    }
}

void __free(struct list *list) {
    struct node *current = list->head;
    struct node *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    free(list);
}

void __free_with_items(struct list *list) {
    struct node *current = list->head;
    struct node *next;

    while (current != NULL) {
        next = current->next;
        free(current->data);
        free(current);
        current = next;
    }

    free(list);
}

const struct listop listop = {
    .instance = __instance,
    .append = __append,
    .prepend = __prepend,
    .delete = __delete,
    .find = __find,
    .foreach = __foreach,
    .free = __free,
    .free_with_items = __free_with_items,
};
