/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** handle_client
*/

#include "server.h"
#include "cmd.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

static cmd_t index_of(const char **narr, cmd_t *funcs, char *cmd)
{
    int i = 0;

    while (narr[i] != NULL) {
        if (!strcasecmp(narr[i], cmd))
            return (funcs[i]);
        i++;
    }
    return (NULL);
}

static void client_request(server_t *serv, client_t *client, const char *req)
{
    char **data = NULL;
    const char *command_string[] = F_NAME;
    cmd_t funcs[] = F_FUNC;
    cmd_t func = NULL;

    data = parse_cmd(&client->req, req);
    if (data == NULL || data[0] == NULL)
        return destroy_tab(data);
    print_tab(data);
    if ((func = index_of(command_string, funcs, data[0])) != NULL)
        (func)(serv, client, &data[1]);
    destroy_tab(data);
}

void handle_client(server_t *server, client_t *client)
{
    char buffer[BUFFER_READ_SIZE] = { 0 };
    int ret = 0;

    ret = read(client->fd, buffer, BUFFER_READ_SIZE);
    if (ret < 0) {
        ASSERT(errno == ECONNRESET);
        ret = 0;
    }
    if (ret == 0)
        return ll_erase(&server->clients, client, &client_destructor);
    client_request(server, client, buffer);
}