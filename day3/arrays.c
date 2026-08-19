#include <stdio.h>
#include <assert.h>

int sum(int arr[], int size) {
	int total = 0;
	for (int i = 0; i < size; i++) {
		total += *(arr+i);
	}
	return total;
}

int *find(int item, int arr[], int size) {
	int *output = NULL;
	for (int i = 0; i < size; i++) {
		if (item == arr[i]) {
			output = arr+i;
			break;
		}
	}
	return output;

	
}

int main() {
	int a[] = {2, 3, 4};
	int total = sum(a, 3);
	printf("Sum Output: %d\n", total);
	int *output = find(3, a, 3);
	if (output != NULL) {
		printf("Find Output\n");
		printf("Pointer Value: %p\n", output);
		printf("Integer Value: %d\n", *output); // Should be 3
	}
    
    int nums[] = {1,2,3,4,5};
    assert(sum(nums, 5) == 16);

	return 0;
}
