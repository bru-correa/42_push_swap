# ********** MUTE MAKEFILE ********** #
ifndef VERBOSE
.SILENT:
endif

# ********** VARIABLES ********** #
RED					= \033[1;31m
YELLOW				= \033[1;33m
GREEN				= \033[1;32m
NOCOLOR				= \033[0m
DONE_MSG			= "$(GREEN)Done!$(NOCOLOR)"
COMPILING_MSG		= "$(YELLOW)Compiling...$(NOCOLOR)"
CLEANING_MSG		= "$(RED)Cleaning up...$(NOCOLOR)"

NAME				= push_swap
CC					= gcc
CFLAGS				= -Wall -Wextra -Werror -I$(LIBFT_DIR) -I$(INCLUDE_DIR)
CFLAGS_LIB			= -lft -L $(LIBFT_DIR)

INCLUDE_DIR			= include
SRC_DIR				= src
OBJ_DIR				= obj
LIB_DIR				= lib
LIBFT_DIR			= lib/libft

SRC_FILES			= $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES			= $(patsubst %, $(OBJ_DIR)/%.o, \
						$(basename $(notdir $(SRC_FILES))))

MAIN				= push_swap.c

VALGRIND			= valgrind --leak-check=full --show-leak-kinds=all
VALGRIND			+= --track-origins=yes --quiet --tool=memcheck

# ********** TESTS VARIABLES ********** #

# HACK: Remove this before final commit!!!
TEST_DIR			= ./tests
TEST_SRC_DIR		= $(TEST_DIR)/src
TEST_OBJ_DIR		= $(TEST_DIR)/obj
TEST_SRC_FILES		= $(wildcard $(TEST_SRC_DIR)/*.c)
TEST_OBJ_FILES		= $(patsubst %, $(TEST_OBJ_DIR)%.o, \
					  	$(basename $(notdir $(TEST_SRC_FILES))))
TEST_MAIN			= tests.c

# ********** RULES ********** #

all:				$(NAME)

$(NAME):			required
					$(CC) $(MAIN) $(OBJ_FILES) $(CFLAGS) $(CFLAGS_LIB) \
						-o $(NAME)
					echo $(DONE_MSG)

# Compile required src files
required:			compile_message $(OBJ_DIR) $(OBJ_FILES) libft

libft:
					$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR):
					mkdir -p $@

$(OBJ_DIR)/%.o:		$(SRC_DIR)/%.c
					$(CC) -c $< $(CFLAGS) -o $@

clean:
					echo $(CLEANING_MSG)
					rm -rf $(OBJ_DIR)
					$(MAKE) -C $(LIBFT_DIR) clean

fclean:				clean
					rm -f $(NAME)
					$(MAKE) -C $(LIBFT_DIR) fclean

re:					fclean all

re_bonus:			fclean bonus

compile_message:
					echo $(COMPILING_MSG)


# Add -g flag and change output to debug
setup_debug:
					$(eval NAME=debug)
					$(eval CFLAGS+=-g)

# Compile with -g flag and output the 'debug' file
debug:				clean setup_debug all compile_message
					# gdb --quiet ./debug -tui

valgrind:			all
					$(VALGRIND) ./$(NAME) 1 2 3 4 5

# ********** TESTS RULES ********** #

# tests:				all compile_message 
# 					./tests/test.sh

test:				all compile_message
					cp push_swap tester/push_swap
					bash tester/tester.sh

stest:				all compile_message
					./tests/simple_test.sh

# TODO: Make tests download my test repo

.PHONY:	all run clean fclean re re_bonus libft debug setup_debug tests
