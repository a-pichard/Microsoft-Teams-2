/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** comment
*/

#include "data.h"
#include "server.h"
#include <string.h>
#include "logging_server.h"

comment_t *comment_create(thread_t *thread, user_t *creator, const char *body)
{
    comment_t *comment = malloc(sizeof(comment_t));
    char id_thread[37];
    char id_user[37];

    strcpy(comment->body, body);
    comment->time = time(NULL);
    uuid_copy(comment->u_creator, creator->uuid);
    uuid_generate(comment->uuid);
    uuid_unparse(thread->uuid, id_thread);
    uuid_unparse(creator->uuid, id_user);
    server_event_thread_new_message(id_thread, id_user, body);
    thread_add_comment(thread, comment);
    return comment;
}

comment_t *comment_reload(user_t *creator, const char *body)
{
    comment_t *comment = malloc(sizeof(comment_t));

    strcpy(comment->body, body);
    comment->time = time(NULL);
    uuid_copy(comment->u_creator, creator->uuid);
    uuid_generate(comment->uuid);
    return comment;
}