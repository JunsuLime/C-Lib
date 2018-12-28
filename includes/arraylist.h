#ifndef __ARRAYLIST_H__
#define __ARRAYLIST_H__

#define INIT_ARRAY_SIZE 32

struct __arraylist {
    void **array;
    int length;
    int size;
};

typedef struct __arraylist arraylist;

struct __arraylist_iter {
    arraylist *list;
    int index;
};

typedef struct __arraylist_iter arraylist_iter;

struct __arraylist_op {
    void (*init)(arraylist *list);
    void (*append)(arraylist *list, void *e);
    void *(*pop)(arraylist *list);
    void *(*get)(arraylist *list, int i);
    void (*set)(arraylist *list, int i, void *e);
    void (*swap)(arraylist *list, int i1, int i2);
    void (*clear)(arraylist *list);
    int (*length)(arraylist *list);
    int (*empty)(arraylist *list);
    void (*foreach)(arraylist *list, void (*func)(void *e));
    void (*free)(arraylist *list);
    void (*free_foreach)(arraylist *list,  void (*func)(void *e));

    void (*iterator)(arraylist *list, arraylist_iter *iter);
    int (*has_next)(arraylist_iter *iter);
    void *(*next)(arraylist_iter *iter);
};

typedef struct __arraylist_op __arraylist_op;

extern const __arraylist_op arraylist_op;

#endif // __ARRAY_LIST_H__
