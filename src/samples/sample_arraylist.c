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

int test_clear_and_length(arraylist *list) {
    int array[DUMMY_SIZE];

    if (arraylist_op.length(list) != 0) {
        return FALSE;
    }

    fill_arraylist(list, array);

    if (arraylist_op.length(list) != DUMMY_SIZE) {
        return FALSE;
    }

    arraylist_op.clear(list);
    if (arraylist_op.length(list) != 0) {
        return FALSE;
    }
    return TRUE;
}

int test_append_and_get(arraylist *list) {
    int i;
    int array[DUMMY_SIZE];
   
    fill_arraylist(list, array);

    for (i = 0; i < DUMMY_SIZE; i++) {
        if (*(int*)arraylist_op.get(list, i) != array[i]) {
            return FALSE; 
        }
    }

    arraylist_op.clear(list);
    return TRUE;
}

int test_pop_and_empty(arraylist *list) {
    int i;
    int array[DUMMY_SIZE];

    fill_arraylist(list, array);
    if (arraylist_op.empty(list)) {
        return FALSE;
    }

    for (i = 0; i < DUMMY_SIZE; i++) {
        if (*(int*)arraylist_op.pop(list) != array[DUMMY_SIZE - 1 - i]) {
            return FALSE;
        }
    }

    if (!arraylist_op.empty(list)) {
        return FALSE;
    }

    arraylist_op.clear(list);
    return TRUE;
}

int test_iterator(arraylist *list) {
    int i;
    int array[DUMMY_SIZE];

    fill_arraylist(list, array);

    arraylist_iter iter;
    arraylist_op.iterator(list, &iter);

    i = 0;
    while (arraylist_op.has_next(&iter)) {
        if (*(int*)arraylist_op.next(&iter) != array[i++]) {
            return FALSE;
        }
    }

    arraylist_op.clear(list);
    return TRUE;
}

int main(int argc, char** argv) {

    arraylist list;
    arraylist_op.init(&list);

    VERIFY(test_clear_and_length(&list));
    VERIFY(test_append_and_get(&list));
    VERIFY(test_pop_and_empty(&list));
    VERIFY(test_iterator(&list));

    arraylist_op.free(&list);
    return 0;
}
