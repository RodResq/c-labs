#include <stdio.h>

int main(void) {
	char a[10] = "Ana";
	char *p = a;

	p[0] = 'E';
	printf("%s\n", a);

	return 0;
}
