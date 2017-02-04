#include <stdio.h>
#include "monty.h"

void monty_instr_pall(monty_t *monty) {
	for (dlist_node_t* node = monty->dlist.head; node != NULL; node = node->next) {
		monty_value_t v;
		v.ptr = node->value;
		printf("%d\n", (int) v.value);
	}
}
