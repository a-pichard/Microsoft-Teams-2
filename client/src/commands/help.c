/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** create
*/

#include "client.h"
#include <logging_client.h>
#include "common.h"
#include "parser.h"

void help(client_t *client, char const * recept)
{
    char **data = str_to_wordtab(recept, ' ', true);

    parser_result_t *r_status = parse(data, &INT_PARSER);

    if (r_status == NULL)
        dprintf(1, "Bad reponse.\n");
    else if (*(int *)(r_status->data) != 200)
        dprintf(1, "%s\n", *(r_status->remainer));
    else
        dprintf(1, "%s\n", *(r_status->remainer));
    destroy_tab(data);
    parser_result_clean(&INT_PARSER, r_status);
}