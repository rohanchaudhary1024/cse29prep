#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Return a fresh copy of s on the heap. Caller must free it.
Returns NULL if there was no memory. */

char *dup_string(char *s) {
	int len = strlen(s);
	char *copy = malloc(len + 1);
	if (copy == NULL) return NULL;

	for (int i = 0; i <= len; i++) {
		copy[i] = s[i];
	}

	return copy;
}

char *join(char *a, char *b) {
	int len = strlen(a) + strlen(b) + 1 ;
	char *joined = malloc(len);
	for (int i = 0; i < strlen(a); i++) {
		joined[i] = a[i];
	}
	for (int i = 0; i <= strlen(b); i++) {
		joined[strlen(a) + i] = b[i];
	}
	return joined;
}

int main(void) {
	char *c = dup_string("hello");
	printf("copy = %s\n", c);
	free(c);

	char *s = join("apples", "bananas");
	printf("join = %s\n", s);
	free(s);
	return 0;
}
