/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** client_destroy
*/

#include "client.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>

void client_destroy(client_t *client)
{
    fd_set set;
    struct timeval tv;
    int ret;

    tv.tv_sec = 5;
    tv.tv_usec = 0;
    FD_ZERO(&set);
    FD_SET(client->fd, &set);
    ret = select(client->fd + 1, NULL, &set, NULL, &tv);
    if (ret > 0 && FD_ISSET(client->fd, &set))
        dprintf(client->fd, "/logout\r\n");
    if (client->fd != -1)
        close(client->fd);
    if (client->req != NULL)
        free(client->req);
    ll_destroy(&client->to_send, &free);
    free(client);
}