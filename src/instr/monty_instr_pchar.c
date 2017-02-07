#include "../monty.h"

int	monty_instr_pchar(monty_t *monty) {
	int v;

	if (monty->dl->count == 0) {
		return MONTY_ERROR_PCHAR_EMPTY;
	}
	v = monty->dl->head->value.as_int;	
	if (v > 127) {
		return MONTY_ERROR_PCHAR_OUT_RANGE;
	}
	printf("%c\n", v);
	return MONTY_ERROR_NONE;
}
