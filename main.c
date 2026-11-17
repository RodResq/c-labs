#include <stdio.h>
#include "ponto.h"

int main(void) {
	Ponto a = {0, 0}, b = {3, 4};
	printf("%.1f\n", ponto_distancia(&a, &b));

	ponto_mover(&a, 3, 0);
	printf("%.1f\n", ponto_distancia(&a, &b));

	return 0;
}
