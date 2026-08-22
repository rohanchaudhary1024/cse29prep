#include <stdio.h>
#include <assert.h>
void print_board(char b[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}
}

char check_winner(char b[3][3]) {
	// Check Horizontals, Verticals, X/O
	for (int i = 0; i < 3; i++) {
		if (b[i][0] == b[i][1] && b[i][0] == b[i][2]) {
			if (b[i][0] == 'X') {
				return 'X';
			} else if (b[i][0] == 'O') {
				return 'O';
			}
		}
		if (b[0][i] == b[1][i] && b[0][i] == b[2][i]) {
			if (b[0][i] == 'X') {
				return 'X';
			} else if (b[0][i] == 'O') {
				return 'O';
			}
		}
	}

	if (b[0][0] == b[1][1] && b[0][0] == b[2][2]) {
		if (b[0][0] == 'X') {
			return 'X';
		} else if (b[0][0] == 'O') {
			return 'O';
		}
	}
	if (b[2][0] == b[1][1] && b[2][0] == b[2][2]) {
		if (b[0][2] == 'X') {
			return 'X';
		} else if (b[0][2] == 'O') {
			return 'O';
		}
	}

	return ' ';
}

int main(void) {
	char boardOne[3][3] = {
		{'X', 'X', 'X'},
		{'X', 'O', 'O'},
		{'O', 'X', 'X'},
	};
	assert(check_winner(boardOne) == 'X');
	
	char boardTwo[3][3] = {
		{'X', 'O', 'X'},
		{'X', 'O', 'O'},
		{'O', 'O', 'X'},
	};
	assert(check_winner(boardTwo) == 'O');
	
	char boardThree[3][3] = {
		{'X', 'O', 'X'},
		{'X', 'X', 'O'},
		{'O', 'X', 'X'},
	};
	assert(check_winner(boardThree) == 'X');
	
	char boardFour[3][3] = {
		{'X', 'O', 'X'},
		{'X', 'O', 'O'},
		{'O', 'X', 'X'},
	};
	assert(check_winner(boardFour) == ' ');

	printf("Four tests passed.");
	return 0;
}
