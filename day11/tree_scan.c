#include <stdio.h>
#include <string.h>
#include "mystring.h"

struct entry {
	char dir[128];
	char name[128];
};

int load_tree(char *filename, struct entry list[], int max) {
	FILE *f = fopen(filename, "r");
	if (f == NULL) return -1;
	char line[256];
	int storedAmount = 0;
	char currDev[256];
	while ((fgets(line, sizeof(line), f) != NULL) && (storedAmount < max)) {
		trim_newline(line);
		printf("%s\n", line);
		if (strlen(line) != 0) {
			int len = strlen(line);
			if (line[len-1] == ':') {
				strcpy(currDev, line);
				currDev[len-1] = '\0';
			}
			else {
				strcpy(list[storedAmount].dir, currDev);
				strcpy(list[storedAmount].name, line);
				storedAmount += 1;
			}
		}
	}
	fclose(f);
	return storedAmount;
}

int count_in_dir(struct entry list[], int count, char *dir) {
	int scount = 0;
	for (int i = 0; i < count; i++) {
		printf("%s\n", list[i].dir);
		printf("%s\n", list[i].name);
		if (strcmp(list[i].dir, dir) == 0) {
			scount += 1;
		}
	}
	return scount;
}

int main(void) {
	struct entry list[200];
	char fileName[] = "tree.txt";
	int count = load_tree(fileName, list, 200);
	printf("count is %d\n", count);
	printf("first entry dir is %s\n", list[0].dir);
	printf("day1 files = %d\n", count_in_dir(list,count,"./day1")); 
	return 0;
}
