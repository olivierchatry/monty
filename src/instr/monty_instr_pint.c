#include "../monty.h"

int	monty_instr_pint(monty_t *monty) {
	if (monty->dl->count == 0) {
		return MONTY_ERROR_PINT_EMPTY;
	}
	printf("%d\n", monty->dl->head->value.as_int);
	return MONTY_ERROR_NONE;
}
