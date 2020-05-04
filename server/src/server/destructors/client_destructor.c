/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** client_utils
*/

#include "server.h"
#include <stdlib.h>

void client_destructor(void *data)
{
    client_t *client = (client_t *)data;

    if (client->req)
        free(client->req);
    // todo : destroy complete write_q
    close(client->fd);
}