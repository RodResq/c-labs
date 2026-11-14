#include <stdio.h>
#include <stdbool.h>

typedef enum { VAL_NULL, VAL_INT, VAL_DOUBLE } ValueType;

typedef struct {
	ValueType type;
	union { long i; double d; } as;
} Value;

bool value_equals(const Value *a, const Value *b) {
    	if (a->type != b->type)	
		return false;
	
	switch(a->type){
		case VAL_NULL: return true;
		case VAL_INT: return a->as.i == b->as.i;
		case VAL_DOUBLE: return a->as.d == b->as.d;
	}

	return false;
}

int main(void) {
	Value a = { .type = VAL_INT, .as.i = 10 };
	Value b = { .type = VAL_INT, .as.i = 10 };
	Value c = { .type = VAL_DOUBLE, .as.d = 10.0 };
	Value n = { .type = VAL_NULL };

	printf(" %d %d %d %d\n", 
			value_equals(&a, &b), 
			value_equals(&a, &c), 
			value_equals(&n, &n), 
			value_equals(&a, &n));

	return 0;
	
}
