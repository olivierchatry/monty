#include "monty.h"

void monty_instr_sub(monty_t *monty) {
	if (monty->dlist.count < 2) {
		monty->error = MONTY_ERROR_TO_SHORT;
	} else {
		int v1 = monty_pop(monty);
		int v2 = monty_pop(monty);
		monty_push(monty, v2 - v1);
	}
}
