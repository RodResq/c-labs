#include <stddef.h>
#include <stdio.h>

/* represena os lugares */
enum { INICIO, A, B, A_OK, B_OK, FIM, N_LUGARES };

static const char *nome_lugar[N_LUGARES] = 
	{ "inicio", "a", "b", "a_ok", "b_ok", "fim" };

typedef struct {
	const char *nome;
	int entradas[2], n_entradas;
	int saidas[2], n_saidas;
} Transicao;

enum { T_FORK, T_A, T_B, T_JOIN };

static const Transicao rede[] = {
	[T_FORK] = { .nome="fork", .entradas={INICIO}, .n_entradas=1, .saidas={A, B}, .n_saidas=2 },
	[T_A] = { .nome="tarefaA", .entradas={A}, .n_entradas=1, .saidas={A_OK}, .n_saidas=1 },
	[T_B] = { "tarefaB", {B}, 1, {B_OK}, 1 },
	[T_JOIN] = { .nome="join", .entradas={A_OK, B_OK}, .n_entradas=2, .saidas={FIM}, .n_saidas=1 },
};

/* Habilitacao: Uma transicao esta habilitada quando todos os lugares de entradas dela tem pelo menos 1 token */
static int habilitada(const Transicao *t, const int marcacao[]) {
	for (int i = 0; i < t->n_entradas; i++) 
		if (marcacao[t->entradas[i]] == 0) return 0;
	return 1;
}

/* Disparo: A transicao consome um token de cada lugar de entrada e produz 1 token em cada lugar de saida. Passo atomico. */
static void disparar(const Transicao *t, int marcacao[]) {
	for (int i = 0; i < t->n_entradas; i++) marcacao[t->entradas[i]]--; /*consome */
	for (int i = 0; i < t->n_saidas; i++) marcacao[t->saidas[i]]++; /* dispara */
}

static void mostrar(const int marcacao[]) {
	for (int p = 0; p < N_LUGARES; p++)
		if (marcacao[p]) printf(" %s:%d", nome_lugar[p], marcacao[p]);
	putchar('\n');
}

int main(void) {
	/* Cada marcacao(token) e um int marcacao[], 1 = com marcacao e 0 = sem marcacao */
	int marcacao[N_LUGARES] = { [INICIO] = 1 };
	const int roteiro[] = { T_JOIN, T_FORK, T_A, T_JOIN, T_B, T_JOIN };

	printf("M0: "); mostrar(marcacao);
	for (size_t i = 0; i < sizeof roteiro / sizeof roteiro[0]; i++) {
		const Transicao *t = &rede[roteiro[i]];
		if (!habilitada(t, marcacao)) { printf("%-8s nao habilitado\n", t->nome); continue; }
		disparar(t, marcacao);
		printf("%-8s dispara ->", t->nome); mostrar(marcacao);
	}

	return 0;
}
