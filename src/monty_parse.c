#include <stdlib.h>
#include <string.h>
#include "monty.h"

static void monty_init(monty_t *monty) {
	monty->dl = calloc(sizeof(dlist_t), 1);
	dlist_init(monty->dl);
	monty->mode = MONTY_STACK; 
	monty->line = 0;
}

static void monty_free(monty_t *monty) {
	dlist_free(monty->dl);
	free(monty->dl);
}

static void monty_remove_comment(char *content) {
	for (;*content && (*content != '#'); content++);
	*content = 0;
}

int monty_parse(FILE *file) {
	char		*line;
	int			error = MONTY_ERROR_NONE;
	size_t	len = 0;
	monty_t	monty;
	
	monty_init(&monty);
	while ((error == MONTY_ERROR_NONE) && (getline(&line, &len, file) != -1)) {
		monty.line++;
		monty_remove_comment(line);
		error = monty_execute(&monty, line);
	}
	monty_error(&monty, error);
	monty_free(&monty);
	free(line);
	return error;
}
