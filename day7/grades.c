#include <stdio.h>

int student_avg(int g[][5], int row) {
	int total = 0;
	for (int i = 0; i < 5; i++) {
		total += g[row][i];
	}
	total = total / 5;
	return total;
}

int task_avg(int g[][5], int col, int rows) {
	int total = 0;
	for (int i = 0; i < rows; i++) {
		total += g[i][col];
	}
	total = total / rows;
	return total;
}

int main(void) {
		int grades[4][5] = {
		{90, 85, 78, 92, 88},
		{70, 75, 80, 65, 72},
		{100, 98, 95, 99, 97},
		{60, 55, 70, 62, 58}
	};

	printf("Student Average #1: %d\n", student_avg(grades,0));
	printf("Assignment Average #3: %d\n", task_avg(grades, 2, 4));
	return 0;
}
