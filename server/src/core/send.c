/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** send
*/

#include "server.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void write_q(client_t *client, const char *msg)
{
    ll_push_back(&client->write_q, strdup(msg));
}

void send_message(client_t *client)
{
    void *data = ll_pop_front(&client->write_q);
    size_t len = strlen((char *)data) + 2;
    char *msg = malloc(sizeof(char) * (len + 1));

    raise_err(msg != NULL, "malloc() ");
    strcpy(msg, (char *)data);
    strcat(msg, "\r\n");
    write(client->fd, msg, len);
    free(msg);
    write_q_destructor(data);
}