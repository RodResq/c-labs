#include <stdio.h>
#include <math.h>

typedef struct {
	int x, y;	
} Ponto;

void mover(Ponto *p, int dx, int dy) {
	p->x += dx;
	p->y += dy;
}

double distancia(const Ponto *a, const Ponto *b) {
	double dx = (double)b->x - a->x;
	double dy = (double)b->y - a->y;

	return sqrt(dx * dx + dy * dy);
}

void imprimir(const char *nome, const Ponto *p) {
	printf("%s = (%d, %d)\n", nome, p->x, p->y);
}

int main(void) {
	Ponto a = {0, 0};
	Ponto b = {.x = 3, .y=4};

	imprimir("a", &a);
	imprimir("b", &b);
	printf("distancia(a, b) = %.2f\n\n", distancia(&a, &b));

	mover(&a, 3, 0);
	imprimir("a depois de mover(&a, 3, 0)", &a);
	printf("distancia(a, b) = %.2f\n", distancia(&a, &b));

	return 0;
}
