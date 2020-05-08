##
## EPITECH PROJECT, 2020
## NWP_myteams_2019
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
NAME	=	libcommon.a
TEST_NAME	=	unit_test
RM	=	rm -f
INCL_DIR	=	$(ROOT)/incl
OBJ_DIR	=	$(ROOT)/obj
SRC_DIR	=	$(ROOT)/src
TESTS_DIR	=	$(ROOT)/tests
CFLAGS	=	-Wall -Wextra -I$(INCL_DIR)
MAIN	=	main.c
SRC_TESTS	=	$(shell find $(SRC_DIR) $(TESTS_DIR) -type f -name '*.c' -not -path $(SRC_DIR)/$(MAIN) 2> /dev/null)
SRC	=	$(shell find $(SRC_DIR)/ -type f -name '*.c')

all:	$(NAME)
debug: CFLAGS += -DDEBUG -g
debug: $(NAME)

OBJ	=	$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@printf "%-70b->%70b\n$(WHITE)" "$(RED)[$(BLUE)$<$(RED)]" "$(RED)[$(GREEN)$@$(RED)]"
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJ)
	@printf "$(PURPLE)packing $(NAME)...$(WHITE)\n"
	@ar rc -o $(NAME) $^
	@printf "$(PURPLE)$(NAME) created!$(WHITE)\n\n"

clean:
	@rm -Rf $(OBJ_DIR) *.gcno *.gcda
	@printf "$(ORANGE)clean$(WHITE)\n"

fclean: clean
	@rm -f $(NAME) $(TEST_NAME)
	@printf "$(ORANGE)fclean$(WHITE)\n"

tests_run: fclean
	@$(CC) $(SRC_TESTS) -o $(TEST_NAME) -lcriterion --coverage -luuid $(CFLAGS)
	@printf "$(BLUE)Compile sources and tests : $(GREEN)success$(WHITE)\n"
	@printf "$(BLUE)Launching tests...$(WHITE)\n"
	@./unit_test
	@gcovr --exclude tests

re:	fclean	all

.PHONE: all clean fclean re

