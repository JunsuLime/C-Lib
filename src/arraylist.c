#include <stdlib.h>
#include "arraylist.h"


ArrayListOp arrayListOp() {
	ArrayListOp *op;
	op = (ArrayListOp*) malloc(sizeof(ArrayListOp));

	op->init = arrayListInit;
	op->free = arrayListFree;
	op->contain = arrayListContain;
	op->isEmpty = arrayListIsEmpty;
	op->get = arrayListGet;
	op->set = arrayListSet;
	op->iterator = arrayListIterator;
	op->remove = arrayListRemove;
	op->add = arrayListAdd;
	op->append = arrayListAppend;
	op->pop = arrayListPop;
	op->clear = arrayListClear;
	op->length = arrayListLength;

	return *op;
}

void arrayListInit(ArrayList *arrayList) {
	arrayList->length = 0;
	arrayList->_size = INIT_ARRAY_SIZE;
	arrayList->_container = (int*)malloc(sizeof(int)*INIT_ARRAY_SIZE);
}

void arrayListFree(ArrayList *arrayList) {
	free(arrayList->_container);
}

int arrayListContain(ArrayList *arrayList, int e) {
	int i = 0;
	for (i = 0; i < arrayList->length; i++) {
		if (arrayList->_container[i] == e) {
			return TRUE;
		}
	}
	return FALSE;
}

int arrayListIsEmpty(ArrayList *arrayList) {
	return arrayList->length == 0;
}

int arrayListGet(ArrayList *arrayList, int index) {
	return arrayList->_container[index];
}

void arrayListSet(ArrayList *arrayList, int index, int e) {
	if (index > arrayList->length) {
		return;
	}
	arrayList->_container[index] = e;	
}

ArrayListIter* arrayListIterator(ArrayList *arrayList) {
	return 0;
}

void arrayListRemove(ArrayList *arrayList, int index) {
	if (index >= arrayList->length) {
		return;
	}
	int i;
	for (i = index; i < arrayList->length-1; i++) {
		arrayList->_container[i] = arrayList->_container[i+1];
	}

	if (arrayList->length > INIT_ARRAY_SIZE && arrayList->length-1 < arrayList->_size >> 2) {
		arrayList->_size = arrayList->_size >> 1;
		arrayList->_container = realloc(arrayList->_container, sizeof(int)*arrayList->_size);
	}
	arrayList->length--;
}

void arrayListAdd(ArrayList *arrayList, int index, int e) {
	if (index < 0 || index > arrayList->length) {
		return;
	}
	
	// if container is filled fully
	if (arrayList->length == arrayList->_size) {
		arrayList->_size = arrayList->_size * 2;
		arrayList->_container = realloc(arrayList->_container, sizeof(int)*arrayList->_size);
	}

	int i = 0;

	for (i = arrayList->length; i >= index; i--) {
		arrayList->_container[i+1] = arrayList->_container[i];
	}
	arrayList->_container[index] = e;
	arrayList->length++;
}

void arrayListAppend(ArrayList *arrayList, int e) {
	// if container is filled fully
	if (arrayList->length == arrayList->_size) {
		arrayList->_size = arrayList->_size * 2;
		arrayList->_container = realloc(arrayList->_container, sizeof(int)*arrayList->_size);
	}
	arrayList->_container[arrayList->length] = e;
	arrayList->length++;
}

int arrayListPop(ArrayList *arrayList) {
	// if container is filled less than quarter and bigger than INIT_ARRAY_SIZE
	if (arrayList->length > INIT_ARRAY_SIZE && arrayList->length-1 < arrayList->_size >> 2) {
		arrayList->_size = arrayList->_size >> 1;
		arrayList->_container = realloc(arrayList->_container, sizeof(int)*arrayList->_size);
	}

	arrayList->length--;
	return arrayList->_container[arrayList->length];
}

void arrayListClear(ArrayList *arrayList) {
	if (arrayList->_size > INIT_ARRAY_SIZE) {
		arrayList->_size = INIT_ARRAY_SIZE;
		arrayList->_container = realloc(arrayList->_container, sizeof(int)*INIT_ARRAY_SIZE);
	}
	arrayList->length = 0;
}

int arrayListLength(ArrayList *arrayList) {
	return arrayList->length;
}


