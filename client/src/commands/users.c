/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** users
*/

#include "client.h"
#include <logging_client.h>
#include "common.h"
#include "parser.h"

static void get_users_infos(char const * const * remainer)
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

void users(client_t *client UNUSED, char const * recept)
{
    char **data = str_to_wordtab((char *)recept, ' ', true);

    parser_result_t *r_status = parse((const char * const *)data, &INT_PARSER);

    if (r_status == NULL)
        dprintf(1, "Bad reponse.\n");
    else if (*(int *)(r_status->data) != 200)
        dprintf(1, "%s\n", *(r_status->remainer));
    else
        get_users_infos(r_status->remainer);
    destroy_tab(data);
    parser_result_clean(&INT_PARSER, r_status);
}
