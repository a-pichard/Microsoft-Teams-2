/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** thread_serializer
*/

#include "server.h"
#include <stdlib.h>
#include <string.h>

static void concat_uuids(char *str, thread_t *thread)
{
    char str_uuid[37];

    uuid_unparse(thread->uuid, str_uuid);
    strcat(str, str_uuid);
    strcat(str, " ");
    uuid_unparse(thread->u_creator, str_uuid);
    strcat(str, str_uuid);
    strcat(str, " ");
}

char *thread_serializer(const void *data)
{
    thread_t *thread = (thread_t *)data;
    size_t len = strlen(thread->title) + strlen(thread->body) + 37 + 37 + 10;
    char *str = malloc(sizeof(char) * (len + 7));
    char time[10];

    ASSERT(str != NULL);
    sprintf(time, "%ld", thread->time);
    strcpy(str, "\"");
    concat_uuids(str, thread);
    strcat(str, time);
    strcat(str, " ");
    strcat(str, thread->title);
    strcat(str, " ");
    strcat(str, thread->body);
    strcat(str, "\"");
    return str;
}