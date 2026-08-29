#include <stdio.h>
#include <string.h>

struct entry {
	char dir[128];
	char name[128];
};

int main(void) {
	struct entry e;

	strcpy(e.dir, "./day6");
	strcpy(e.name, "mystring.c");

	printf("%s/%s\n", e.dir, e.name);
	printf("sizeof(struct entry) = %zu\n", sizeof(struct entry));

	struct entry list[3];
	strcpy(list[0].dir, "./day1");
	strcpy(list[0].name, "notes.txt");
	printf("%s/%s\n", list[0].dir, list[0].name);

	return 0;
}
