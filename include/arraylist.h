#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include "container.h"

#define INIT_ARRAY_SIZE 16

typedef struct {
	int *_container;
	int _size;
	int length;
} ArrayList;

typedef struct {

} ArrayListIter;

typedef struct {
	void (*init)(ArrayList* arrayList);
 
 	void (*free)(ArrayList* arrayList);
  
	int (*contain)(ArrayList* arrayList, int e);
  
	int (*isEmpty)(ArrayList* arrayList);
  
	int (*get)(ArrayList* arrayList, int index);
  
	void (*set)(ArrayList* arrayList, int index, int e);
  
	ArrayListIter* (*iterator)(ArrayList* arrayList);
  
	void (*remove)(ArrayList* arrayList, int index);
  
	void (*add)(ArrayList* arrayList, int index, int e);
  
	void (*append)(ArrayList *arrayList, int e);
  
	int (*pop)(ArrayList *arrayList);

	void (*clear)(ArrayList *arrayList);
  
	int (*length)(ArrayList *arrayList);

} ArrayListOp;


ArrayListOp arrayListOp();

void arrayListInit(ArrayList *arrayList);

void arrayListFree(ArrayList *arrayList);

int arrayListContain(ArrayList *arrayList, int e);

int arrayListIsEmpty(ArrayList *arrayList);

int arrayListGet(ArrayList *arrayList, int index);

void arrayListSet(ArrayList *arrayList, int index, int e);

ArrayListIter* arrayListIterator(ArrayList *arrayList);

void arrayListRemove(ArrayList *arrayList, int index);

void arrayListAdd(ArrayList *arrayList, int index, int e);

void arrayListAppend(ArrayList *arrayList, int e);

int arrayListPop(ArrayList *arraylist);

void arrayListClear(ArrayList  *arrayList);

int arrayListLength(ArrayList *arrayList);

#endif
