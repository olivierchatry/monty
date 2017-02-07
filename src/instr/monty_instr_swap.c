#include "../monty.h"

int	monty_instr_swap(monty_t *monty) {
	dlist_value_t v1, v2;

	if (monty->dl->count < 2) {
		return MONTY_ERROR_TO_SHORT;
	}
	v1 = dlist_pop_head(monty->dl);
	v2 = dlist_pop_head(monty->dl);
	dlist_push_head(monty->dl, v1);
	dlist_push_head(monty->dl, v2);		
	return MONTY_ERROR_NONE;
}
