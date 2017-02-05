#include "../monty.h"

void monty_instr_pall(monty_t *monty) {
	for (dlist_node_t* node = monty->dl->head; node != NULL; node = node->next) {
		printf("%d\n", (int) node->value.as_int);
	}
}
