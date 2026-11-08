#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int *criar_sequencia(size_t n) {
	int *v = malloc(n * sizeof * v);
	if (v == NULL)
		return NULL;
	for (size_t i = 0; i < n; i++)
		v[i] = (int)(i + 1);
	return v;
}

int main(void) {
	size_t n;
	printf("Quantos elementos? ");
	if (scanf("%zu", &n) != 1 || n == 0)
		return 1;

	int *seq = criar_sequencia(n);
	if (seq == NULL) {
		printf("Sem memoria\n");
		return 1;
	}

	printf("seq (na stack) mora em %p\n", (void *)&seq);
	printf("seq guarda o endereco %p (bloco na heap)\n", (void *)seq);
	printf("tamanho do bloco: %zu bytes\n", n * sizeof *seq);

	for (size_t i = 0; i < n; i++)
		printf("%d", seq[i]);
	printf("\n");

	free(seq);
	seq = NULL;

	return 0;
}
