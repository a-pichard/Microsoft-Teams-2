/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** server_teams_management
*/

#include "server.h"
#include <string.h>

team_t *server_get_teams_by_uuid(server_t *server, uuid_t uuid)
{
    if (server == NULL)
        return NULL;
    ll_foreach(server->teams, team_t, teams,
        if (!uuid_compare(teams->uuid, uuid)) {
            return teams;
        }
    );
    return NULL;
}

team_t *server_get_teams_by_name(server_t *server, char *name)
{
    if (server == NULL)
        return NULL;
    ll_foreach(server->teams, team_t, teams,
        if (!strcmp(teams->name, name)) {
            return teams;
        }
    );
    return NULL;
}

static void team_create_event(server_t *server, team_t *team)
{
    char *ser = team_serializer(team);
    char *r = strcat_alloc("\"event\" \"create\" \"team\" ", ser);

    ll_foreach(server->clients, client_t, client,
        if (uuid_compare(team->u_creator, client->user->uuid))
            write_q(client, r);
    );
    free(ser);
    free(r);
}

void server_add_team(server_t *server, team_t *team)
{
    team_create_event(server, team);
    ll_push_back(&server->teams, team);
}

void server_team_notify_users(server_t *server, team_t *team,
    const char *msg, uuid_t exep)
{
    client_t *client = NULL;

    ll_foreach(team->users_uuid, unsigned char, uuid,
        client = server_get_client_by_uuid(server, uuid);
        if (client && (exep == NULL || uuid_compare(uuid, exep)))
            write_q(client, msg);
    );
}