#include <stdio.h>
#include <stdlib.h>

int global_int = 42;
int global_zero;

int main(void) {
  int local = 1;
  int *heap = malloc(sizeof *heap);

  printf("codgio (main) %p\n", (void *)main);
  printf(".data  %p\n", (void *)&global_int);
  printf(".bss %p\n", (void *)&global_zero);
  printf("heap (malloc) %p\n", (void *)heap);
  printf("libc (printf) %p\n", (void *)printf);
  printf("pilha (local) %p\n", (void *)&local);

  free(heap);
  return 0;
}
