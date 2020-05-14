/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** server_channel_management
*/

#include "server.h"

channel_t *get_channel_by_uuid(server_t *server, uuid_t uuid)
{
    ll_foreach(server->teams, team_t, teams,
        ll_foreach(teams->channels, channel_t, channel,
            if (!uuid_compare(channel->uuid, uuid)) {
                return channel;
            }
        );
    );
    return NULL;
}