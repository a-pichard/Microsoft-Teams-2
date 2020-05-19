/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** info
*/

#include "server.h"

void info(UNUSED server_t *server, client_t *client, char const * const *data)
{
    if (*data != NULL) {
        write_q_responce(client, 300, "");
    } else {
        if (client->state == NONE) {
            write_q_responce_objet(client, 200, client->user,
                user_serializer);
        } else if (client->state == TEAM) {
            write_q_responce_objet(client, 200, client->use_ptr,
                team_serializer);
        } else if (client->state == CHANNEL) {
            write_q_responce_objet(client, 200, client->use_ptr,
                channel_serializer);
        } else {
            write_q_responce_objet(client, 200, client->use_ptr,
                thread_serializer);
        }
    }
}