/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** users
*/

#include "server.h"
#include <string.h>

static char *get_string_all_user(server_t *server)
{
    char *temp_str = ll_serialize(&server->users, &user_serializer);
    char *str = strcat_alloc("200 ", temp_str);

    free(temp_str);
    return str;
}

void users(server_t *server, client_t *client, char const * const *data)
{
    char *r = NULL;

    if (*data != NULL) {
        write_q(client, "500 \"Bad argument\"");
    } else {
        r = get_string_all_user(server);
        write_q(client, r);
        free(r);
    }
}