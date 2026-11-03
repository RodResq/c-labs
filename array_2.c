#include <stdio.h>

double media(const int *v, size_t n) {
  int soma = 0;
  for (size_t i = 0; i < n; i++)
    soma += v[i];
  return (double)soma / n;
}

int main(void) {
  int notas[4] = {7, 9, 5, 8};
  size_t n = sizeof(notas) / sizeof(notas[0]);
  printf("media: %.2f\n", media(notas, n));
  return 0;
}
