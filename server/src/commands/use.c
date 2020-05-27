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
        return write_q(client, "500");
    team = server_get_teams_by_uuid(server, (unsigned char *)r->data);
    if (team == NULL)
        return write_q_responce_objet(client, 401, r->data, uuid_serialize);
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
        return write_q(client, "500");
    list = r->data;
    team = server_get_teams_by_uuid(server, (unsigned char *)list->data);
    channel = team_get_channel_by_uuid(team,
        (unsigned char *)list->next->data);
    if (team == NULL || channel == NULL)
        return write_q_responce_objet(client, (team == NULL)?401:402,
            (team == NULL)?list->data:list->next->data, uuid_serialize);
    client->use_ptr = channel;
    client->state = CHANNEL;
    parser_result_clean(&p, r);
    return write_q(client, "200");
}

static thread_t *use_thread_error(server_t *server, client_t *client,
    ll_t *list)
{
    team_t *team = server_get_teams_by_uuid(server,
        (unsigned char *)list->data);
    channel_t *chan = team_get_channel_by_uuid(team,
        (unsigned char *)list->next->data);
    thread_t *thread = channel_get_thread_by_uuid(chan,
        (unsigned char *)list->next->next->data);

    if (team == NULL || chan == NULL || thread == NULL) {
        if (team == NULL)
            write_q_responce_objet(client, 401, list->data, uuid_serialize);
        if (chan == NULL)
            write_q_responce_objet(client, 402, list->next->data,
                uuid_serialize);
        if (thread == NULL)
            write_q_responce_objet(client, 403, list->next->next->data,
                uuid_serialize);
        return NULL;
    }
    return thread;
}

static void use_thread(server_t *server, client_t *client,
    char const * const *data)
{
    AND_PARSER(p, &UUID_PARSER, &UUID_PARSER, &UUID_PARSER);
    parser_result_t *r = parse(data, &p);
    ll_t *list = NULL;
    thread_t *thread = NULL;

    if (r == NULL)
        return write_q(client, "500");
    list = r->data;
    thread = use_thread_error(server, client, list);
    if (thread == NULL)
        return;
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
        write_q(client, "500");
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