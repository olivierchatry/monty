#include "monty.h"

int	monty_peek(monty_t *monty) {
	monty_value_t v;
	v.ptr = monty->dlist.head->value;
	return v.value;
}
