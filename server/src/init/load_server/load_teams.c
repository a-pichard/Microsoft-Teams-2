/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** load_teams
*/

#include "server.h"
#include "parser.h"

#define TEAMS_PARSER    \
    AND_PARSER(comment_parser, &UUID_PARSER, &UUID_PARSER, &INT_PARSER, \
        &STRING_PARSER);    \
    TAB_PARSER(comments_parser, &comment_parser);   \
    AND_PARSER(thread_parser, &UUID_PARSER, &UUID_PARSER, &INT_PARSER,  \
        &STRING_PARSER, &STRING_PARSER, &comments_parser);   \
    TAB_PARSER(threads_parser, &thread_parser); \
    AND_PARSER(channel_parser, &UUID_PARSER, &STRING_PARSER,    \
        &STRING_PARSER, &threads_parser);  \
    TAB_PARSER(channels_parsers, &channel_parser);  \
    AND_PARSER(team_parser, &UUID_PARSER, &STRING_PARSER, &STRING_PARSER,   \
        &channels_parsers);   \
    TAB_PARSER(teams_parser, &team_parser); \

const char * const *load_teams(server_t *server, const char * const *data)
{
    TEAMS_PARSER
    const char * const *remain = NULL;
    parser_result_t *r = parse(data, &teams_parser);

    if (r == NULL) {
        return NULL;
    } else {
        //TODO reload everything
        printf("team parser sucess\n");
    }
    remain = r->remainer;
    parser_result_clean(&teams_parser, r);
    return remain;
}