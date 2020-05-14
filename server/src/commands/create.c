/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** create
*/

#include "server.h"
#include "parser.h"

void create_team(server_t *server, client_t *client, char const * const *data)
{
    parser_t sur = SUROUNDE_PARSER('"', &STRING_PARSER);
    AND_PARSER(p, &sur, &sur);
    parser_result_t *r = parse(data, &p);
    team_t *teams;
    ll_t *d;

    if (r == NULL) {
        write_q(client, "300");
        return;
    }
    d = r->data;
    teams = get_teams_by_name(server, d->data);
    if (teams != NULL) {
        write_q(client, "300");
    } else {
        server_add_team(server, team_create(d->data, d->next->data));
        write_q(client, "200 context"); // todo send the team simple serialisation
    }
    parser_result_clean(&p, r);
}

void create_channel(server_t *server, client_t *client, char const * const *data)
{
    parser_t sur = SUROUNDE_PARSER('"', &STRING_PARSER);
    AND_PARSER(p, &sur, &sur);
    parser_result_t *r = parse(data, &p);

    parser_result_clean(&p, r);
}

void create_thread(server_t *server, client_t *client, char const * const *data)
{
    parser_t sur = SUROUNDE_PARSER('"', &STRING_PARSER);
    AND_PARSER(p, &sur, &sur);
    parser_result_t *r = parse(data, &p);

    parser_result_clean(&p, r);
}

void create_reply(server_t *server, client_t *client, char const * const *data)
{
    parser_t p = SUROUNDE_PARSER('"', &STRING_PARSER);
    parser_result_t *r = parse(data, &p);

    parser_result_clean(&p, r);
}

void create(server_t *server, client_t *client, char const * const *data)
{
    if (client->state == NONE) {
        create_team(server, client, data);
    } else if (client->state == TEAM) {
        create_channel(server, client, data);
    } else if (client->state == CHANNEL) {
        create_thread(server, client, data);
    } else {
        create_reply(server, client, data);
    }
}