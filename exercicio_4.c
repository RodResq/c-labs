#include <stdio.h>

int main(void) {
  int idade = 30;
  int *p = &idade;
  int **pp = &p;

  printf("&idade: %p\n", (void *)&idade);
  printf("&p: %p\n", (void *)&p);
  printf("\n");

  printf("pp = %p\n", (void *)pp);
  printf("*pp= %p\n", (void *)*pp);
  printf("**pp= %d\n", **pp);

  **pp = 99;
  printf("\n idade: %d\n", idade);

  return 0;
}
