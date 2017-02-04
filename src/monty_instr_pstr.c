#include <stdio.h>
#include "monty.h"

void monty_instr_pstr(monty_t *monty) {
	int val = 1;
	while (monty->dlist.count != 0 && val > 0 && val <= 127) {
		val = monty_pop(monty);
		printf("%c", val);
	}
	printf("\n");
}
