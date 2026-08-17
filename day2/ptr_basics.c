#include <stdio.h>

int main() {
	int x = 42;
	int *p = &x;

	printf("x = %d\n", x);
	printf("&x = %p\n", (void *)&x);
	printf("*p = %d\n", *p);

	*p = 99;
	printf("x is now %d\n", x);
	return 0;
}
