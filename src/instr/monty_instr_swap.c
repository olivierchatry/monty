#include "monty.h"

void monty_instr_swap(monty_t *monty) {
	if (monty->dlist.count < 2) {
		monty->error = MONTY_ERROR_TO_SHORT;
	} else {
		monty_value_t v1, v2;
		v1.value = monty_pop(monty);
		v2.value = monty_pop(monty);

		dlist_push_head(&(monty->dlist), v1.ptr);
		dlist_push_head(&(monty->dlist), v2.ptr);		
	}
}
