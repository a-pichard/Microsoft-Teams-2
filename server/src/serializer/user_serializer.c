/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** user_serializer
*/

#include "server.h"
#include <stdlib.h>
#include <string.h>

char *user_serialize(const user_t *user)
{
    char *str = malloc(sizeof(char) * (strlen(user->name) + 37 + 6));
    char str_uuid[37];

    uuid_unparse(user->uuid, str_uuid);
    strcpy(str, "\"");
    strcat(str, str_uuid);
    strcat(str, " ");
    strcat(str, user->name);
    strcat(str, " ");
    if (user->status == 0) {
        strcat(str, "0");
    } else {
        strcat(str, "1");
    }
    strcat(str, "\"");
    return str;
}