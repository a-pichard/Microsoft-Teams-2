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
    AND_PARSER(p, &UUID_PARSER, &STRING_PARSER);
    parser_result_t *r = parse(data, &p);
    ll_t *d;
    user_t *user;

    if (r == NULL) {
        write_q(client, "500");
    } else {
        d = r->data;
        user = get_user_by_uuid(server, d->data);
        if (user == NULL)
            return write_q_responce_objet(client, 400, d->data, uuid_serialize);
        server_add_private_message(server, msg_create(client->user->uuid,
            (unsigned char *)(d->data), (char *)(d->next->data)));
        write_q(client, "200");
    }
    parser_result_clean(&p, r);
}