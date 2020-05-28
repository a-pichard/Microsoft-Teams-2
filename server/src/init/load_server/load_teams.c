/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** load_teams
*/

#include "server.h"
#include "parser.h"

static void reload_members(team_t *team, ll_t *data)
{
    unsigned char *new_uuid = NULL;

    ll_foreach(data, unsigned char, uuid,
        new_uuid = malloc(sizeof(char) * 16);
        uuid_copy(new_uuid, uuid);
        ll_push_back(&team->users_uuid, new_uuid);
    );
}

static team_t *reload_teams(ll_t *data)
{
    team_t *team = malloc(sizeof(team_t));
    ll_t *channels = data->next->next->next->next->data;
    ll_t *members = data->next->next->next->next->next->data;

    ASSERT(team != NULL);
    team->channels = NULL;
    team->users_uuid = NULL;
    uuid_copy(team->uuid, data->data);
    uuid_copy(team->u_creator, data->next->data);
    strcpy(team->name, data->next->next->data);
    strcpy(team->description, data->next->next->next->data);
    ll_foreach(channels, ll_t, c,
        ll_push_back(&team->channels, reload_channel(c));
    );
    reload_members(team, members);
    return team;
}

static const char * const *parse_teams(server_t *server, const parser_t *p,
    parser_result_t *r)
{
    const char * const *remain = r->remainer;
    ll_t *list_team = r->data;

    ll_foreach(list_team, ll_t, t,
        ll_push_back(&server->teams, reload_teams(t))
    );
    parser_result_clean(p, r);
    return (remain);
}

const char * const *load_teams(server_t *server, const char * const *data)
{
    AND_PARSER(comment_parser, &UUID_PARSER, &UUID_PARSER, &INT_PARSER,
        &STRING_PARSER);
    TAB_PARSER(comments_parser, &comment_parser);
    AND_PARSER(thread_parser, &UUID_PARSER, &UUID_PARSER, &INT_PARSER,
        &STRING_PARSER, &STRING_PARSER, &comments_parser);
    TAB_PARSER(threads_parser, &thread_parser);
    AND_PARSER(channel_parser, &UUID_PARSER, &UUID_PARSER, &STRING_PARSER, &STRING_PARSER,
        &threads_parser);
    TAB_PARSER(channels_parsers, &channel_parser);
    TAB_PARSER(members_parser, &UUID_PARSER);
    AND_PARSER(team_parser, &UUID_PARSER, &UUID_PARSER, &STRING_PARSER, &STRING_PARSER,
        &channels_parsers, &members_parser);
    TAB_PARSER(teams_parser, &team_parser);
    parser_result_t *r = parse(data, &teams_parser);

    return ((r == NULL) ? NULL : parse_teams(server, &teams_parser, r));
}