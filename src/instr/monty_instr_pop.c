#include "../monty.h"

void monty_instr_pop(monty_t *monty) {
	if (monty->dl->count == 0) {
		monty->error = MONTY_ERROR_POP_EMPTY;
	} else {
		dlist_pop_head(monty->dl);
	}
}
