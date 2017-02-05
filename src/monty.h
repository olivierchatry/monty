#ifndef __MONTY_H__
#define __MONTY_H__

#include <stdio.h>
#include "dlist/dlist.h"

#define UNUSED(x) (void)x

#define MONTY_OK 0
#define MONTY_ERROR 1
#define MONTY_ERROR_INVALID_OPCODE 1
#define MONTY_ERROR_PUSH_MISSING_ARG 2
#define MONTY_ERROR_PUSH_INVALID_ARG 3
#define MONTY_ERROR_PINT_EMPTY 4
#define MONTY_ERROR_POP_EMPTY 5
#define MONTY_ERROR_TO_SHORT 6
#define MONTY_ERROR_DIV_ZERO 7
#define MONTY_ERROR_PCHAR_EMPTY 8
#define MONTY_ERROR_PCHAR_OUT_RANGE 9

#define MONTY_STACK 0
#define MONTY_QUEUE 1


struct monty_s {
	char			*save_ptr;
	int				line;
	char			*token;
	dlist_t		*dl;
	int				mode;
	int				error;
};
 
typedef struct monty_s monty_t;

struct monty_instruction_s {
	const char	*opcode;
	void				(*fun)(monty_t *monty);
};
typedef struct monty_instruction_s monty_instruction_t;

int		monty_parse(FILE *file);
void	monty_error(monty_t* monty);
void	monty_execute(monty_t *monty, char *line);

void	monty_instr_push(monty_t *monty);
void	monty_instr_pall(monty_t *monty);
void	monty_instr_pop(monty_t *monty);
void	monty_instr_pint(monty_t *monty);
void	monty_instr_swap(monty_t *monty);
void	monty_instr_add(monty_t *monty);
void	monty_instr_nop(monty_t *monty);
void	monty_instr_sub(monty_t *monty);
void	monty_instr_mul(monty_t *monty);
void	monty_instr_div(monty_t *monty);
void	monty_instr_mod(monty_t *monty);
void	monty_instr_pchar(monty_t *monty);
void	monty_instr_pstr(monty_t *monty);
void	monty_instr_rotl(monty_t *monty);
void	monty_instr_rotr(monty_t *monty);
void	monty_instr_stack(monty_t *monty);
void	monty_instr_queue(monty_t *monty);

#endif