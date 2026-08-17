#include <stdio.h>

void swap_broken(int a, int b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main() {
	int x = 1;
	int y = 2;
	swap_broken(x, y);
	printf("broken: x = %d, y = %d\n", x, y);
	swap(&x, &y);
	printf("working: x = %d, y = %d\n", x, y);
	return 0;
}

