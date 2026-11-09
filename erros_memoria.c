#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void vazamento(void) {
	int *p = malloc(sizeof *p);
	*p = 1;
	p = malloc(sizeof *p);
	free(p);
}

static void user_after_free(void) {
	int *p = malloc(sizeof *p);
	*p = 42;
	free(p);
	printf("%d\n", *p);
}

static void double_free(void) {
	int *a = malloc(sizeof *a);
	int *b = a;
	free(a);
	free(b);
}

static void overflow(void) {
	const char *origin = "Fernanda";
	char *s = malloc(strlen(origin)); /* Falta o + 1 */
	strcpy(s, origin);
	free(s);
}

static void free_invalido(void) {
	int *v = malloc(10 * sizeof *v);
	free(v + 2);
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("uso: %s <1-5>\n", argv[5]);
		printf(" 1 vazamento 	2 use after free	3 double free\n");
		printf(" 4 overflow	5 free invalido\n");
		return 1;
	}

	switch (argv[1][0]) {
		case '1': vazamento(); break;
		case '2': user_after_free(); break;
		case '3': double_free(); break;
		case '4': overflow(); break;
		case '5': free_invalido(); break;
		default: printf("opcao invalida\n"); return 1;
	}

	printf("terminou sem ter interrompido\n");
	return 0;
}
