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
    AND_PARSER(p, &STRING_PARSER, &STRING_PARSER);
    parser_result_t *r = parse(data, &p);
    team_t *teams;
    ll_t *d;

    if (r == NULL) {
        write_q(client, "300");
    } else {
        d = r->data;
        teams = server_get_teams_by_name(server, d->data);
        if (teams != NULL) {
            write_q(client, "300");
        } else {
            teams = team_create(client->user, d->data, d->next->data);
            write_q_responce_objet(client, 200, teams, team_serializer);
        }
    }
    parser_result_clean(&p, r);
}

void create_channel(UNUSED server_t *server, client_t *client,
    char const * const *data)
{
    AND_PARSER(p, &STRING_PARSER, &STRING_PARSER);
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
        channel = channel_create(client->use_ptr, d->data, d->next->data);
        write_q_responce_objet(client, 201, channel, channel_serializer);
    }
    parser_result_clean(&p, r);
}

void create_thread(UNUSED server_t *server, client_t *client,
    char const * const *data)
{
    AND_PARSER(p, &STRING_PARSER, &STRING_PARSER);
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
        thread = thread_create(client->use_ptr, client->user, d->data, d->next->data);
        write_q_responce_objet(client, 202, thread, thread_serializer);
    }
    parser_result_clean(&p, r);
}

void create_reply(UNUSED server_t *server, client_t *client,
    char const * const *data)
{
    parser_result_t *r = parse(data, &STRING_PARSER);
    comment_t *comment = NULL;

    if (r == NULL) {
        write_q(client, "300");
        return;
    }
    comment = comment_create(client->use_ptr, client->user, r->data);
    write_q_responce_objet(client, 203, comment, comment_serializer);
    parser_result_clean(&STRING_PARSER, r);
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