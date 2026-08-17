#include <stdio.h>

void show_size(int arr[]) {
	printf("inside function: %zu\n", sizeof(arr));
}

void extra_size(int arr[]) {
       	printf("arr[2]=%d *(arr+72)=%d\n", arr[2], *(arr + 2));
  	printf("inside function: %zu\n", sizeof(arr+7));
}


int main() {
	int arr[] = {2, 9, 2, 0, 2, 5};
	printf("in main: %zu\n", sizeof(arr));
	printf("arr=%p &arr[0]=%p\n", (void *)arr, (void *)&arr[0]);
	printf("arr[2]=%d *(arr+2)=%d\n", arr[2], *(arr + 2));
	show_size(arr);
	extra_size(arr);
	return 0;
}
