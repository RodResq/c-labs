#include <stdio.h>

int main(void) {
	int idade = 30;
	int *p = &idade;

	printf("&idade = %p (onde idade mora)\n", (void *)&idade);
	printf("p = %p (o endereco guardado em p)\n", (void *)p);
	printf("&p = %p (onde o proprio p mora)\n\n", (void *)&p);
	
	unsigned char *b = (unsigned char *)&p;
	printf("bytes de p, na ordem da memoria:");
	for (size_t i = 0; i < sizeof p; i++)
		printf(" %02x", b[i]);
	printf("\n");
	
	return 0;
}
