#include "monty.h"

void monty_push(monty_t *monty, int value) {
	monty_value_t v;
	v.value = value;
	if (monty->mode == MONTY_STACK) {
		dlist_push_head(&(monty->dlist), v.ptr);
	} else {
		dlist_push_tail(&(monty->dlist), v.ptr);
	}
}
