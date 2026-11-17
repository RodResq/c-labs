#include <stdio.h>

#ifdef DEBUG
#define LOG(msg) printf("[%s:%d] %s\n", __FILE__, __LINE__, msg)
#else
#define LOG(msg)
#endif

int main(void) {
	LOG("inicio");
	printf("trabalhando...\n");
	LOG("fim");

	return 0;
}
