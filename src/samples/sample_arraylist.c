#include "arraylist.h"
#include "common.h"
#include "test/verify.h"

#define DUMMY_SIZE 1048576

void fill_arraylist(arraylist *list, int *array) {
    int i;
    for (i = 0; i < DUMMY_SIZE; i++) {
        arraylist_op.append(list, &array[i]);
    }
}

void test_clear_and_length(arraylist *list) {
    int array[DUMMY_SIZE];

    VERIFY(arraylist_op.length(list), 0);

    fill_arraylist(list, array);
    VERIFY(arraylist_op.length(list), DUMMY_SIZE);

    arraylist_op.clear(list);
    VERIFY(arraylist_op.length(list), 0);
}

void test_append_and_get(arraylist *list) {
    int i;
    int array[DUMMY_SIZE];
   
    fill_arraylist(list, array);

    for (i = 0; i < DUMMY_SIZE; i++) {
        VERIFY(*(int*)arraylist_op.get(list, i), array[i]);
    }

    arraylist_op.clear(list);
}

void test_pop_and_empty(arraylist *list) {
    int i;
    int array[DUMMY_SIZE];

    fill_arraylist(list, array);
    VERIFY(arraylist_op.empty(list), FALSE);

    for (i = 0; i < DUMMY_SIZE; i++) {
        VERIFY(*(int*)arraylist_op.pop(list), array[DUMMY_SIZE - 1 - i]);
    }
    VERIFY(arraylist_op.empty(list), TRUE);

    arraylist_op.clear(list);
}

void test_iterator(arraylist *list) {
    int i;
    int array[DUMMY_SIZE];

    fill_arraylist(list, array);

    arraylist_iter iter;
    arraylist_op.iterator(list, &iter);

    i = 0;
    while (arraylist_op.has_next(&iter)) {
        VERIFY(*(int*)arraylist_op.next(&iter), array[i++]);
    }

    arraylist_op.clear(list);
}

void test_set_and_swap(arraylist *list) {
    int e1 = 3;
    int e2 = 5;
    int e3 = 7;

    arraylist_op.append(list, &e1);
    arraylist_op.append(list, &e2);

    arraylist_op.set(list, 0, &e3);

    VERIFY(*(int*)arraylist_op.get(list, 0), e3);

    arraylist_op.swap(list, 0, 1);
    VERIFY(*(int*)arraylist_op.get(list, 0), e2);

    arraylist_op.clear(list);
}

void __test_foreach(void *e) {
    VERIFY(*(int*)e, 1024);
}

void test_foreach(arraylist *list) {
    int i;
    int array[3] = {1024, 1024, 1024};
    
    for (i = 0; i < 3; i++) {
        arraylist_op.append(list, &array[i]);
    }
    
    arraylist_op.foreach(list, __test_foreach);
    arraylist_op.clear(list);
}

int main(int argc, char** argv) {

    arraylist list;
    arraylist_op.init(&list);

    test_clear_and_length(&list);
    test_append_and_get(&list);
    test_pop_and_empty(&list);
    test_iterator(&list);
    test_set_and_swap(&list);
    test_foreach(&list);

    arraylist_op.free(&list);
    return 0;
}
