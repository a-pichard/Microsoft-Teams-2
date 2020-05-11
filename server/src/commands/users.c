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
    size_t len = ll_len(&server->users);
    char *str = malloc(sizeof(char)*(len*(DEFAULT_NAME_LENGTH + 20)) + 20);
    char *temp_str;

    strcpy(str, "200 [ ");
    ll_foreach(server->users, user_t, user,
        temp_str = user_serialize(user);
        strcat(str, temp_str);
        strcat(str, " ");
        free(temp_str);
    );
    strcat(str, "]");
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