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

static void add_user_from_team(server_t *server, team_t *team, ll_t **list,
    user_t *user)
{
    ll_foreach(team->users_uuid, unsigned char, uuid,
        if (uuid_compare(user->uuid, uuid) && !ll_find(list,
        (int (*)(const void *, const void *))uuid_compare, uuid)) {
            ll_push_back(list, get_user_by_uuid(server, uuid));
        }
    );
}

ll_t *get_user_to_notify(server_t *server, user_t *user)
{
    ll_t *list = NULL;

    ll_foreach(server->teams, team_t, team,
        printf("a\n");
        if (ll_find(&team->users_uuid, (compare_fn)uuid_compare, user->uuid)) {
            add_user_from_team(server, team, &list, user);
        }
    );
    return list;
}