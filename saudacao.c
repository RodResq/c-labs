#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *saudacao(const char *nome) {
	const char *prefixo = "Oi, ";
	size_t tamanho = strlen(prefixo) + strlen(nome) + 1;

	char *s = malloc(tamanho);
	if (s == NULL)
		return NULL;

	snprintf(s, tamanho, "%s%s", prefixo, nome);
	return s;
}

int main(void) {
	char *a = saudacao("Ana");
	char *b = saudacao("Bruno");
	if (a == NULL || b == NULL) {
		free(a);
		free(b);

		return 1;
	}

	printf("%s\n", a);
	printf("%s\n", b);

	free(a);
	a = NULL;
	free(b); 
	b = NULL;

	return 0;
}
