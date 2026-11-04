#include <stdio.h>
#include <string.h>

void dentro_da_funcao(const char *s) {
	printf(" na função sizeof = %zu, strlen = %zu\n", sizeof(s), strlen(s));
}

int main(void) {
	char nome[] = "Ana";
	char buf[50] = "Ana";
	const char *ptr = "Ana";

	printf("nome[]: sizeof = %zu, strlen = %zu\n", sizeof(nome), strlen(nome));
	printf("buf[50]: sizeof = %zu, strlen = %zu\n", sizeof(buf), strlen(buf));
	printf("ptr: sizeof = %zu, strlen = %zu\n", sizeof(ptr), strlen(ptr));

	printf("\npassando nome para a funcao:\n");
	dentro_da_funcao(nome);

	buf[1] = '\0';
	printf("\nbuf apos buf[1] = '\\0': sizeof = %zu, strlen = %zu, texto = \"%s\"\n", sizeof(buf), strlen(buf), buf);

	return 0;
}
