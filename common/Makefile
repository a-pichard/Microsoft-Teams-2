GREEN	=	\e[1;32m
WHITE	=	\e[0m
ORANGE	=	\e[1;33m
RED		=	\e[1;35m
BLUE	=	\e[1;34m

CC	=	gcc
ROOT	=	.
NAME	=	libcommon.a
RM	=	rm -f
INCL_DIR	=	$(ROOT)/incl
OBJ_DIR	=	$(ROOT)/obj
SRC_DIR	=	$(ROOT)/src
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
	@printf "%-50b$(WHITE)->%50b\n$(WHITE)" "$(RED)[$(BLUE)$<$(RED)]" "$(RED)[$(GREEN)$@$(RED)]"
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJ)
	@printf "$(RED)packing $(NAME)...$(WHITE)\n"
	@ar rc -o $(NAME) $^
	@printf "$(RED)finish $(NAME)!$(WHITE)\n"

clean:
	@rm -Rf $(OBJ_DIR)
	@printf "$(RED)clean$(WHITE)\n"

fclean: clean
	@rm -f $(NAME)
	@printf "$(RED)fclean$(WHITE)\n"

tests_run: fclean $(NAME)
	@printf "put test"


re:	fclean	all

.PHONE: all clean fclean re

