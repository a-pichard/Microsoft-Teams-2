/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** users
*/

#include "server.h"
#include <string.h>

void users(server_t *server, client_t *client, char const * const *data)
{
    if (*data != NULL) {
        write_q(client, "500 \"Bad argument\"");
    } else {
        write_q_responce_objet_list(client, 200, server->users, user_serializer);
    }
}