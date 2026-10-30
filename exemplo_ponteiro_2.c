#include <stdio.h>

void trocar(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int main(void) {
  int x = 1, y = 2;
  trocar(&x, &y);
  printf("x = %d, y = %d\n", x, y);

  return 0;
}
