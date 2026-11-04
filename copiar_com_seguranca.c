#include <stdio.h>

int main(void) {
	char pequeno[4];
	snprintf(pequeno, sizeof(pequeno), "%s", "Fernanda");
	printf("%s\n", pequeno);

	return 0;
}
