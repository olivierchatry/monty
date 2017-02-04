#include <stdio.h>
#include <stdlib.h>
#include <hlib/hlib.h>
#include <utils/utils.h>
#include "monty.h"



int main(int ac, char** av) {
	int exit_value = EXIT_FAILURE;
	if (ac < 2) {
		printf("USAGE: monty file\n");
	} else {
		char* monty = util_read_file(*(++av));
		if (monty) {
			exit_value = monty_parse(monty);
			free(monty);
		} else {
			printf("Error: Can't open file %s\n", *av);
		}
	}
	return exit_value;
}