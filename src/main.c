#include <stdlib.h>
#include "monty.h"



int main(int ac, char** av) {
	int exit_value = EXIT_FAILURE;
	if (ac < 2) {
		printf("USAGE: monty file\n");
	} else {
		FILE*	file = fopen(av[1], "rt");
		if (file) {
			exit_value = monty_parse(file);
			fclose(file);
		} else {
			printf("Error: Can't open file %s\n", *av);
		}
	}
	return exit_value;
}