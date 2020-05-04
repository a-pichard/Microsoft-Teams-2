
RM = rm -f

ROOT = .

COMMON_DIR = $(ROOT)/common

SERVER_DIR = $(ROOT)/server

CLIENT_DIR = $(ROOT)/client

CLIENT = myteams_cli

SERVER = myteams_server

COMMON = common.a

all : $(CLIENT) $(SERVER)
	@printf "done"

$(COMMON):
	@printf "common\n"
	@make -s -C $(COMMON_DIR)
	@cp $(COMMON_DIR)/$(COMMON) $(COMMON)

$(CLIENT): $(COMMON)
	@printf "client\n"
	@make -s -C $(CLIENT_DIR)
	@cp $(CLIENT_DIR)/$(CLIENT) $(CLIENT)

$(SERVER) : $(COMMON)
	@printf "server\n"
	@make -s -C $(SERVER_DIR)
	@cp $(SERVER_DIR)/$(SERVER) $(SERVER)


fclean:
	@make -s -C $(COMMON_DIR) fclean
	@make -s -C $(SERVER_DIR) fclean
	@make -s -C $(CLIENT_DIR) fclean
	@$(RM) $(COMMON)
	@$(RM) $(CLIENT)
	@$(RM) $(SERVER)


clean:
	@make -s -C $(COMMON_DIR) clean
	@make -s -C $(SERVER_DIR) clean
	@make -s -C $(CLIENT_DIR) clean

re: fclean all

.PHONY: all clean fclean re $(CLIENT) $(SERVER) $(COMMON)