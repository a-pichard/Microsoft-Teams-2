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
    char *str = NULL;
    char str_uuid[37];
    int size = 0;
    char *patern = "%s \"%s\" %d";

    uuid_unparse(user->uuid, str_uuid);
    size = snprintf(NULL, 0, patern, str_uuid, user->name, user->status);
    if (size == -1)
        return (NULL);
    str = malloc(sizeof(char) * (size + 1));
    ASSERT(str != NULL);
    size = snprintf(str, size + 1, patern, str_uuid, user->name, user->status);
    if (size == -1)
        return (NULL);
    return str;
}