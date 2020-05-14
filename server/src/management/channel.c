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