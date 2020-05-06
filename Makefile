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
BLUE	=	\e[1;34m

RM = rm -f

ROOT = .

COMMON_DIR = $(ROOT)/common

SERVER_DIR = $(ROOT)/server

CLIENT_DIR = $(ROOT)/client

CLIENT = myteams_cli

SERVER = myteams_server

COMMON = libcommon.a

all : $(CLIENT) $(SERVER)
	@printf "$(GREEN)Project built!$(WHITE)"

$(COMMON):
	@printf "$(RED)MAKING: common\n$(WHITE)"
	@make -s -C $(COMMON_DIR)
	@cp $(COMMON_DIR)/$(COMMON) $(COMMON)

$(CLIENT): $(COMMON)
	@printf "$(RED)MAKING: client\n$(WHITE)"
	@cp $(COMMON) $(CLIENT_DIR)/$(COMMON)
	@make -s -C $(CLIENT_DIR)
	@cp $(CLIENT_DIR)/$(CLIENT) $(CLIENT)

$(SERVER) : $(COMMON)
	@printf "$(RED)MAKING: server\n$(WHITE)"
	@cp $(COMMON) $(SERVER_DIR)/$(COMMON)
	@make -s -C $(SERVER_DIR)
	@cp $(SERVER_DIR)/$(SERVER) $(SERVER)


fclean:
	@make -s -C $(COMMON_DIR) fclean
	@make -s -C $(SERVER_DIR) fclean
	@make -s -C $(CLIENT_DIR) fclean
	@$(RM) $(COMMON)
	@$(RM) $(CLIENT)
	@$(RM) $(SERVER)
	@$(RM) $(SERVER_DIR)/$(COMMON)
	@$(RM) $(CLIENT_DIR)/$(COMMON)

clean:
	@make -s -C $(COMMON_DIR) clean
	@make -s -C $(SERVER_DIR) clean
	@make -s -C $(CLIENT_DIR) clean

re: fclean all

.PHONY: all clean fclean re $(CLIENT) $(SERVER) $(COMMON)