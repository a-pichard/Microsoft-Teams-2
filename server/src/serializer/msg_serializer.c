/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** msg_serializer
*/

#include "server.h"
#include <stdlib.h>
#include <string.h>

char *msg_serializer(const void *data)
{
    msg_t *msg = (msg_t *)data;
    char *str = NULL;
    char fuuid[37];
    char tuuid[37];
    int size = 0;
    char *patern = "%s %s %d \"%s\"";

    uuid_unparse(msg->from, fuuid);
    uuid_unparse(msg->to, tuuid);
    size = snprintf(NULL, 0, patern, fuuid, tuuid, msg->time, msg->msg);
    if (size == -1)
        return (NULL);
    str = malloc(sizeof(char) * (size + 1));
    ASSERT(str != NULL);
    size = snprintf(str, size + 1, patern, fuuid, tuuid, msg->time, msg->msg);
    if (size == -1)
        return (NULL);
    return str;
}