/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** server_user_management
*/

#include "server.h"
#include <string.h>

user_t *get_user_by_name(server_t *server, const char *username)
{
    ll_foreach(server->users, user_t, user,
        if (!strcmp(username, user->name)) {
            return user;
        }
    );
    return NULL;
}

user_t *get_user_by_uuid(server_t *server, uuid_t uuid)
{
    ll_foreach(server->users, user_t, user,
        if (!uuid_compare(user->uuid, uuid)) {
            return user;
        }
    );
    return NULL;
}

user_t *server_add_user_with_name(server_t *server, const char *username)
{
    user_t *user = user_create(username);

    ll_push_back(&server->users, user);
    return user;
}