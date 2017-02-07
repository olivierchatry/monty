#include <stdlib.h>
#include <string.h>
#include "../monty.h"

static int	isnumber(const char *str) {
	int ok;
		
	for (ok = 1;*str && ok; ++str) {
		char c = *str;
		ok = ((c >= '0') && (c <= '9')) || (c == '+') || (c == '-');
	}
	return ok;
}

int	monty_instr_push(monty_t *monty) {
	char					*value = strtok_r(NULL, " \t\n", &monty->save_ptr);
	dlist_value_t v;

	if (!value) {
		return MONTY_ERROR_PUSH_MISSING_ARG;
	} 
	if (!isnumber(value)) {
		return MONTY_ERROR_PUSH_INVALID_ARG;
	}
	v.as_int = atoi(value);
	if (monty->mode == MONTY_STACK) {
		dlist_push_head(monty->dl, v);
	} else {
		dlist_push_tail(monty->dl, v);
	}
	return MONTY_ERROR_NONE;
}
