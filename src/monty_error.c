#include "monty.h"

void monty_error(monty_t* monty) {
	switch (monty->error) {
		case MONTY_OK:
			break;
		case MONTY_ERROR_INVALID_OPCODE:
			printf("L%d: unknow instruction %s\n", monty->line, monty->token);
			break;
		case MONTY_ERROR_PUSH_MISSING_ARG:
		case MONTY_ERROR_PUSH_INVALID_ARG:
			printf("L%d: usage push integer\n", monty->line);
			break;
		case MONTY_ERROR_POP_EMPTY:
			printf("L%d: can't pop an empty stack\n", monty->line);
			break;
		case MONTY_ERROR_PCHAR_EMPTY:
		case MONTY_ERROR_PINT_EMPTY:
			printf("L%d: can't %s, stack empty\n", monty->line, monty->token);
			break;
		case MONTY_ERROR_TO_SHORT:
			printf("L%d: can't %s, stack too short\n", monty->line, monty->token);
			break;
		case MONTY_ERROR_DIV_ZERO:
			printf("L%d: division by zero\n", monty->line);
			break;
		case MONTY_ERROR_PCHAR_OUT_RANGE:
			printf("L%d: can't pchar, value out of range\n", monty->line);
			break;		
		default:
			printf("L%d: unknow error\n", monty->line);
	}
}
