#include "../monty.h"

int	monty_instr_pall(monty_t *monty) {
	dlist_node_t*	node;

	for (node = monty->dl->head; node != NULL; node = node->next) {
		printf("%d\n", (int) node->value.as_int);
	}
	return MONTY_ERROR_NONE;
}
