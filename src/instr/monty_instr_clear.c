#include "../monty.h"

int	monty_instr_clear(monty_t *monty) {
	dlist_free(monty->dl);
	return MONTY_ERROR_NONE;
}
