#include <stdio.h>

int main() {
	int a[4] = {10, 20, 30, 40};
	char b[4] = {'w', 'x', 'y', 'z'};
	int *pi = a;
	char *pc = b;

	printf("int : %p -> %p\n", (void *)pi, (void *)(pi + 1));
	printf("char : %p -> %p\n", (void *)pc, (void *)(pc + 1));
	printf("a[3] - a[0] = %ld\n", &a[3] - &a[0]);
	return 0;
}
