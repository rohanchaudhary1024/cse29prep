#include <stdio.h>
#include <assert.h>
#include "mystring.h"

int main(void) {
	assert(str_index("hello world", "world") == 6);
	assert(str_index("hello world", "hello") == 0);
	assert(str_index("hello world", "d") == 10);
	assert(str_index("hello world", "moneymagic") == -1);
	assert(str_index("hello", "hello world") == -1);
	assert(str_index("", "hello") == -1);
	assert(str_index("hello world", "") == -1);
	assert(str_index("aaa", "aa") == 0);

	printf("str_index: 8 tests passed\n");
	return 0;
}
