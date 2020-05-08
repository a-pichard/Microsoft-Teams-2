/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** login
*/

#include "cmd.h"
#include "parser.h"

void login(server_t *server UNUSED, client_t *client, char const * const *data UNUSED)
{
    parser_t int_parser = STRING_PARSER;
    
    AND_PARSER(p, &int_parser);
    // parser_t p = {.type=AND, {.parsers=(parser_t**){&int_parser, NULL}}};

    parser_result_t *r = parse(data, &p);

    if (r == NULL) {
        write_q(client, "500 \"Bad argument\"");
    } else {
        write_q(client, "200 \"login success\"");
    }

}