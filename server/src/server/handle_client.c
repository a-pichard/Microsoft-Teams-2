/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** handle_client
*/

#include "server.h"
#include "errors.h"
#include "cmd.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

static cmd_t index_of(const char **narr, cmd_t *funcs, char *cmd)
{
    int i = 0;

    while (narr[i] != NULL) {
        if (!strcasecmp(narr[i], cmd)) {
            free(cmd);
            return (funcs[i]);
        }
        i++;
    }
    return (NULL);
}

static void client_request(server_t *serv, client_t *client, const char *req)
{
    char *cmd = NULL;
    char *data = NULL;
    cmd_t funcs[] = {};
    cmd_t func = NULL;
    const char *command_string[] = {"hel"};

    parse_cmd(client->req, req, &cmd, &data);
    if (cmd == NULL && data == NULL)
        return;
    if ((func = index_of(command_string, funcs, cmd)) != NULL)
        (func)(serv, client, data);
    if (data != NULL)
        free(data);
}

void handle_client(server_t *server, client_t *client)
{
    char buffer[BUFFER_READ_SIZE] = { 0 };
    int ret = 0;

    ret = read(client->fd, buffer, BUFFER_READ_SIZE);
    raise_error(ret >= 0, "read() ");
    if (ret == 0)
        return ll_erase(server->clients, client, &client_destructor);
    client_request(server, client, buffer);
}