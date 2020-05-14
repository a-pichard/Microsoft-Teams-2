/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** server_teams_management
*/

#include "server.h"
#include <string.h>

team_t *get_teams_by_uuid(server_t *server, uuid_t uuid)
{
    ll_foreach(server->teams, team_t, teams,
        if (!uuid_compare(teams->uuid, uuid)) {
            return teams;
        }
    );
    return NULL;
}

team_t *get_teams_by_name(server_t *server, char *name)
{
    ll_foreach(server->teams, team_t, teams,
        if (!strcmp(teams->name, name)) {
            return teams;
        }
    );
    return NULL;
}

void server_add_team(server_t *server, team_t *team)
{
    //todo notify
    ll_push_back(&server->teams, team);
}