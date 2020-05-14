/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** use
*/

#include "server.h"
#include "parser.h"

static bool set_uuid(server_t *server, client_t *client, uuid_t uuid)
{
    team_t *teams = get_teams_by_uuid(server, uuid);
    channel_t *channel = get_channel_by_uuid(server, uuid);
    thread_t *thread = get_thread_by_uuid(server, uuid);

    if (thread != NULL || teams != NULL || channel != NULL) {
        uuid_copy(client->use_uuid, uuid);
        if (teams != NULL)
            client->state = TEAM;
        if (channel != NULL)
            client->state = CHANNEL;
        if (thread != NULL)
            client->state = THREAD;
        return false;
    } else {
        return true;
    }
}

void use(server_t *server, client_t *client, char const * const *data)
{
    parser_result_t *r;

    if (*data == NULL) {
        client->state = NONE;
        write_q(client, "200");
        return;
    }
    r = parse(data, &UUID_PARSER);
    if (r == NULL || r->remainer != NULL) {
        write_q(client, "300");
    } else {
        if (set_uuid(server, client, (unsigned char *)(r->data)))
            write_q(client, "300");
        else
            write_q(client, "200");
    }
}