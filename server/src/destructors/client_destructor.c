/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** client_utils
*/

#include "server.h"
#include <stdlib.h>
#include <unistd.h>

void client_destructor(void *data)
{
    client_t *client = (client_t *)data;

    if (client->username)
        free(client->username);
    if (client->req)
        free(client->req);
    ll_destroy(&client->write_q, &write_q_destructor);
    close(client->fd);
    free(client);
}