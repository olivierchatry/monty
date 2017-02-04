#include <stdlib.h>

#include "monty.h"
#include "hlib/hlib.h"

void monty_remove_comment(char* content) {
	for (;*content && (*content != '#'); content++);
	*content = 0;
}

int monty_parse(char* content) {
	char		*save_ptr, *line;
	monty_t	monty;
	
	monty_init(&monty);
	line = hstrtok_r(content, "\n", &save_ptr);
	while (line && monty.error == MONTY_OK) {
		monty.line++;
		monty_remove_comment(line);
		monty_execute(&monty, line);
		line = hstrtok_r(NULL, "\n", &save_ptr);
	}
	return monty_error(&monty) ? EXIT_FAILURE : EXIT_SUCCESS;
}
