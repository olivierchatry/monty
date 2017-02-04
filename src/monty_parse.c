#include <stdlib.h>
#include <string.h>
#include "monty.h"

static void monty_init(monty_t *monty) {
	dlist_init(&monty->dlist);
	monty->error = MONTY_OK;
	monty->mode = MONTY_STACK; 
	monty->line = 0;
}

static void monty_free(monty_t *monty) {
	dlist_free(&monty->dlist);
}

static void monty_remove_comment(char* content) {
	for (;*content && (*content != '#'); content++);
	*content = 0;
}

int monty_parse(FILE* file) {
	char		*line;
	int			status;
	size_t	len = 0;
	monty_t	monty;
	
	monty_init(&monty);
	while ((getline(&line, &len, file) != -1) && (monty.error == MONTY_OK)) {
		monty.line++;
		monty_remove_comment(line);
		monty_execute(&monty, line);
	}
	free(line);
	status = monty.error;
	monty_error(&monty);
	monty_free(&monty);
	return status == MONTY_OK ? EXIT_SUCCESS : EXIT_FAILURE;
}
