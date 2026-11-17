#ifndef PONTO_H
#define PONTO_H

typedef struct {
	int x, y;
} Ponto;

void ponto_mover(Ponto *p, int dx, int dy);

double ponto_distancia(const Ponto *a, const Ponto *b);

#endif
