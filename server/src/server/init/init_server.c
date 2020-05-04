/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** init_server
*/

#include "server.h"
#include "errors.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

server_t *server_address(server_t *server)
{
    static server_t *save;

    if (server == NULL)
        return (save);
    save = server;
    return (save);
}

void init_server(server_t *server, int port)
{
    server_address(server);
    server->server_fd = init_main_server_socket(port);
    server->port = port;
    init_users(server);
    server->clients = NULL;
}