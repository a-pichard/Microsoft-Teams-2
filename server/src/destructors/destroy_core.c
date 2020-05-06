/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** destroy
*/

#include "server.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void destroy_server(void)
{
    server_t *server = server_address(NULL);

    ll_destroy(&server->users, &user_destructor);
    ll_destroy(&server->clients, &client_destructor);
    close(server->server_fd);
    dprintf(1, "Server fd: %d closed\n", server->server_fd);
}