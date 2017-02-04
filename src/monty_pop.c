#include "monty.h"

int	monty_pop(monty_t *monty) {
	monty_value_t v;
	v.ptr = dlist_pop_head(&(monty->dlist));
	return v.value;
}
