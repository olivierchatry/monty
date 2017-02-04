#include "monty.h"

void monty_instr_rotl(monty_t *monty) {
	if (monty->dlist.count > 0) {
		monty_value_t v; 
		v.ptr = dlist_pop_head(&monty->dlist);
		dlist_push_tail(&monty->dlist, v.ptr);
	}
}
