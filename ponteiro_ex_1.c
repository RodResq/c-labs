#include <stdio.h>

int main(void) {
  int a = 10;
  int *p;

  p = &a;

  printf("&a = %p  (onde a mora)\n", (void *)&a);
  printf("a = %d  (o que a grava)\n", a);
  printf("\n");
  printf("&p = %p  (onde p mora)\n", (void *)&p);
  printf("p = %p  (o que p guarda: igual a &a)\n", (void *)p);
  printf("*p = %d  (o que esta no endereço guardado em p)\n", *p);

  printf("teste");
  
  *p = 15;
  printf("\n depois de *p = 15: a = %d\n", a);

  return 0;
}
