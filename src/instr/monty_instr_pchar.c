#include "monty.h"

void monty_instr_pchar(monty_t *monty) {
	if (monty->dlist.count == 0) {
		monty->error = MONTY_ERROR_PCHAR_EMPTY;
	} else {
		int v = monty_pop(monty);
		if (v >= 0 && v <= 127) {
			printf("%c\n", v);
		} else {
			monty->error = MONTY_ERROR_PCHAR_OUT_RANGE;
		}
	}
}
