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

void subscribed(client_t *client UNUSED, char const * recept)
{
    char **data = str_to_wordtab((char *)recept, ' ', true);
    parser_result_t *r_status = parse((const char * const *)data, &INT_PARSER);

    if (!r_status)
        dprintf(1, "Bad reponse.\n");
    if (*(int *)r_status->data == 300)
        client_error_unauthorized();
}