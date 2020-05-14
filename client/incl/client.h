/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** client
*/

#ifndef CLIENT_H_
#define CLIENT_H_

#include "common.h"
#include "linked_list.h"

typedef struct client_s
{
    int fd;
    char *req;
    ll_t *to_send;
} client_t;

typedef void (*cmd_t)(client_t *client, char const * recept);

void helper(const char *prg, int exit_status);

// client
client_t *init_client(const char *ip, const char *port_str);
client_t *client_save(client_t *client);
void client_destroy(client_t *client);
void client_run(client_t *client);
void client_send(client_t *client, const char *msg);
void read_from_server(client_t *client, cmd_t func);
cmd_t read_from_human(client_t *client);

char **clean(char **data);
cmd_t check_cmd(char **data, const char **command_string);
void client_run(client_t *client);

#endif /* !CLIENT_H_ */
