#include <stdio.h>
#include <string.h>

int main() {
	char s[] = "hello";

	printf("sizeof = %zu\n", sizeof(s));
	printf("strlen = %zu\n", strlen(s));

	for (int i = 0; i < 6; i++) {
		printf("s[%d] = %d\n", i, s[i]);
	}

	char a[] = "hello";
	char *b = "hello";

	a[0] = 'H';
	printf("a = %s\n", a);
	
	printf("b = %s\n", b);

	printf("%p %p\n", (void*)a, (void*)b);
	return 0;
}
