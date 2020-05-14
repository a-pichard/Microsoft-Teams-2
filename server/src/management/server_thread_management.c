/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** server_thread_management
*/

#include "server.h"

thread_t *get_thread_by_uuid(server_t *server, uuid_t uuid)
{
    ll_foreach(server->teams, team_t, teams,
        ll_foreach(teams->channels, channel_t, channel,
            ll_foreach(channel->threads, thread_t, thread,
                if (!uuid_compare(thread->uuid, uuid)) {
                    return thread;
                }
            );
        );
    );
    return NULL;
}