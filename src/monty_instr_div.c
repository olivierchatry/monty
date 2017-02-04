#include "monty.h"

void monty_instr_div(monty_t *monty) {
	if (monty->dlist.count < 2) {
		monty->error = MONTY_ERROR_TO_SHORT;
	} else {
		int v1 = monty_pop(monty);
		if (v1 == 0) {
			monty->error = MONTY_ERROR_DIV_ZERO;
		} else {
			monty_value_t v;
			v.value = monty_pop(monty) / v1;
			dlist_push_head(&(monty->dlist), v.ptr);
		}
	}
}
