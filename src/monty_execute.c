#include <stdlib.h>
#include <string.h>
#include "monty.h"

static monty_instruction_t	g_monty_instructions[] = {
	{"push", monty_instr_push},
	{"pall", monty_instr_pall},
	{"pop", monty_instr_pop},
	{"pint", monty_instr_pint},
	{"swap", monty_instr_swap},
	{"add", monty_instr_add},
	{"nop", monty_instr_nop},
	{"sub", monty_instr_sub},
	{"mul", monty_instr_mul},
	{"div", monty_instr_div},
	{"mod", monty_instr_mod},
	{"pchar", monty_instr_pchar},
	{"pstr", monty_instr_pstr},
	{"rotl", monty_instr_rotl},
	{"rotr", monty_instr_rotr},
	{"queue", monty_instr_queue},
	{"stack", monty_instr_stack},
	{"clear", monty_instr_clear},
	{NULL, NULL}
};

void monty_execute(monty_t *monty, char *line) {
	monty_instruction_t	*instr;
	
	monty->token = strtok_r(line, " \t\n", &monty->save_ptr);
	if (monty->token) {
		for (instr = g_monty_instructions; instr->opcode && strcmp(instr->opcode, monty->token); instr++);
		if (instr->fun) {
			instr->fun(monty);
		} else {
			monty->error = MONTY_ERROR_INVALID_OPCODE;
		}
	}
}
