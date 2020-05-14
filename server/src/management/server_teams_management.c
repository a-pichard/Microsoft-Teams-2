/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** server_teams_management
*/

#include "server.h"

team_t *get_teams_by_uuid(server_t *server, uuid_t uuid)
{
    ll_foreach(server->teams, team_t, teams,
        if (!uuid_compare(teams->uuid, uuid)) {
            return teams;
        }
    );
    return NULL;
}