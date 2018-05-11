/**
 * C collection ArrayList: arraylist.c
 *
 * Copyright (c) 2018 Junsulime
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <stdlib.h>
#include "arraylist.h"

int initialized;
ArrayListOp operator;

ArrayListOp arrayListOp() {
    if (!initialized) {
    	operator.init = arrayListInit;
	    operator.free = arrayListFree;
    	operator.contain = arrayListContain;
	    operator.isEmpty = arrayListIsEmpty;
    	operator.get = arrayListGet;
	    operator.set = arrayListSet;
	    operator.iterator = arrayListIterator;
        operator.hasNext = arrayListHasNext;
        operator.next = arrayListNext;
    	operator.remove = arrayListRemove;
	    operator.add = arrayListAdd;
	    operator.append = arrayListAppend;
    	operator.pop = arrayListPop;
	    operator.clear = arrayListClear;
	    operator.length = arrayListLength;
    }
	return operator;
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
    ArrayListIter *iterator = (ArrayListIter*)malloc(sizeof(ArrayListIter));
    iterator->_arrayList = arrayList;
    iterator->current = 0;
	
    return iterator;
}

int arrayListHasNext(ArrayListIter* iterator) {
    return iterator->current < iterator->_arrayList->length;
}

int arrayListNext(ArrayListIter* iterator) {
    return iterator->_arrayList->_container[iterator->current++];
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


