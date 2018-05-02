#ifndef ARRAYLIST_H
#define ARRAYLIST_H

typedef struct {
	int *container;
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

int arrayListLength(ArrayList *arrayList);
#endif
