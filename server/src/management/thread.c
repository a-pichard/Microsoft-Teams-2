/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** thread
*/

#include "data.h"
#include "server.h"
#include "logging_server.h"
#include <string.h>

static team_t *get_team(server_t *server, channel_t *channel)
{
    ll_foreach(server->teams, team_t, team, 
        ll_foreach(team->channels, channel_t, c,
            if (c == channel) {
                return team;
            }
        );
    );
    return NULL;
}

static void thread_create_notify(channel_t *channel, thread_t *thread, user_t *user) {
    server_t *server = server_address(NULL);
    team_t *t = get_team(server, channel);
    char *ser = thread_serializer(thread);
    char *r = strcat("\"event\" \"create\" \"thread\" ", ser);

    server_team_notify_users(server_address(NULL), t, r, user->uuid);
    free(r);
    free(ser);
}

thread_t *thread_create(channel_t *channel, user_t *creator, const char *name,
    const char *body)
{
    thread_t *thread = malloc(sizeof(thread_t));
    char id_channel[37];
    char id_thread[37];
    char id_creator[37];

    strcpy(thread->title, name);
    strcpy(thread->body, body);
    thread->comments = NULL;
    thread->time = time(NULL);
    uuid_generate(thread->uuid);
    uuid_copy(thread->u_creator, creator->uuid);
    uuid_unparse(channel->uuid, id_channel);
    uuid_unparse(thread->uuid, id_thread);
    uuid_unparse(thread->u_creator, id_creator);
    thread_create_notify(channel, thread, creator);
    server_event_thread_created(id_channel, id_thread, id_creator, body);
    channel_add_thread(channel, thread);
    return thread;
}

void thread_add_comment(thread_t *thread, comment_t *comment)
{
    ll_push_back(&thread->comments, comment);
}