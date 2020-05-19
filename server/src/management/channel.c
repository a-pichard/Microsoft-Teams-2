/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** channel
*/

#include "server.h"
#include "logging_server.h"
#include <string.h>

channel_t *channel_create(const char *name, const char *description)
{
    char str[37];
    channel_t *team = malloc(sizeof(channel_t));

    team->threads = NULL;
    strcpy(team->description, description);
    strcpy(team->name, name);
    uuid_generate(team->uuid);
    uuid_unparse(team->uuid, str);
    server_event_channel_created(str, name, description);
    return team;
}

thread_t *channel_get_thread_by_uuid(channel_t *channel, uuid_t uuid)
{
    if (channel == NULL)
        return NULL;
    ll_foreach(channel->threads, thread_t, thread,
        if (!uuid_compare(thread->uuid, uuid)) {
            return thread;
        }
    );
    return NULL;
}

thread_t *channel_get_thread_by_name(channel_t *channel, const char *name)
{
    if (channel == NULL)
        return NULL;
    ll_foreach(channel->threads, thread_t, thread,
        if (!strcmp(thread->title, name)) {
            return thread;
        }
    );
    return NULL;
}

void channel_add_thread(channel_t *channel, thread_t *thread)
{
    ll_push_back(&channel->threads, thread);
}