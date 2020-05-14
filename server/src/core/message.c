/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** message
*/

#include "data.h"
#include "string.h"
#include "logging_server.h"

msg_t *msg_create(uuid_t from, uuid_t to, const char *content)
{
    msg_t *message = malloc(sizeof(msg_t));

    ASSERT(message != NULL);
    uuid_copy(message->from, from);
    uuid_copy(message->to, to);
    message->msg = strdup(content);
    message->time = time(NULL);
    return message;
}

msg_t *message_reload(uuid_t from, uuid_t to, time_t t, const char *content)
{
    msg_t *message = malloc(sizeof(msg_t));

    ASSERT(message != NULL);
    uuid_copy(message->from, from);
    uuid_copy(message->to, to);
    message->msg = strdup(content);
    message->time = t;
    return message;
}