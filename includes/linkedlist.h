#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

struct node {
    struct node *next;
    void *data;
};

struct list {
    struct node *head;
    struct node *tail;
};

struct listop {
    struct list *(*instance)();
    void (*append)(struct list *list, void *element);
    void (*prepend)(struct list *list, void *element);
    void *(*delete)(struct list *list, void *element,
                   int (*equals)(void *compared, void *item));
    void *(*find)(struct list *list, void *element,
                  int (*Equals)(void *compared, void *item));
    void (*foreach)(struct list *list,
                    void (*function)(void *data));
    void (*free)(struct list *list);
    void (*free_with_items)(struct list *list);
};

extern const struct listop listop;

#endif  // __LINKEDLIST_H__
