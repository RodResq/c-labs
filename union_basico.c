#include <stdio.h>
#include <stddef.h>

union U {
	int i;
	double d;
	char c;
};

int main(void) {
	union U u;

	printf("sizeof(union U) = %zu\n", sizeof u);
	printf("offsets: i=%zu d=%zu c=%zu\n\n", 
			offsetof(union U, i), offsetof(union U, d), offsetof(union U, c));

	printf("&u.i = %p\n&u.d = %p\n&u.c = %p\n\n", 
			(void *)&u.i, (void *)&u.d, (void *)&u.c);

	u.i = 65;
	printf("depois do u.i = 65: u.i = %d, u.c = '%c'\n", u.i, u.c);

	u.d = 3.14;
	printf("depois do u.d = 3.14: u.d = %.2f, u.i = '%d'\n", u.d, u.i);

	return 0;
}
