#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include "mystring.h"

#define MAX_WORDS 500
#define WORD_LEN 32

struct wordcount {
	char word[WORD_LEN];
	int n;
};

int find_word(struct wordcount list[], int count, char *w) {
	for (int i = 0; i < count; i++) {
		if (strcmp(list[i].word, w) == 0) {
			return i;
		}
	}
	return -1;
}

int add_word(struct wordcount list[], int count, int max, char *w) {
	
	printf("Adding word: List matches...");
	printf("... to %s\n", w);	
	for (int i = 0; i < count; i++) {
		printf("%s, ",list[i].word);
		if (strcmp(list[i].word, w) == 0) {
			printf("WORKS!");
			list[i].n += 1;
			return count;
		}
	}
	if (count < max) {
		strcpy(list[count].word, w);
		list[count].n = 1;
		return count+1;
	}
	printf("\n");
	return count;
}

int count_words(char *filename, struct wordcount list[], int max) {
	FILE *f = fopen(filename, "r");
	if (f == NULL) return -1;
	char line[256];
	int wcount = 0;
	int ccount = 0;
	char currWord[WORD_LEN];
	while (fgets(line, sizeof(line), f) != NULL) {
		trim_newline(line);
		for (int i = 0; i <= strlen(line); i++) {
			if (isalpha(line[i]) && line[i] != '\0') {
				if (ccount != WORD_LEN-1) {
					
					currWord[ccount] = tolower(line[i]);
					currWord[ccount+1] = '\0';

					ccount += 1;
				}
			}
			else if (ccount > 0) {
				wcount =add_word(list, wcount, MAX_WORDS, currWord);	
			
				strcpy(currWord,"");
				ccount = 0;
			}
		}
	}
	fclose(f);
	return wcount;
}

int main(void) {
	struct wordcount list[MAX_WORDS];
	int count = 0;
	
	count = add_word(list, count, MAX_WORDS, "dog");
	count = add_word(list, count, MAX_WORDS, "cat");
	count = add_word(list, count, MAX_WORDS, "dog");

	assert(count == 2);
	assert(list[find_word(list, count, "dog")].n == 2);
	assert(find_word(list, count, "zebra") == -1);

	printf("helpers ok\n");
	
	count = count_words("sample.txt", list, MAX_WORDS);
	assert(count > 0);

	printf("distinct words: %d\n", count);
	for (int i = 0; i < count; i++)
		printf("%-12s %d\n", list[i].word, list[i].n);
	
	assert(count == 9);
	assert(list[find_word(list, count, "the")].n == 3);
	assert(list[find_word(list, count, "dog")].n == 2);
	printf("wordfreq: all tests passed\n");

	return 0;
}




