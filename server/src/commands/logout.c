/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** logout
*/

#include "cmd.h"
#include "logging_server.h"

static void event_user_logout(server_t *server, user_t *user)
{
    char *ser = user_serializer(user);
    char *msg = strcat_alloc("\"event\" \"logout\" ", ser);
    ll_t *todo = get_user_to_notify(server, user);

    ll_foreach(server->clients, client_t, client,
        ll_foreach(todo, user_t, to_not,
            if (client->user == to_not) {
                write_q(client, msg);
            }
        );
    );
    free(ser);
    free(msg);
}

void logout(server_t *server UNUSED, client_t *client,
    char const * const *data UNUSED)
{
    char uuid_str[37];

    if (*data != NULL) {
        write_q(client, "500 \"Bad argument\"");
    } else {
        if (client->user == NULL) {
            write_q(client, "300 \"not logged in\"");
        } else {
            uuid_unparse(client->user->uuid, uuid_str);
            server_event_user_logged_out(uuid_str);
            event_user_logout(server, client->user);
            write_q_responce_objet(client, 200, client->user,
                user_serializer);
            client->user->status--;
            client->user = NULL;
        }
    }
}