#include <stdio.h>

void dobrar(int *n) {
  int valor_dobrado = *n * 2;
  *n = valor_dobrado;
}

int main(void) {
  int x = 2;
  dobrar(&x);
  printf("x= %d\n", x);
}
