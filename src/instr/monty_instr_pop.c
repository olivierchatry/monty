#include "monty.h"

void monty_instr_pop(monty_t *monty) {
	if (monty->dlist.count == 0) {
		monty->error = MONTY_ERROR_POP_EMPTY;
	} else {
		monty_pop(monty);
	}
}
