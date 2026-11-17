#include <math.h>
#include "ponto.h"

void ponto_mover(Ponto *p, int dx, int dy) {
	p->x += dx;
	p->y += dy;
}

double ponto_distancia(const Ponto *a, const Ponto *b) {
	double dx = (double)b->x - a->x;
	double dy = (double)b->y - a->y;

	return sqrt(dx * dx + dy * dy);
}
