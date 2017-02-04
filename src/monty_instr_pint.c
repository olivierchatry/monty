#include <stdio.h>
#include "monty.h"

void monty_instr_pint(monty_t *monty) {
	if (monty->dlist.count == 0) {
		monty->error = MONTY_ERROR_PINT_EMPTY;
	} else {
		printf("%d\n", monty_peek(monty));
	}
}
