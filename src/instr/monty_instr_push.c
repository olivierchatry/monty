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

void monty_instr_push(monty_t *monty) {
	char	*value = strtok_r(NULL, " \t\n", &monty->save_ptr);

	if (!value) {
		monty->error = MONTY_ERROR_PUSH_MISSING_ARG;
	} else if (!isnumber(value)) {
		monty->error = MONTY_ERROR_PUSH_INVALID_ARG;
	} else {
		dlist_value_t v;

		v.as_int = atoi(value);
		if (monty->mode == MONTY_STACK) {
			dlist_push_head(monty->dl, v);
		} else {
			dlist_push_tail(monty->dl, v);
		}
	}
}
