/**
 * C collection ArrayList: arraylist.h
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

// TODO: Add comment on functions
//
// - What the inputs and outputs are.
// - For class member functions: whether the object remembers reference arguments
//   beyond the duration of the method call, and whether it will free them or not.
// - If the function allocates memory that the caller must free.
// - Whether any of the arguments can be a null pointer.
// - If there are any performance implications of how a function is used.


#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include "container.h"

#define INIT_ARRAY_SIZE 16

typedef struct {
	// Has item array's pointer
	int *_container;
	// Has item array's physical size
	int _size;
	// Has item array's logical size
	int length;
} ArrayList;

typedef struct {
    // reference arrayList
    ArrayList *_arrayList;
    // current refer index
    int current;
} ArrayListIter;

typedef struct {
	void (*init)(ArrayList* arrayList);
 
 	void (*free)(ArrayList* arrayList);
  
	int (*contain)(ArrayList* arrayList, int e);
  
	int (*isEmpty)(ArrayList* arrayList);
  
	int (*get)(ArrayList* arrayList, int index);
  
	void (*set)(ArrayList* arrayList, int index, int e);
  
	ArrayListIter* (*iterator)(ArrayList* arrayList);

    int (*hasNext)(ArrayListIter* arrayListIter);

    int (*next)(ArrayListIter* arrayListIter);
  
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

int arrayListHasNext(ArrayListIter *iterator);

int arrayListNext(ArrayListIter *iterator);

void arrayListRemove(ArrayList *arrayList, int index);

void arrayListAdd(ArrayList *arrayList, int index, int e);

void arrayListAppend(ArrayList *arrayList, int e);

int arrayListPop(ArrayList *arraylist);

void arrayListClear(ArrayList  *arrayList);

int arrayListLength(ArrayList *arrayList);

#endif	// ARRAYLIST_H
