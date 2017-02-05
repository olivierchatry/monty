#include "../monty.h"

void monty_instr_clear(monty_t *monty) {
	dlist_free(monty->dl);
}
