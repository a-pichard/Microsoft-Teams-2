/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** load_channel
*/

#include "server.h"
#include <string.h>

static comment_t *reload_comment(ll_t *data)
{
    comment_t *comment = malloc(sizeof(comment_t));

    uuid_copy(comment->uuid, data->data);
    uuid_copy(comment->u_creator, data->next->data);
    comment->time = *(time_t *)data->next->next->data;
    strcpy(comment->body, data->next->next->next->data);
    return comment;
}

static thread_t *reload_thread(ll_t *data)
{
    thread_t *thread = malloc(sizeof(thread_t));
    ll_t *comments = data->next->next->next->next->next->data;

    ASSERT(thread != NULL);
    thread->comments = NULL;
    uuid_copy(thread->uuid, data->data);
    uuid_copy(thread->u_creator, data->next->data);
    thread->time = *(time_t *)data->next->next->data;
    strcpy(thread->title, data->next->next->next->data);
    strcpy(thread->body, data->next->next->next->next->data);
    ll_foreach(comments, ll_t, comment,
        ll_push_back(&thread->comments, reload_comment(comment));
    );
    return thread;
}

channel_t *reload_channel(ll_t *data)
{
    channel_t *channel = malloc(sizeof(channel_t));
    ll_t *threads = data->next->next->next->next->data;

    ASSERT(channel != NULL);
    channel->threads = NULL;
    uuid_copy(channel->uuid, data->data);
    uuid_copy(channel->u_creator, data->next->data);
    strcpy(channel->name, data->next->next->data);
    strcpy(channel->description, data->next->next->next->data);
    ll_foreach(threads, ll_t, thread,
        ll_push_back(&channel->threads, reload_thread(thread));
    );
    return channel;
}
