/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** client_destroy
*/

#include "client.h"
#include <stdlib.h>
#include <unistd.h>

void client_destroy(client_t *client)
{
    if (client->fd != -1)
        close(client->fd);
    if (client->req != NULL)
        free(client->req);
    free(client);
}