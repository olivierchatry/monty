#include "../monty.h"

int	monty_instr_stack(monty_t *monty) {
	monty->mode = MONTY_STACK;
	return MONTY_ERROR_NONE;
}
