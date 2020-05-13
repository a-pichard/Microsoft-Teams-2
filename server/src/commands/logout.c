/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** logout
*/

#include "cmd.h"
#include "logging_server.h"

static void success_response(client_t *client)
{
    char *serialized_usr = user_serialize(client->user);
    char *response = strcat_alloc("200 ", serialized_usr);

    ASSERT(response != NULL);
    free(serialized_usr);
    write_q(client, response);
    free(response);
}

void logout(server_t *server UNUSED, client_t *client, char const * const *data UNUSED)
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
            success_response(client);
            client->user->status--;
            client->user = NULL;
        }
    }
}