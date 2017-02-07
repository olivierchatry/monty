#include "../monty.h"

int	monty_instr_rotr(monty_t *monty) {
	if (monty->dl->count > 0) {
		dlist_value_t v;
		
		v = dlist_pop_tail(monty->dl);
		dlist_push_head(monty->dl, v);
	}
	return MONTY_ERROR_NONE;
}
