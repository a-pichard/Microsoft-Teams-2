/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** subscribe
*/

#include "client.h"
#include <logging_client.h>
#include "common.h"
#include "parser.h"

static void parse_subscribe(char const * const *remainer)
{
    char uuid_str[37];
    char uuid_str2[37];
    AND_PARSER(user_p, &UUID_PARSER, &UUID_PARSER);
    parser_result_t *r = parse(remainer, &user_p);
    ll_t *user;

    if (r) {
        user = r->data;
        uuid_unparse(user->data, uuid_str);
        uuid_unparse(user->next->data, uuid_str2);
        client_print_subscribed(uuid_str, uuid_str2);
    } else {
        dprintf(1, "Bad reponse.\n");
    }
    parser_result_clean(&user_p, r);
}

void subscribe(client_t *client, char const * recept)
{
    char **data = str_to_wordtab((char *)recept, ' ', true);
    parser_result_t *r_status = parse((const char * const *)data, &INT_PARSER);
    if (r_status == NULL)
        dprintf(1, "Bad reponse.\n");
    else if (*(int *)(r_status->data) != 200)
        !*r_status->remainer ? 0 : dprintf(1, "%s\n", *(r_status->remainer));

    else
        parse_subscribe(r_status->remainer);
    destroy_tab(data);
    parser_result_clean(&INT_PARSER, r_status);
}
