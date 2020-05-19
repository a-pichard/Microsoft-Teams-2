/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** use
*/

#include "server.h"
#include "parser.h"

static void use_team(server_t *server, client_t *client,
    char const * const *data)
{
    parser_result_t *r = parse(data, &UUID_PARSER);
    team_t *team = NULL;

    if (r == NULL)
        return write_q(client, "300");
    team = server_get_teams_by_uuid(server, (unsigned char *)r->data);
    if (team == NULL)
        return write_q(client, "404");
    client->use_ptr = team;
    client->state = TEAM;
    parser_result_clean(&UUID_PARSER, r);
    return write_q(client, "200");
}

static void use_channel(server_t *server, client_t *client,
    char const * const *data)
{
    AND_PARSER(p, &UUID_PARSER, &UUID_PARSER);
    parser_result_t *r = parse(data, &p);
    ll_t *list = NULL;
    team_t *team = NULL;
    channel_t *channel = NULL;

    if (r == NULL)
        return write_q(client, "300");
    list = r->data;
    team = server_get_teams_by_uuid(server, (unsigned char *)list->data);
    channel = team_get_channel_by_uuid(team,
        (unsigned char *)list->next->data);
    if (channel == NULL)
        return write_q(client, "404");
    client->use_ptr = channel;
    client->state = CHANNEL;
    parser_result_clean(&p, r);
    return write_q(client, "200");
}

static void use_thread(server_t *server, client_t *client,
    char const * const *data)
{
    AND_PARSER(p, &UUID_PARSER, &UUID_PARSER, &UUID_PARSER);
    parser_result_t *r = parse(data, &p);
    ll_t *list = NULL;
    team_t *team = NULL;
    channel_t *chan = NULL;
    thread_t *thread = NULL;

    if (r == NULL)
        return write_q(client, "300");
    list = r->data;
    team = server_get_teams_by_uuid(server, (unsigned char *)list->data);
    chan = team_get_channel_by_uuid(team, (unsigned char *)list->next->data);
    thread = channel_get_thread_by_uuid(chan,
        (unsigned char *)list->next->next->data);
    if (thread == NULL)
        return write_q(client, "404");
    client->use_ptr = thread;
    client->state = THREAD;
    parser_result_clean(&p, r);
    return write_q(client, "200");
}

void use(server_t *server, client_t *client, char const * const *data)
{
    size_t len = get_tab_len(data);

    if (*data == NULL) {
        client->state = NONE;
        client->use_ptr = NULL;
        write_q(client, "200");
        return;
    }
    if (len < 1 || len > 3) {
        write_q(client, "300");
        return;
    }
    if (len == 1) {
        use_team(server, client, data);
    } else if (len == 2) {
        use_channel(server, client, data);
    } else {
        use_thread(server, client, data);
    }
}