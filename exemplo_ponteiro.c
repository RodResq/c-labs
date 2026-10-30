#include <stdio.h>

int main(void) {
  int idade = 30;
  int *p = &idade;

  printf("idade: %d\n", idade);
  printf("p: %p\n", p);
  printf("*p: %d\n", *p);

  *p = 31;
  printf("idade: %d\n", idade);

  return 0;
}
