/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019 [WSL: Debian]
** File description:
** read_from_server
*/

#include "client.h"
#include <unistd.h>
#include <string.h>

static char *clean(char *data)
{
    if (data)
        data[strlen(data) - 2] = 0;
    return (data);
}

static char *client_recieve(client_t *client)
{
    char buffer[BUFFER_READ_SIZE] = { 0 };
    int ret = 0;

    ret = read(client->fd, buffer, BUFFER_READ_SIZE);
    ASSERT(ret >= 0);
    if (ret == 0) {
        close(client->fd);
        dprintf(1, "The client has been disconnected from the server\n");
        exit(0);
    }
    return (bufferizer(&client->req, buffer, REQ_END));
}

void read_from_server(client_t *client, cmd_t func)
{
    char *recept;

    recept = clean(client_recieve(client));
    if (recept) {
        if (!strncmp(recept, "\"event\"", 7)) {
            parse_event(recept);
        } else if (func) {
            (func)(client, (char const *)recept);
            func = NULL;
        }
        free(recept);
    }
}