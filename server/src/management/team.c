/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** team
*/

#include "server.h"
#include <string.h>
#include "logging_server.h"

team_t *team_create(const char *name, const char *description)
{
    char str[37];
    team_t *team = malloc(sizeof(team_t));

    team->channels = NULL;
    strcpy(team->description, description);
    strcpy(team->name, name);
    uuid_generate(team->uuid);
    uuid_unparse(team->uuid, str);
    team->users_uuid = NULL;
    server_event_team_created(str, name, description);
    return team;
}