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
CFLAGS				= -Wall -Wextra -Werror $(CFLAGS_LIBFT) -I$(INCLUDE_DIR)
CFLAGS_LIBFT		= -lft -L $(LIBFT_DIR) -I $(LIBFT_DIR)

INCLUDE_DIR			= include
SRC_DIR				= src
OBJ_DIR				= obj
LIB_DIR				= lib
LIBFT_DIR			= lib/libft

SRC_FILES			= $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES			= $(patsubst %, $(OBJ_DIR)/%.o, \
						$(basename $(notdir $(SRC_FILES))))

MAIN				= push_swap.c

# ********** TESTS VARIABLES ********** #
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
					$(CC) -g $(MAIN) $(OBJ_FILES) $(CFLAGS) -o $(NAME)
					echo $(DONE_MSG)

required:			compile_message $(OBJ_DIR) $(OBJ_FILES) libft

libft:
					$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR):
					mkdir -p $@

$(OBJ_DIR)/%.o:		$(SRC_DIR)/%.c
					$(CC) -c -g $< $(CFLAGS) -o $@

clean:
					echo $(CLEANING_MSG)
					rm -rf $(OBJ_DIR)

fclean:				clean
					rm -f $(NAME)

re:					fclean all

re_bonus:			fclean bonus

compile_message:
					echo $(COMPILING_MSG)

debug:				setup_debug all compile_message

setup_debug:
					$(eval NAME=debug)
					$(eval CFLAGS+=-g)

# ********** TESTS RULES ********** #
tests:				all compile_message 
					./tests/test.sh

# TODO: Make the debug file for x test (check makefile args)
# TODO: Make rules for compiling with "-g" and creating the debug file
# TODO: Make tests download my test repo

.PHONY:	all run clean fclean re run libft
