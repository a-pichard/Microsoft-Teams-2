/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** comment_serializer
*/

#include "server.h"
#include <stdlib.h>
#include <string.h>

char *comment_serializer(const void *data)
{
    comment_t *c = (comment_t *)data;
    char *str = NULL;
    char cuuid[37];
    char uuuid[37];
    int size = 0;
    char *patern = "%s %s %d \"%s\"";

    uuid_unparse(c->uuid, cuuid);
    uuid_unparse(c->u_creator, uuuid);
    size = snprintf(NULL, 0, patern, cuuid, uuuid, c->time, c->body);
    if (size == -1)
        return (NULL);
    str = malloc(sizeof(char) * (size + 1));
    ASSERT(str != NULL);
    size = snprintf(str, size + 1, patern, cuuid, uuuid, c->time, c->body);
    if (size == -1)
        return (NULL);
    return str;
}