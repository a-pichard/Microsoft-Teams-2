##
## EPITECH PROJECT, 2020
## CCP_plazza_2019
## File description:
## Makefile
##

GREEN	=	\e[1;32m
WHITE	=	\e[0m
ORANGE	=	\e[1;33m
RED	=	\e[1;31m
PURPLE	=	\e[1;35m
BLUE	=	\e[1;34m

CC	=	gcc
ROOT	=	.
NAME	=	myteams_server
TEST_NAME	=	unit_tests
RM	=	rm -f
INCL_DIR	=	$(ROOT)/incl
OBJ_DIR	=	$(ROOT)/obj
SRC_DIR	=	$(ROOT)/src
TESTS_DIR = $(ROOT)/tests
CFLAGS	=	-Wall -Wextra -I$(INCL_DIR) -I ../common/incl -I../libs/myteams
LD_FLAGS = libcommon.a -luuid -L../libs/myteams -lmyteams
MAIN	=	$(ROOT)/src/main.c
SRC_TESTS	=	$(shell find $(SRC_DIR) $(TESTS_DIR) -type f -name '*.c' -not -path $(MAIN) 2> /dev/null)
SRC	=	$(shell find $(SRC_DIR)/ -type f -name '*.c')
COVERAGE_FILE	=	*.gcda *.gcno
all:	$(NAME)
debug: CFLAGS += -DDEBUG -g
debug: $(NAME)

OBJ	=	$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@printf "%-70b->%70b\n$(WHITE)" "$(RED)[$(BLUE)$<$(RED)]" "$(RED)[$(GREEN)$@$(RED)]"
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJ)
	@printf "$(PURPLE)linking $(NAME)...$(WHITE)\n"
	@$(CC) -o $(NAME) $^ $(LD_FLAGS)
	@printf "$(PURPLE)$(NAME) built!$(WHITE)\n\n"

tests_run	: $(NAME)
	@$(RM) $(COVERAGE_FILE)
	@printf "$(RED)testing...$(WHITE)"
	python tests/test.py
	# ./${TEST_NAME}

clean:
	@$(RM) $(COVERAGE_FILE)
	@$(RM) -R $(OBJ_DIR)
	@printf "$(ORANGE)clean$(WHITE)\n"

fclean: clean
	@$(RM) $(TEST_NAME)
	@$(RM) $(NAME)
	@printf "$(ORANGE)fclean$(WHITE)\n"

re: fclean all

.PHONE: all clean fclean re