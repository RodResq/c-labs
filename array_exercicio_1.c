#include <stdio.h>

int main(void) {
  int ni[4] = {7, 9, 5, 8};
  char nc[4] = {'a', 'b', 'c', 'd'};

  printf("int:\n");
  for (int *p = ni; p < ni + 4; p++)
    printf(" %p (+%td bytes)\n", (void *)p, (char *)p - (char *)ni);

  printf("char: \n");
  for (char *p = nc; p < nc + 4; p++)
    printf(" %p (+%td bytes)\n", (void *)p, p - nc);

  return 0;
}
