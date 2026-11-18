#include <stdio.h>

int proximo_id(void) {
	static int ultimo = 0;
	ultimo++;
	return ultimo;
}

int main(void) {
	printf("%d  %d  %d\n", proximo_id(), proximo_id(), proximo_id());
	return 0;
}
