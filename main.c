#include <stdio.h>
#include "ponto.h"

double quadrado(double v);

int main(void) {
	Ponto a = {0, 0}, b = {3, 4};
	printf("%.1f\n", ponto_distancia(&a, &b));

	ponto_mover(&a, 3, 0);
	printf("%.1f\n", ponto_distancia(&a, &b));

	printf("%.1f\n", quadrado(3.0));

	return 0;
}
