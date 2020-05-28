/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** subscribed
*/

#include "client.h"
#include <logging_client.h>
#include "common.h"
#include "parser.h"

static void subscribed_team(char const * const *remainer)
{
    char uuid_str[37];
    AND_PARSER(team_parser, &UUID_PARSER, &STRING_PARSER, &STRING_PARSER);
    TAB_PARSER(teams_parser, &team_parser);
    parser_result_t *r = parse(remainer, &teams_parser);

    if (r != NULL) {
        ll_foreach(r->data, ll_t, list,
            uuid_unparse(list->data, uuid_str);
            client_print_teams(uuid_str, list->next->data,
            list->next->next->data);
        );
    } else {
        dprintf(1, "Bad reponse.\n");
    }
    parser_result_clean(&teams_parser, r);
}

static void subscribed_users(char const * const * remainer)
{
    char uuid_str[37];
    AND_PARSER(user_p, &UUID_PARSER, &STRING_PARSER, &INT_PARSER);
    TAB_PARSER(users_parser, &user_p);
    parser_result_t *r = parse(remainer, &users_parser);

    if (r != NULL) {
        ll_foreach(r->data, ll_t, list,
            uuid_unparse(list->data, uuid_str);
            client_print_user(uuid_str, list->next->data,
            *(int *)list->next->next->data >= 1 ? 1 : 0);
        );
    } else {
        dprintf(1, "Bad reponse.\n");
    }
    parser_result_clean(&users_parser, r);
}

void subscribed(client_t *client UNUSED, char const * recept)
{
    char **data = str_to_wordtab((char *)recept, ' ', true);
    parser_result_t *r_status = parse((const char * const *)data, &INT_PARSER);

    if (!r_status)
        dprintf(1, "Bad reponse.\n");
    if (*(int *)r_status->data == 300)
        client_error_unauthorized();
    else if (*(int *)r_status->data == 404)
        !*r_status->remainer ? 0 : dprintf(1, "%s\n", *(r_status->remainer));
    else
        if (*(int *)r_status->data == 201)
            subscribed_team(r_status->remainer);
        else
            subscribed_users(r_status->remainer);
    destroy_tab(data);
    parser_result_clean(&INT_PARSER, r_status);
}