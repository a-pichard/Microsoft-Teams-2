/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** logout
*/

#include "client.h"
#include "logging_client.h"
#include "common.h"
#include "parser.h"

static void get_user_infos(char const * const *remainer)
{
    char uuid_str[37];
    AND_PARSER(user_p, &UUID_PARSER, &STRING_PARSER, &INT_PARSER);
    parser_t sep_p = SEP_PARSER(' ', &user_p);
    parser_t suround = SUROUNDE_PARSER('"', &sep_p);
    parser_result_t *r = parse(remainer, &suround);
    ll_t *user;

    if (r) {
        user = r->data;
        uuid_unparse(user->data, uuid_str);
        client_event_loggedout(uuid_str, user->next->data);
    } else {
        dprintf(1, "Bad reponse.\n");
    }
    parser_result_clean(&suround, r);
}

void logout(client_t *client, char const * recept)
{
    char **data = str_to_wordtab(recept, ' ', true);

    parser_result_t *r_status = parse(data, &INT_PARSER);

    if (r_status == NULL)
        dprintf(1, "Bad reponse.\n");
    else if (*(int *)(r_status->data) != 200)
        dprintf(1, "%s\n", *(r_status->remainer));
    else
        get_user_infos(r_status->remainer);
    destroy_tab(data);
    parser_result_clean(&INT_PARSER, r_status);
}