#include "monty.h"

void monty_init(monty_t *monty) {
	dlist_init(&monty->dlist);
	monty->error = MONTY_OK;
	monty->mode = MONTY_STACK; 
	monty->line = 0;
}
