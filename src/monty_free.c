#include "monty.h"

void monty_free(monty_t *monty) {
	dlist_free(&monty->dlist);
}
