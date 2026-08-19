#include <stdio.h>
#include <string.h>
#include <assert.h>

/* Replace every 'find' with 'rep' in s, in place. s must be writable -
a char array, not a string literal. Returns how many were replaced. */

int replace_char(char *s, char find, char rep) {
    int replacecount = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == find) {
            s[i] = rep;
			replacecount += 1;
        }
    }   
	return replacecount;
}

/* Remove a trailing '\n' from s, if there is one. Safe on strings without one. Returns 1 if a newline was removed, 0 otherwise */

int trim_newline(char *s) {
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == '\n') {
			s[i] = '\0';
			return 1;
		}
	}
	return 0;
}

int main() {
	char fruit[] = "banana";
	assert(replace_char(fruit, 'a', 'o') == 3);
	assert(fruit[1] == 'o');

	char line[] = "hello\n";
	assert(trim_newline(line) == 1);
	assert(line[5] == '\0');

	char plain[] = "hello";
	assert(trim_newline(plain) == 0);

	printf("string2.c : 5 tests passed\n");
	return 0;
}
