/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** server_client_management
*/

#include "server.h"

client_t *server_get_client_by_uuid(server_t *s, uuid_t *uuid)
{
    ll_foreach(s->clients, client_t, client, 
        if (client->user != NULL && !uuid_compare(client->user->uuid, uuid)) {
            return client;
        }
    );
    return NULL;
}