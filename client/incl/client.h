/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** client
*/

#ifndef CLIENT_H_
#define CLIENT_H_

#include "common.h"

typedef struct client_s
{
    int fd;
    char *req;
} client_t;

void helper(const char *prg, int exit_status);


// client
client_t *client_create(const char *ip, int port);
void client_destroy(client_t *client);
void client_run(client_t *client);
char *client_recieve(client_t *client);
void client_send(client_t *client, const char *msg);


char **clean(char **data);
void check_cmd(char **data, const char **command_string);
void client_run(client_t *client);


#endif /* !CLIENT_H_ */