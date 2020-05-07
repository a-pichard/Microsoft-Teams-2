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
#include <stdio.h>

void write_q(client_t *client, const char *msg)
{
    ll_push_back(&client->write_q, strdup(msg));
}

void send_message(client_t *client)
{
    void *data = ll_pop_front(&client->write_q);

    dprintf(client->fd, "%s\r\n", (char *)data);
    LOG("send:%s\n", (char *)data)
    write_q_destructor(data);
}