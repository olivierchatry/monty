#include "monty.h"

void monty_instr_mul(monty_t *monty) {
	if (monty->dlist.count < 2) {
		monty->error = MONTY_ERROR_TO_SHORT;
	} else {
		monty_value_t v;

		v.value = monty_pop(monty) * monty_pop(monty);
		dlist_push_head(&(monty->dlist), v.ptr);
	}
}
