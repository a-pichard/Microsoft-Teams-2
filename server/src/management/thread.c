/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** thread
*/

#include "data.h"
#include "server.h"
#include <string.h>

thread_t *thread_create(user_t *creator, const char *name, const char *body)
{
    thread_t *thread = malloc(sizeof(thread_t));

    strcpy(thread->title, name);
    strcpy(thread->body, body);
    thread->comments = NULL;
    thread->time = time(NULL);
    uuid_generate(thread->uuid);
    uuid_copy(thread->u_creator, creator->uuid);
    return thread;
}

void thread_add_comment(thread_t *thread, comment_t *comment)
{
    ll_push_back(&thread->comments, comment);
}