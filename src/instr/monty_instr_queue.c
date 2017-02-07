#include "../monty.h"

int monty_instr_queue(monty_t *monty) {
	monty->mode = MONTY_QUEUE;
	return MONTY_ERROR_NONE;
}
