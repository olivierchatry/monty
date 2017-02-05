#include "../monty.h"

void monty_instr_add(monty_t *monty) {
	if (monty->dl->count < 2) {
		monty->error = MONTY_ERROR_TO_SHORT;
	} else {
		dlist_value_t v;
		
		v.as_int = dlist_pop_head(monty->dl).as_int;
		v.as_int += dlist_pop_head(monty->dl).as_int;
		dlist_push_head(monty->dl, v);
	}
}
