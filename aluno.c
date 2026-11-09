#include <stddef.h>
#include <stdio.h>
#include <string.h>

typedef struct {
	char nome[50];
	int idade;
	double media;
} Aluno;

void imprimir(const Aluno *a) {
	printf("%-8s %3ds anos media %.1f\n", a->nome, a->idade, a->media);
}

void aniversario_errado(Aluno a) {
	a.idade++;
}

void aniversario(Aluno *a) {
	a->idade++;
}

int main(void) {
	Aluno turma[3] = {
		{"Ana", 20, .5},
		{.nome = "Bruno", .idade = 22},
		{"Carla", 19, 9.0},
	};
	size_t n = sizeof turma / sizeof turma[0];

	printf("sizeof(Aluno) = %zu bytes\n", sizeof(Aluno));
	printf("soma dos campos = %zu bytes\n\n", 
			sizeof turma[0].nome + sizeof turma[0].idade + sizeof turma[0].media);

	aniversario_errado(turma[0]);
	aniversario(&turma[1]);

	for (size_t i = 0; i < n; i++)
		imprimir(&turma[i]);

	Aluno copia = turma[2];
	strcpy(copia.nome, "Copia");
	printf("\noriginal: %s, copia: %s\n", turma[2].nome, copia.nome);

	return 0;
}
