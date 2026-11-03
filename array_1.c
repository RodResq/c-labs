#include <stdio.h>

int main(void) {
  int notas[4] = {7, 9, 5, 8};

  for (int i = 0; i < 4; i++)
    printf("%d ", notas[i]);
  printf("\n");

  for (int *p = notas; p < notas + 4; p++)
    printf("%d ", *p);
  printf("/n");

  return 0;
}
