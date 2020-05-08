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

static cmd_t index_of(char const *cmd)
{
    const char *command_string[] = F_NAME;
    cmd_t funcs[] = F_FUNC;
    int i = 0;

    while (command_string[i] != NULL) {
        if (!strcasecmp(command_string[i], cmd))
            return (funcs[i]);
        i++;
    }
    return (NULL);
}

static bool authorized(client_t *client, cmd_t cmd)
{
    if (cmd == &help)
        return (true);
    if (cmd == &login)
        return (client->username == NULL);
    return (client->username != NULL);
}

static void client_request(server_t *serv, client_t *client, const char *req)
{
    char **data = NULL;
    cmd_t func = NULL;

    data = parse_cmd(&client->req, req);
    if (data == NULL || data[0] == NULL)
        return destroy_tab(data);
    print_tab((char const * const *) data);
    if ((func = index_of((char const *)data[0])) != NULL) {
        if (authorized(client, func))
            (func)(serv, client, (char const * const *)(data + 1));
        else if (func != &login)
            write_q(client, "300 \"not logged in\"");
        else
            write_q(client, "300 \"user already logged\"");
    } else
        write_q(client, "500 \"TODO: cmd not found\"");
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