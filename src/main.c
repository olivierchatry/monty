#include <stdlib.h>
#include <string.h>
#include "monty.h"



int main(int ac, char** av) {
	int exit_value = EXIT_FAILURE;
	
	if (ac < 2) {
		printf("USAGE: monty file\n");
	} else {
		FILE*	file = strcmp(av[1], "stdin") == 0 ? stdin : fopen(av[1], "rt");

		if (file) {
			exit_value = (monty_parse(file) == MONTY_ERROR_NONE) ? EXIT_SUCCESS : EXIT_FAILURE;
			fclose(file);
		} else {
			printf("Error: Can't open file %s\n", *av);
		}
	}
	return exit_value;
}