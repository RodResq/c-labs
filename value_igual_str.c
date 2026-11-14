#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef enum { VAL_NULL, VAL_INT, VAL_DOUBLE, VAL_STRING } ValueType;

typedef struct {
	ValueType type;
	union { long i; double d; const char *s; } as;
} Value;

bool value_equals(const Value *a, const Value *b) {
	if (a->type != b->type)
		return false;

	switch (a->type) {
		case VAL_NULL: return true;
		case VAL_INT: return a->as.i == b->as.i;
		case VAL_DOUBLE: return a->as.d == b->as.d;
		case VAL_STRING: return strcmp(a->as.s, b->as.s) == 0;
	}
	return false;
}

int main(void) {
	char t1[] = "ok";
	char t2[] = "ok";
	
	Value n = { .type = VAL_NULL };

	Value a = { .type = VAL_INT, .as.i = 10 };
	Value b = { .type = VAL_INT, .as.i = 10 };

	Value s1 = { .type = VAL_STRING, .as.s = t1 };
	Value s2 = { .type = VAL_STRING, .as.s = t2 };
	Value s3 = { .type = VAL_STRING, .as.s = "nao" };

	printf("%d %d\n", 
			value_equals(&s1, &s2), 
			value_equals(&s1, &s3));

	printf("%d\n", value_equals(&a, &b));
	printf("%d\n", value_equals(&n, &n));
	
	return 0;

}
