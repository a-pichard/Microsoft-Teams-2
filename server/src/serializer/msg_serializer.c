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
    size_t len = strlen(msg->msg) + 37 + 37;
    char *str = malloc(sizeof(char)*(len + 5));
    char str_uuid[37];

    uuid_unparse(msg->from, str_uuid);
    strcpy(str, "\"");
    strcat(str, str_uuid);
    strcat(str, " ");
    uuid_unparse(msg->to, str_uuid);
    strcat(str, str_uuid);
    strcat(str, " ");
    strcat(str, msg->msg);
    strcat(str, "\"");
    return str;
}