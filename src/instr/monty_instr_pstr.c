#include "../monty.h"

void monty_instr_pstr(monty_t *monty) {
	int valid = 1;
	while (monty->dl->count != 0 && valid) {
		int val = dlist_pop_head(monty->dl).as_int;
		valid = val > 0 && val <= 127; 
		if (valid) {
			printf("%c", val);
		}
	}
	printf("\n");
}
