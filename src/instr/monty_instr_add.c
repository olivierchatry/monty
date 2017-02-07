#include "../monty.h"

int	monty_instr_add(monty_t *monty) {
	dlist_value_t v;

	if (monty->dl->count < 2) {
		return MONTY_ERROR_TO_SHORT;
	}
	v = dlist_pop_head(monty->dl);
	monty->dl->head->value.as_int += v.as_int;
	return MONTY_ERROR_NONE;
}
