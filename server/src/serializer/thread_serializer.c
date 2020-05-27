/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** thread_serializer
*/

#include "server.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *thread_serializer(const void *data)
{
    thread_t *t = (thread_t *)data;
    char *str = NULL;
    char tuuid[37];
    char cuuid[37];
    int size = 0;
    char *patern = "%s %s %d \"%s\" \"%s\"";

    uuid_unparse(t->uuid, tuuid);
    uuid_unparse(t->u_creator, cuuid);
    size = snprintf(NULL, 0, patern, tuuid, cuuid, t->time, t->title, t->body);
    if (size == -1)
        return (NULL);
    str = malloc(sizeof(char) * (size + 1));
    ASSERT(str != NULL);
    size = snprintf(str, size + 1, patern, tuuid, cuuid,
        t->time, t->title, t->body);
    if (size == -1)
        return (NULL);
    return str;
}