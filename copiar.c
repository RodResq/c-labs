#include <stdio.h>
#include <string.h>

void copiar(char *dest, const char *origin) {
	size_t i = 0;
	while (origin[i] != '\0') {
		dest[i] = origin[i];
		i++;
	}
	dest[i] = '\0';
}

int main(void) {
	char a[10] = "Ana";
	char b[10];
	
	strcpy(b, a);

	printf("valor de b[10] = %s\n", b);
	return 0;
}
