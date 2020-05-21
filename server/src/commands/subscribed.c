/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** subscribed
*/

#include "server.h"
#include "parser.h"

static void subscribed_user(server_t *server, client_t *client,
    char const * const *data)
{

}

static void subscribed_team(server_t *server, client_t *client,
    char const * const *data)
{
    parser_result_t *r = parse(data, &UUID_PARSER);
    
    parser_result_clean(&UUID_PARSER, r);
}

void subscribed(server_t *server, client_t *client, char const * const *data)
{
    size_t len = get_tab_len(data);

    //TODO revoir protocol
    if (len == 0) {
        subscribed_user(server, client, data);
    } else if (len == 1) {
        subscribed_team(server, client, data);
    } else {
        write_q(client, "300");
    }
}