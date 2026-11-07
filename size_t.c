#include <stdio.h>
#include <string.h>

int main(void) {
	char nome[] = "Fernanda";
	
	size_t bytes = sizeof(nome);
	size_t letras = strlen(nome);

	printf("bytes do array: %zu\n", bytes);
	printf("letras: %zu\n", letras);
	printf("sizeof(size_t): %zu\n", sizeof(size_t));
	printf("sizeof(int): %zu\n", sizeof(int));
	printf("maior size_t: %zu\n", (size_t)-1);

	for (size_t i = 0; i < letras; i++) 
		printf("%c", nome[i]);
	printf("\n");

}
