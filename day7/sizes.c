#include <stdio.h>

int main(void) {
	int grid[4][5] = {
		{90, 85, 78, 92, 88},
		{70, 75, 80, 65, 72},
		{100, 98, 95, 99, 97},
		{60, 55, 70, 62, 58}
	};

	printf("whole grid = %zu bytes\n", sizeof(grid));
	printf("one row = %zu bytes\n", sizeof(grid[0]));
	printf("one cell = %zu bytes\n", sizeof(grid[0][0]));
	printf("grid[2][3] = %d\n", grid[2][3]);
	return 0;
}
