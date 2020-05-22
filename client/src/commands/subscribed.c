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

// static void list_team(parser_result_t *r)
// {
//     char uuid_str[37];

//     ll_foreach(r->data, ll_t, l,
//         uuid_unparse(l->data, uuid_str);
//         client_print_teams(uuid_str, l->next->data, l->next->next->data);
//     );
// }

// static void list_user(parser_result_t *r)
// {
//     char uuid_str[37];

//     ll_foreach(r->data, ll_t, l,
//         uuid_unparse(l->data, uuid_str);
//         dprintf(1, "User %s (%s) %d\n", (char *)l->next->data, uuid_str,
//         *(int *)l->next->next->data);
//     );
// }

// void print_subscribed(char const * const *remainer)
// {
//     AND_PARSER(team_parser, &UUID_PARSER, &STRING_PARSER, &STRING_PARSER);
//     AND_PARSER(user_parser, &UUID_PARSER, &STRING_PARSER, &INT_PARSER);
//     TAB_PARSER(users_parser, &user_parser);
//     TAB_PARSER(teams_parser, &team_parser);
//     parser_result_t *r_teams = parse(remainer, &users_parser);
//     parser_result_t *r_user = parse(remainer, &teams_parser);

//     if (r_teams && !r_user) {
//         list_team(r_teams);
//     } else if (r_user && !r_teams) {
//         list_user(r_user);
//     } else
//         dprintf(1, "Bad reponse.\n");
//     parser_result_clean(&teams_parser, r_user);
//     parser_result_clean(&users_parser, r_teams);
// }

void subscribed(client_t *client UNUSED, char const * recept)
{
    char **data = str_to_wordtab((char *)recept, ' ', true);
    parser_result_t *r_status = parse((const char * const *)data, &INT_PARSER);

    for (int i = 0; data[i]; i++)
        printf("%s\n", data[i]);
    if (!r_status)
        dprintf(1, "Bad reponse.\n");
    if (*(int *)r_status->data == 300)
        client_error_unauthorized();
    else if (*(int *)r_status->data == 404)
        dprintf(1, "%s\n", *(r_status->remainer));
    // else
    //     print_subscribed(r_status->remainer);
}