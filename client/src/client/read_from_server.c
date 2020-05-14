/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019 [WSL: Debian]
** File description:
** read_from_server
*/

#include "client.h"
#include <unistd.h>

static char *client_recieve(client_t *client)
{
    char buffer[BUFFER_READ_SIZE] = { 0 };
    int ret = 0;

    ret = read(client->fd, buffer, BUFFER_READ_SIZE);
    ASSERT(ret >= 0);
    return (bufferizer(&client->req, buffer));
}

void read_from_server(client_t *client, cmd_t func)
{
    char *recept;

    recept = client_recieve(client);
    if (func) {
        (func)(client, (char const *)recept);
        func = NULL;
    }
    if (recept)
        free(recept);
    //TODO EVENT
    // else {

    // }
}