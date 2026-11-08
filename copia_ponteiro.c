#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int *x = malloc(sizeof *x);
	int *y = malloc(sizeof *y);

	if (x == NULL || y == NULL) {
		free(x);
		free(y);
		return 1;
	}

	int *z = x;

	*x = 1;
	*y = 2;
	*z = 3;

	printf("x guarda %p, *x = %d\n", (void *)x, *x);
	printf("y guarda %p, *y = %d\n", (void *)y, *y);
	printf("z guarda %p, *z = %d\n", (void *)z, *z);

	free(x);
	free(y);
	/* free(z);

	return 0;
}
