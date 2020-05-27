/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** use
*/

#include "client.h"
#include <logging_client.h>

void use(client_t *client UNUSED, char const * recept)
{
    char **data = str_to_wordtab((char *)recept, ' ', true);
    parser_result_t *r = parse((const char * const *)data, &INT_PARSER);

    if (!r || *(int *)r->data != 200)
        dprintf(1, "Error, cannot change context.\n");
    else
        dprintf(1, "Context changed.\n");
    parser_result_clean(&INT_PARSER, r);
}