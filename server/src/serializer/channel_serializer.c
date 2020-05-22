/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** channel_serializer
*/

#include "server.h"
#include <stdlib.h>
#include <string.h>

char *channel_serializer(const void *data)
{
    channel_t *c = (channel_t *)data;
    char *str = NULL;
    char str_uuid[37];
    int size = 0;
    char *patern = "%s \"%s\" \"%s\"";

    uuid_unparse(c->uuid, str_uuid);
    size = snprintf(NULL, 0, patern, str_uuid, c->name, c->description);
    if (size == -1)
        return (NULL);
    str = malloc(sizeof(char) * (size + 1));
    ASSERT(str != NULL);
    size = snprintf(str, size + 1, patern, str_uuid, c->name, c->description);
    if (size == -1)
        return (NULL);
    return str;
}