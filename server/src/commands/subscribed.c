/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** subscribed
*/

#include "server.h"
#include "parser.h"

static bool team_contain_user(team_t *team, user_t *user)
{
    ll_foreach(team->users_uuid, unsigned char, uuid,
        if (!uuid_compare(user->uuid, uuid)) {
            return true;;
        }
    );
    return false;
}

static void subscribed_user(server_t *server, client_t *client,
    char const * const *data)
{
    ll_t *teams = NULL;
    char *ser = NULL;

    ll_foreach(server->teams, team_t, team,
        if (team_contain_user(team, client->user)) {
            ll_push_back(&teams, team);
        }
    );
    ser = ll_serialize(&teams, team_serializer);
    write_q_responce(client, 200, ser);
    ll_destroy(&teams, NULL);
}

static void subscribed_team(server_t *server, client_t *client,
    char const * const *data)
{
    parser_result_t *r = parse(data, &UUID_PARSER);
    team_t *team = server_get_teams_by_uuid(server, (unsigned char *)(r->data));
    ll_t *users = NULL;
    user_t *user;
    char *ser = NULL;

    ll_foreach(team->users_uuid, unsigned char, uuid,
        user = get_user_by_uuid(server, uuid);
        ll_push_front(&users, user)
    )
    ser = ll_serialize(&users, user_serializer);
    write_q_responce(client, 200, ser);
    free(ser);
    ll_destroy(&users, NULL);
    parser_result_clean(&UUID_PARSER, r);
}

void subscribed(server_t *server, client_t *client, char const * const *data)
{
    size_t len = get_tab_len(data);

    if (len == 0) {
        subscribed_user(server, client, data);
    } else if (len == 1) {
        subscribed_team(server, client, data);
    } else {
        write_q(client, "300");
    }
}