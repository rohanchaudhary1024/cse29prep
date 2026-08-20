#include <stdio.h>
#include "mystring.h"

int main(void) {
	FILE *in = fopen("input.txt", "r");
	if (in == NULL) {
		printf("could not open input.txt\n");
		return 1;
	}

	FILE *out = fopen("output.txt", "w");
	if (out == NULL) {
		printf("could not open output.txt\n");
		fclose(in);
		return 1;
	}

	char line[256];
	int n = 1;

	while (fgets(line, sizeof(line), in) != NULL) {
		replace_char(line, 'a', 'o');
		trim_newline(line);
		fprintf(out, "%3d: %s\n", n, line);
		n++;
	}

	fclose(in);
	fclose(out);
	printf("relabel: wrote %d lines output.txt\n", n-1);
	return 0;
}
