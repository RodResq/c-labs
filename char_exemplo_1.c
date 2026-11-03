#include <stdio.h>

size_t tamanho(const char *s) {
  size_t n = 0;
  while (s[n] != '\0')
    n++;
  return n;
}

int main(void) {
  char nome[] = "Ana";
  printf("%zu\n", tamanho(nome));
  return 0;
}
