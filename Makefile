BUILD_DIR = ./build
TARGET=monty

SRCS=src/main.c \
	src/dlist/dlist.c \
	src/hlib/hlib.c \
	src/utils/util_read_file.c \
	src/monty_error.c \
	src/monty_execute.c \
	src/monty_free.c \
	src/monty_init.c \
	src/monty_parse.c \
	src/monty_pop.c \
	src/monty_push.c \
	src/monty_peek.c \
	src/monty_instr_pall.c \
	src/monty_instr_pop.c \
	src/monty_instr_push.c \
	src/monty_instr_pint.c \
	src/monty_instr_swap.c \
	src/monty_instr_add.c \
	src/monty_instr_nop.c \
	src/monty_instr_sub.c \
	src/monty_instr_mul.c \
	src/monty_instr_div.c \
	src/monty_instr_mod.c \
	src/monty_instr_pchar.c \
	src/monty_instr_pstr.c \
	src/monty_instr_rotl.c \
	src/monty_instr_rotr.c \
	src/monty_instr_queue.c \
	src/monty_instr_stack.c

OBJS = $(SRCS:%.c=$(BUILD_DIR)/%.o)
DEPS=$(OBJS:%.o=%.d)
CFLAGS=-I. -I./src -g -O0 -Wall -Werror -Wextra -pedantic
RM=rm -f

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC)  $(CFLAGS) $(INCLUDES) -o $(TARGET) $(OBJS) $(LFLAGS) $(LIBS)

-include $(DEPS)

$(BUILD_DIR)/%.o : %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -MMD -c $< -o $@

.PHONY : clean
clean:
	$(RM) $(OBJS) $(DEPS) $(TARGET) vgcore*
