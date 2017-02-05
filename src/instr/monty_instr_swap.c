#include "../monty.h"

void monty_instr_swap(monty_t *monty) {
	if (monty->dl->count < 2) {
		monty->error = MONTY_ERROR_TO_SHORT;
	} else {
		dlist_value_t v1, v2;
		v1 = dlist_pop_head(monty->dl);
		v2 = dlist_pop_head(monty->dl);

		dlist_push_head(monty->dl, v1);
		dlist_push_head(monty->dl, v2);		
	}
}
