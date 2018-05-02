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
	op->length = arrayListLength;

	return *op;
}

void arrayListInit(ArrayList *arrayList) {

}

void arrayListFree(ArrayList *arrayList) {

}

int arrayListContain(ArrayList *arrayList, int e) {
	return 0;
}

int arrayListIsEmpty(ArrayList *arrayList) {
	return 0;
}

int arrayListGet(ArrayList *arrayList, int index) {
	return 0;
}

void arrayListSet(ArrayList *arrayList, int index, int e) {

}

ArrayListIter* arrayListIterator(ArrayList *arrayList) {
	return 0;
}

void arrayListRemove(ArrayList *arrayList, int index) {

}

void arrayListAdd(ArrayList *arrayList, int index, int e) {

}

void arrayListAppend(ArrayList *arrayList, int e) {

}

int arrayListPop(ArrayList *arraylist) {
	return 0;
}

int arrayListLength(ArrayList *arrayList) {
	return 0;
}

