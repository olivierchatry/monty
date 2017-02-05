#include "../monty.h"

void monty_instr_pint(monty_t *monty) {
	if (monty->dl->count == 0) {
		monty->error = MONTY_ERROR_PINT_EMPTY;
	} else {
		printf("%d\n", monty->dl->head->value.as_int);
	}
}
