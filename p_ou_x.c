#include <stdio.h>

int main(void) {
	int x = 5;
	int *p = &x;

	printf("antes: p = %p, x = %d\n", (void *)p, x);
	*p = 9;
	printf("depois: p = %p, x = %d\n", (void *)p, x);

	return 0;
}
