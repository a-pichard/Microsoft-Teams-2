/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** subscribe
*/

#include "server.h"
#include "parser.h"

static void subscribe_response(client_t *client, team_t *team)
{
    char uuid_user[37];
    char uuid_team[37];
    char *r = NULL;

    uuid_unparse(client->user->uuid, uuid_user);
    uuid_unparse(team->uuid, uuid_team);
    r = strcat_alloc3(uuid_user, " ", uuid_team);
    write_q_responce(client, 200, r);
    free(r);
}

void subscribe(server_t *server, client_t *client, char const * const *data)
{
    parser_result_t *r = parse(data, &UUID_PARSER);
    team_t *team = NULL;
    uuid_t *uuid = NULL;

    if (r == NULL || r->remainer != NULL)
        write_q(client, "300");
    team = server_get_teams_by_uuid(server, (unsigned char *)(r->data));
    if (team == NULL)
        return write_q_responce(client, 404, "\"team not found\"");
    uuid = find(&team->users_uuid, uuid_compare, client->user->uuid);
    if (uuid != NULL)
        return write_q_responce(client, 300, "\"user already sub\"");
    team_add_user(team, client->user);
    subscribe_response(client, team);
}
