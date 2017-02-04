#include <stdlib.h>

#include "monty.h"
#include "hlib/hlib.h"

void monty_remove_comment(char* content) {
	for (;*content && (*content != '#'); content++);
	*content = 0;
}

int monty_parse(char* content) {
	char		*save_ptr, *line;
	int			status;
	monty_t	monty;
	
	monty_init(&monty);
	line = hstrtok_r(content, "\n", &save_ptr);
	while (line && monty.error == MONTY_OK) {
		monty.line++;
		monty_remove_comment(line);
		monty_execute(&monty, line);
		line = hstrtok_r(NULL, "\n", &save_ptr);
	}
	status = monty.error;
	monty_error(&monty);
	monty_free(&monty);
	return status == MONTY_OK ? EXIT_SUCCESS : EXIT_FAILURE;
}
