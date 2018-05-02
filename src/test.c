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

	for (i = 0; i < TEST_ITER; i++) {
		op.append(&arr, i);
	}

	for (i = 0; i < TEST_ITER; i++) {
		if (op.get(&arr, i) != i) {
			code = FAILURE;
			break;
		}
	}	
	return code;
}

