/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** user_serializer
*/

#include "server.h"
#include <stdlib.h>
#include <string.h>

char *user_serializer(const void *data)
{
    user_t *user = (user_t *)data;
    char *str = malloc(sizeof(char) * (strlen(user->name) + 37 + 6));
    char str_uuid[37];

    uuid_unparse(user->uuid, str_uuid);
    strcpy(str, str_uuid);
    strcat(str, " \"");
    strcat(str, user->name);
    strcat(str, "\" ");
    if (user->status == 0) {
        strcat(str, "0");
    } else {
        strcat(str, "1");
    }
    return str;
}