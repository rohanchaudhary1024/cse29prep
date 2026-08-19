#include <stdio.h>
#include <stdlib.h>

int *works(void) {
	int *p = malloc(sizeof(int));
	if (p == NULL) return NULL;
	*p = 42;
	return p;
}

int main(void) {
	int on_stack = 1;
	int count = 5;
	int *nums = malloc(count * sizeof(int));

	if (nums == NULL) {
		printf("malloc failed\n");
		return 1;
	}

	for (int i = 0; i < count; i++) {
		nums[i] = i * i;
	}
	for (int i = 0; i < count; i++) {
		printf("nums[%d] = %d\n", i, nums[i]);
	}

	printf("stack: %p\n", (void *)&on_stack);
	printf("heap: %p\n", (void *)nums);
	free(nums);
	works();
	return 0;
}
