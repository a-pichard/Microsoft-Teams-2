/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** load_teams
*/

#include "server.h"
#include "parser.h"

static const char * const *parse_teams(server_t *server, const parser_t *p,
    parser_result_t *r)
{
    const char * const *remain = r->remainer;

    // load here
    printf("team parser sucess\n");
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
    AND_PARSER(channel_parser, &UUID_PARSER, &STRING_PARSER, &STRING_PARSER,
        &threads_parser);
    TAB_PARSER(channels_parsers, &channel_parser);
    AND_PARSER(team_parser, &UUID_PARSER, &STRING_PARSER, &STRING_PARSER,
        &channels_parsers);
    TAB_PARSER(teams_parser, &team_parser);
    parser_result_t *r = parse(data, &teams_parser);

    return ((r == NULL) ? NULL : parse_teams(server, &teams_parser, r));
}