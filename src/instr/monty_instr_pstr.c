#include "monty.h"

void monty_instr_pstr(monty_t *monty) {
	int valid = 1;
	while (monty->dlist.count != 0 && valid) {
		int val = monty_pop(monty);
		valid = val > 0 && val <= 127; 
		if (valid) {
			printf("%c", val);
		}
	}
	printf("\n");
}
