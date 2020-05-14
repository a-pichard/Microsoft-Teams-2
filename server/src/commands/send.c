/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** send
*/

#include "cmd.h"
#include "parser.h"

void my_send(server_t *server, client_t *client, char const * const *data)
{
    parser_t msg = SUROUNDE_PARSER('"', &STRING_PARSER);
    AND_PARSER(p, &UUID_PARSER, &msg);
    parser_result_t *r = parse(data, &p);
    ll_t *d;

    if (r == NULL) {
        write_q(client, "300"); // TODO
    } else {
        //todo check that uuid exit
        d = r->data;
        server_add_private_message(server, msg_create(client->user->uuid,
            (unsigned char *)(d->data), (char *)(d->next->data)));
    }
    parser_result_clean(&p, r);
}