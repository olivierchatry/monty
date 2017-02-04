#include <stdlib.h>
#include "monty.h"
#include "hlib/hlib.h"

void monty_instr_push(monty_t *monty) {
	char	*value = hstrtok_r(NULL, " \t", &monty->save_ptr);
	if (!value) {
		monty->error = MONTY_ERROR_PUSH_MISSING_ARG;
	} 
	else if (!hisnumber(value)) {
		monty->error = MONTY_ERROR_PUSH_INVALID_ARG;
	} else {
		monty_value_t v;
		v.value = hatoi(value);
		if (monty->mode == MONTY_STACK) {
			dlist_push_head(&(monty->dlist), v.ptr);
		} else {
			dlist_push_tail(&(monty->dlist), v.ptr);
		}
	}
}
