#include <stdio.h>
#include <limits.h>

void point_to_max(int *arr, int size, int **out) {
	int tempmax = INT_MIN;
	int maxind = -1;
	for (int i = 0; i < size; i++) {
		if (arr[i] > tempmax) {
			tempmax = arr[i];
			maxind = i;
		}
	}
	printf("%d\n",arr[maxind]);
	printf("%p\n",&arr[maxind]);
	*out = &(arr[maxind]);
}

int main() {
	int *best = NULL;
	int a[] = {2, 3, 4, 5, 6, 7};
	point_to_max(a, 6, &best);
	printf("%p",(void *)(best));
	//printf("%p", (void *)best);
	return 0;
}
