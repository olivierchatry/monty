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
		monty_push(monty, hatoi(value));
	}
}
