#include "../monty.h"


static int monty_print_elem(void *user_data, dlist_value_t value) {
	UNUSED(user_data);
	if ( (value.as_int > 0) && (value.as_int <= 127) ) {
		printf("%c", value.as_int);
		return DLIST_CONTINUE;
	}
	return DLIST_STOP;
}

void monty_instr_pstr(monty_t *monty) {
	dlist_apply_head_to_tail(monty->dl, NULL, monty_print_elem);
	printf("\n");
}
