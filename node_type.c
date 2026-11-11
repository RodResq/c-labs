#include <stdio.h>
#include <string.h>

typedef enum {
	NODE_START, NODE_END, NODE_STATE, NODE_FORK, NODE_JOIN, NODE_DECISION, NODE_TYPE_COUNT
} NodeType;

static const char *const NODE_TYPE_NOME[NODE_TYPE_COUNT] = {
	[NODE_START] = "start-state",
	[NODE_END] = "end-state",
	[NODE_STATE] = "state",
	[NODE_FORK] = "fork",
	[NODE_JOIN] = "join",
	[NODE_DECISION] = "decision"
};

const char *node_type_str(NodeType t) { 
	if (t < 0 || t >= NODE_TYPE_COUNT || NODE_TYPE_NOME[t] == NULL) 
		return "(invalido)";
	return NODE_TYPE_NOME[t];
};

int node_type_parse(const char *s, NodeType *saida) {
	for (int t = 0; t < NODE_TYPE_COUNT; t++) {
		if (NODE_TYPE_NOME[t] != NULL && strcmp(s, NODE_TYPE_NOME[t]) == 0) {
			*saida = (NodeType)t;
			return 0;
		}
	}
	return -1;
}

const char *comportamento(NodeType t) {
	switch(t) {
		case NODE_START:
		case NODE_STATE: return "espera um sinal";
		case NODE_END: return "encerra";
		case NODE_FORK: return "divide o token";
		case NODE_JOIN: return "sincroniza os tokens";
		case NODE_DECISION: return "decisao";
		case NODE_TYPE_COUNT: break;
	}
	return "(invalido)";
};

int main(void) {
	printf("sizeof(NodeType) = %zu\n\n", sizeof(NodeType));

	for (int t = 0; t < NODE_TYPE_COUNT; t++) 
		printf("%d %-12s %s\n", t, node_type_str((NodeType)t), comportamento((NodeType)t));

	const char *entradas[] = {"fork", "decision"};
	for (size_t i = 0; i < 2; i++) {
		NodeType t;
		if (node_type_parse(entradas[i], &t) == 0) 
			printf("\n\"%s\" -> %d", entradas[i], t);
		else	
			printf("\n\"%s\" -> nao reconhecido", entradas[i]);
	}
	printf("\n");

	NodeType lixo = 42;
	printf("\nvalor 42: %s\n", node_type_str(lixo));

	return 0;
}
