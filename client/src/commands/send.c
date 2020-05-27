/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** send
*/

#include "client.h"
#include "logging_client.h"
#include "common.h"
#include "parser.h"

void send(client_t *client UNUSED, char const * recept)
{
    char **data = str_to_wordtab((char *)recept, ' ', true);
    parser_result_t *r = parse((const char * const *)data, &INT_PARSER);

    if (!r || *(int *)r->data != 200)
        dprintf(1, "Cannot send message.\n");
    else
        dprintf(1, "Messaged sent.\n");
    parser_result_clean(&INT_PARSER, r);
    destroy_tab(data);
}