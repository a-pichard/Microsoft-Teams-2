/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** unsubscribe
*/

#include "server.h"
#include "parser.h"
#include "logging_server.h"

static void unsubscribe_response(client_t *client, team_t *team)
{
    char uuid_user[37];
    char uuid_team[37];
    char *r = NULL;

    uuid_unparse(client->user->uuid, uuid_user);
    uuid_unparse(team->uuid, uuid_team);
    server_event_user_leave_a_team(uuid_team, uuid_user);
    r = strcat_alloc3(uuid_user, " ", uuid_team);
    write_q_responce(client, 200, r);
    free(r);
}

void unsubscribe(server_t *server, client_t *client, char const * const *data)
{
    parser_result_t *r = parse(data, &UUID_PARSER);
    team_t *team = NULL;
    uuid_t *uuid = NULL;

    if (r == NULL || *r->remainer != NULL) {
        write_q(client, "500");
        return;
    }
    team = server_get_teams_by_uuid(server, (unsigned char *)(r->data));
    if (team == NULL)
        return write_q_responce_objet(client, 401, r->data, uuid_serialize);
    uuid = ll_find(&team->users_uuid, (compare_fn)uuid_compare,
        client->user->uuid);
    if (uuid == NULL)
        return write_q_responce(client, 500, "\"user not sub\"");
    ll_erase(&team->users_uuid, uuid, free);
    unsubscribe_response(client, team);
}