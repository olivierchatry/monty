#include "../monty.h"

void monty_instr_rotl(monty_t *monty) {
	if (monty->dl->count > 0) {
		dlist_value_t v; 
		v = dlist_pop_head(monty->dl);
		dlist_push_tail(monty->dl, v);
	}
}
