#include "../monty.h"

int	monty_instr_pop(monty_t *monty) {
	if (monty->dl->count == 0) {
		return MONTY_ERROR_POP_EMPTY;
	}
	dlist_pop_head(monty->dl);
	return MONTY_ERROR_NONE;
}
