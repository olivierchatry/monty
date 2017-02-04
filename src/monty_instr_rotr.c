#include "monty.h"

void monty_instr_rotr(monty_t *monty) {
	if (monty->dlist.count > 0) {
		monty_value_t v; 
		v.ptr = dlist_pop_tail(&monty->dlist);
		dlist_push_head(&monty->dlist, v.ptr);
	}
}
