#include "monty.h"

void monty_instr_pint(monty_t *monty) {
	if (monty->dlist.count == 0) {
		monty->error = MONTY_ERROR_PINT_EMPTY;
	} else {
		monty_value_t v;
		v.ptr = monty->dlist.head->value;
		printf("%d\n", v.value);
	}
}
