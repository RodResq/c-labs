#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { VAL_INT, VAL_STRING } ValueType;

typedef struct {
	ValueType type;
	union { long i; char *s; } as;
} Value;

Value value_string(const char *s) {
	size_t n = strlen(s) + 1;
	char *copia = malloc(n);
	memcpy(copia, s, n);

	return (Value){ .type = VAL_STRING, .as.s = copia };
}

void value_free(Value *v) {
	if (v->type == VAL_STRING)
		free(v->as.s);
}

Value value_copy(const Value *v) {
	switch(v->type)	{
		case VAL_INT: return *v;
		case VAL_STRING: return value_string(v->as.s);
	}
	return *v;	
}

int main(void) {
	Value orig = value_string("pedido");
	Value copia = value_copy(&orig);

	copia.as.s[0] = 'P';
	printf("orig: %s, copia %s\n", orig.as.s, copia.as.s);

	value_free(&orig);
	value_free(&copia);

	return 0;
}

