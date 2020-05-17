/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** create
*/

#include "server.h"
#include "parser.h"

void create_team(server_t *server, client_t *client,
    char const * const *data)
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
    teams = server_get_teams_by_name(server, d->data);
    if (teams != NULL) {
        write_q(client, "300");
    } else {
        server_add_team(server, team_create(d->data, d->next->data));
        write_q(client, "200 context"); // todo send the team simple serialisation
    }
    parser_result_clean(&p, r);
}

void create_channel(UNUSED server_t *server, client_t *client,
    char const * const *data)
{
    parser_t sur = SUROUNDE_PARSER('"', &STRING_PARSER);
    AND_PARSER(p, &sur, &sur);
    parser_result_t *r = parse(data, &p);
    channel_t *channel;
    ll_t *d;

    if (r == NULL) {
        write_q(client, "300");
        return;
    }
    d = r->data;
    channel = team_get_channel_by_name(client->use_ptr, d->data);
    if (channel != NULL) {
        write_q(client, "300");
    } else {
        team_add_channel(client->use_ptr,
            channel_create(d->data, d->next->data));
        write_q(client, "201 context"); // todo send the channel simple serialisation
    }
    parser_result_clean(&p, r);
}

void create_thread(UNUSED server_t *server, client_t *client,
    char const * const *data)
{
    parser_t sur = SUROUNDE_PARSER('"', &STRING_PARSER);
    AND_PARSER(p, &sur, &sur);
    parser_result_t *r = parse(data, &p);
    thread_t *thread;
    ll_t *d;

    if (r == NULL) {
        write_q(client, "300");
        return;
    }
    d = r->data;
    thread = channel_get_thread_by_name(client->use_ptr, d->data);
    if (thread != NULL) {
        write_q(client, "300");
    } else {
        channel_add_thread(client->use_ptr, thread_create(client->user,
            d->data, d->next->data));
        write_q(client, "202 context"); // todo send the thread simple serialisation
    }
    parser_result_clean(&p, r);
}

void create_reply(UNUSED server_t *server, client_t *client,
    char const * const *data)
{
    parser_t p = SUROUNDE_PARSER('"', &STRING_PARSER);
    parser_result_t *r = parse(data, &p);

    if (r == NULL) {
        write_q(client, "300");
        return;
    }
    thread_add_comment(client->use_ptr, comment_create(client->user,
        r->data));
    write_q(client, "203 context"); // todo send the thread simple serialisation
    parser_result_clean(&p, r);
}

void create(server_t *server, client_t *client, char const * const *data)
{
    return;
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