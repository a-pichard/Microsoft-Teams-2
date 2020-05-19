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
    channel_t *channel = (channel_t *)data;
    size_t len = strlen(channel->name) + strlen(channel->description) + 37;
    char *str = malloc(sizeof(char) * (len + 7));
    char str_uuid[37];

    ASSERT(str != NULL);
    uuid_unparse(channel->uuid, str_uuid);
    strcpy(str, str_uuid);
    strcat(str, " \"");
    strcat(str, channel->name);
    strcat(str, "\" \"");
    strcat(str, channel->description);
    strcat(str, "\"");
    return str;
}