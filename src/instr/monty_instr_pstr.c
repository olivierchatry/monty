#include "../monty.h"

void monty_instr_pstr(monty_t *monty) {
	int valid = 1;
	
	for (dlist_node_t* node = monty->dl->head; (node != NULL) && valid; node = node->next) {
		dlist_value_t val = node->value;
		
		valid = val.as_int > 0 && val.as_int <= 127; 
		if (valid) {
			printf("%c", val.as_int);
		}
	}
	printf("\n");
}
