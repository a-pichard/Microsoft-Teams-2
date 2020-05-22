/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** team
*/

#include "server.h"
#include <string.h>
#include "logging_server.h"

team_t *team_create(user_t *user, const char *name, const char *description)
{
    char str[37];
    char str2[37];
    team_t *team = malloc(sizeof(team_t));

    team->channels = NULL;
    strcpy(team->description, description);
    strcpy(team->name, name);
    uuid_generate(team->uuid);
    uuid_unparse(team->uuid, str);
    team->users_uuid = NULL;
    uuid_unparse(user->uuid, str2);
    uuid_copy(team->u_creator, user->uuid);
    server_event_team_created(str, name, str2);
    return team;
}

channel_t *team_get_channel_by_uuid(team_t *team, uuid_t uuid)
{
    if (team == NULL)
        return NULL;
    ll_foreach(team->channels, channel_t, channel,
        if (!uuid_compare(channel->uuid, uuid)) {
            return channel;
        }
    );
    return NULL;
}

channel_t *team_get_channel_by_name(team_t *team, const char *name)
{
    if (team == NULL)
        return NULL;
    ll_foreach(team->channels, channel_t, channel,
        if (!strcmp(channel->name, name)) {
            return channel;
        }
    );
    return NULL;
}

void team_add_channel(team_t *team, channel_t *channel)
{
    char *ser = channel_serializer(channel); 
    char *msg = strcat_alloc("\"event\" \"create\" \"channel\" ", ser);

    ll_push_back(&team->channels, channel);
}

void team_add_user(team_t *team, user_t *user)
{
    unsigned char *uuid = malloc(sizeof(uuid_t));
    char uuid_team[37];
    char uuid_user[37];

    uuid_copy(uuid, user->uuid);
    uuid_unparse(team->uuid, uuid_team);
    uuid_unparse(user->uuid, uuid_user);
    server_event_user_join_a_team(uuid_team, uuid_user);
    ll_push_back(&team->users_uuid, uuid);
}
