/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** client_send
*/

#include "client.h"
#include <stdio.h>

void client_send(client_t *client, const char *msg)
{
    ll_push_back(&client->to_send, strdup(msg));
}