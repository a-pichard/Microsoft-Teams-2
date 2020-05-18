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
    size_t i;

    for (i = 1; i < get_tab_len(remainer)-2; i += 3) {
        client_print_user(remainer[i], remainer[i +1], atoi(remainer[i+2]));
    }
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
