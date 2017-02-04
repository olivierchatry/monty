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
	src/instr/monty_instr_pall.c \
	src/instr/monty_instr_pop.c \
	src/instr/monty_instr_push.c \
	src/instr/monty_instr_pint.c \
	src/instr/monty_instr_swap.c \
	src/instr/monty_instr_add.c \
	src/instr/monty_instr_nop.c \
	src/instr/monty_instr_sub.c \
	src/instr/monty_instr_mul.c \
	src/instr/monty_instr_div.c \
	src/instr/monty_instr_mod.c \
	src/instr/monty_instr_pchar.c \
	src/instr/monty_instr_pstr.c \
	src/instr/monty_instr_rotl.c \
	src/instr/monty_instr_rotr.c \
	src/instr/monty_instr_queue.c \
	src/instr/monty_instr_stack.c

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
