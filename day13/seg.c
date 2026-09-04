#include <stdio.h>
#include <string.h>

/* Return a pointer to the first space in s, or NULL if there is not one */
char *first_space(char *s) {
	for (int i = 0; s[i] != '\0'; i++) 
		if (s[i] == ' ') return &s[i];
	return NULL;
}

int main(void) {
	char *lines[3] = { "the quick fox", "jumps over", "nospacehere" };

	for (int i = 0; i < 3; i++) {
		char *sp = first_space(lines[i]);
		if (sp != NULL) {
		printf("line %d, after the first space: %s\n", i, sp + 1);
		}
	}

	return 0;
}
