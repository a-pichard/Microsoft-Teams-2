/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** channel
*/

#include "server.h"
#include "logging_server.h"
#include <string.h>

channel_t *channel_create(team_t *team, const char *name,
    const char *description)
{
    channel_t *channel = malloc(sizeof(channel_t));
    char id_team[37];
    char id_channel[37];

    channel->threads = NULL;
    strcpy(channel->description, description);
    strcpy(channel->name, name);
    uuid_generate(channel->uuid);
    uuid_unparse(team->uuid, id_team);
    uuid_unparse(channel->uuid, id_channel);
    server_event_channel_created(id_team, id_channel, channel->name);
    team_add_channel(team, channel);
    return channel;
}

channel_t *channel_reload(uuid_t uuid, const char *name,
    const char *description)
{
    channel_t *team = malloc(sizeof(channel_t));

    team->threads = NULL;
    strcpy(team->description, description);
    strcpy(team->name, name);
    uuid_copy(team->uuid, uuid);
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