/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** comment_serializer
*/

#include "server.h"
#include <stdlib.h>
#include <string.h>

static void concat_uuids(char *str, comment_t *comment)
{
    char str_uuid[37];

    uuid_unparse(comment->uuid, str_uuid);
    strcpy(str, str_uuid);
    strcat(str, " ");
    uuid_unparse(comment->u_creator, str_uuid);
    strcat(str, str_uuid);
    strcat(str, " ");
}

char *comment_serializer(const void *data)
{
    comment_t *comment = (comment_t *)data;
    size_t len = strlen(comment->body) + 37 + 37 + 10;
    char *str = malloc(sizeof(char) * (len + 6));
    char time[10];

    ASSERT(str != NULL);
    sprintf(time, "%ld", comment->time);
    concat_uuids(str, comment);
    strcat(str, time);
    strcat(str, " \"");
    strcat(str, comment->body);
    strcat(str, "\"");
    return str;
}