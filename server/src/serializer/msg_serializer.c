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
    size_t len = strlen(msg->msg) + 37 + 37 + 24;
    char *str = calloc(sizeof(char), (len + 5));
    char str_uuid1[37];
    char str_uuid2[37];
    char int_str[24] = { 0 };

    sprintf(int_str, "%ld", msg->time);
    uuid_unparse(msg->from, str_uuid1);
    uuid_unparse(msg->to, str_uuid2);
    strcpy(str, str_uuid1);
    strcat(str, " ");
    strcat(str, str_uuid2);
    strcat(str, " ");
    strcat(str, int_str);
    strcat(str, " ");
    strcat(str, "\"");
    strcat(str, msg->msg);
    strcat(str, "\"");
    return str;
}