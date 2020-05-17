/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** comment
*/

#include "data.h"
#include "server.h"
#include <string.h>

comment_t *comment_create(user_t *creator, const char *body)
{
    comment_t *comment = malloc(sizeof(comment_t));

    strcpy(comment->body, body);
    comment->time = time(NULL);
    uuid_copy(comment->uuid, creator->uuid);
    uuid_generate(comment->uuid);
    return comment;
}