/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** user
*/

#include "server.h"
#include <uuid/uuid.h>
#include <string.h>
#include <logging_server.h>
#include <string.h>

user_t *user_create(const char *name)
{
    user_t *user = malloc(sizeof(user_t));
    char uuid_str[37];

    ASSERT(user != NULL);
    strcpy(user->name, name);
    uuid_generate(user->uuid);
    uuid_unparse(user->uuid, uuid_str);
    server_event_user_created(uuid_str, name);
    user->status = 0;
    return user;
}

user_t *user_reload(const char *name, uuid_t uuid, int status)
{
    user_t *user = malloc(sizeof(user_t));

    strcpy(user->name, name);
    uuid_copy(user->uuid, uuid);
    user->status = status;
    //todo call log
    return user;
}