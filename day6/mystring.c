#include <stdio.h>
#include <string.h>
#include "mystring.h"

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

/* Haystack Needle Problem */

int str_index(char *haystack, char *needle) {
	int index = -1;
	int tindex = -1;
	int count = 0;
	for (int i = 0; i < strlen(haystack); i++) {
		if (strlen(haystack) <= count) {
			break;
		}
		if (haystack[i] == needle[count]) {
			if (count == 0) {
				tindex = i;
			}
			if (count == strlen(needle)-1) {
				index = tindex;
				return index;
			}

			count += 1;
		}
	}
	return index;

}
