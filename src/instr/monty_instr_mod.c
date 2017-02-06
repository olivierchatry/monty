#include "../monty.h"

void monty_instr_mod(monty_t *monty) {
	if (monty->dl->count < 2) {
		monty->error = MONTY_ERROR_TO_SHORT;
	} else {
		dlist_value_t v;

		v = dlist_pop_head(monty->dl);
		if (v.as_int == 0) {
			monty->error = MONTY_ERROR_DIV_ZERO;
		} else {
			monty->dl->head->value.as_int %= v.as_int;
		}
	}
}
