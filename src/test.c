/**
 * C collection Tester: test.c
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

#include <stdio.h>

#include "test.h"
#include "arraylist.h"

void printResult(int code) {
	switch (code) {
		case SUCCESS:
			printf("Success!\n");
			break;
		default:
			printf("Failure\n");
			break;
	}
}

int testArrayList() {
	ArrayListOp op = arrayListOp();
	ArrayList arr;
    ArrayListIter *iter;
	
    op.init(&arr);

	int i, code;
	code = SUCCESS;

	/* isEmpty function test */
	if (!op.isEmpty(&arr)) {
		return FAILURE;
	}
	
	/* append, get function test */
	for (i = 0; i < TEST_ITER; i++) {
		op.append(&arr, i);
	}

	for (i = 0; i < TEST_ITER; i++) {
		if (op.get(&arr, i) != i) {
			code = FAILURE;
			break;
		}
	}

    /* iterator test */
    iter = arrayListIterator(&arr);
    i = 0;
    while (op.hasNext(iter)) {
        if (op.next(iter) != i) {
            return FAILURE;
        }
        i++;
    }
    
	/* pop function test */
	for (i = TEST_ITER-1; i >= 0; i--) {
		if (op.pop(&arr) != i) {
			code = FAILURE;
			break;
		}
	}

	/* get, set, clear, length function test */
	op.append(&arr, 1);
	op.set(&arr, 0, 3);
	if (op.length(&arr) != 1) {
		return FAILURE;
	}
	if (op.get(&arr, 0) != 3) {
		return FAILURE;
	}
	op.clear(&arr);
	if (op.length(&arr) != 0) {
		return FAILURE;
	}

	/* add, remove function test */
	op.add(&arr, 0, 1);
	op.remove(&arr, 0);


	op.free(&arr);
	return code;
}

