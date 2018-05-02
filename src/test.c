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

	op.init(&arr);

	int i, code;
	code = SUCCESS;

	// isEmtpy function
	if (!op.isEmpty(&arr)) {
		return FAILURE;
	}
	
	// test append and get function
	for (i = 0; i < TEST_ITER; i++) {
		op.append(&arr, i);
	}

	for (i = 0; i < TEST_ITER; i++) {
		if (op.get(&arr, i) != i) {
			code = FAILURE;
			break;
		}
	}

	// test pop function
	for (i = TEST_ITER-1; i >= 0; i--) {
		if (op.pop(&arr) != i) {
			code = FAILURE;
			break;
		}
	}

	// set, get, clear and length function
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

	// add and remove
	op.add(&arr, 0, 1);
	op.remove(&arr, 0);


	op.free(&arr);
	return code;
}

