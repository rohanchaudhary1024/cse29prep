#include <stdio.h>
#include <assert.h>
#include "mystring.h"

int main(void) {
	char fruit[] = "banana";
	assert(replace_char(fruit, 'a', 'o') == 3);
	assert(fruit[1] == 'o');

	char line[] = "hello\n";
	assert(trim_newline(line) == 1);
	assert(line[5] == '\0');

	char plain[] = "hello";
	assert(trim_newline(plain) == 0);

	printf("mystring: 5 tests passed\n");
	return 0;
}
