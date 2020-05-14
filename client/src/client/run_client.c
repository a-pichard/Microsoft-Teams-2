/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** run_client
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "command.h"
#include <sys/select.h>

static void check_ready_fd(
    fd_set *rset, fd_set *wset, client_t *client, cmd_t *func)
{
    char *msg = NULL;

    if (FD_ISSET(0, rset))
        *func = read_from_human(client);
    if (FD_ISSET(client->fd, rset)) {
        read_from_server(client, *func);
        *func = NULL;
    } else if (FD_ISSET(client->fd, wset)) {
        msg = ll_pop_front(&client->to_send);
        dprintf(client->fd, "%s\r\n", msg);
        free(msg);
    }
}

void client_run(client_t *client)
{
    fd_set rset;
    fd_set wset;
    cmd_t func = NULL;

    while (true) {
        FD_ZERO(&rset);
        FD_ZERO(&wset);
        FD_SET(0, &rset);
        FD_SET(client->fd, &rset);
        if (client->to_send)
            FD_SET(client->fd, &wset);
        select(client->fd + 1, &rset, &wset, NULL, NULL);
        check_ready_fd(&rset, &wset, client, &func);
    }
}