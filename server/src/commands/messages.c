/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** messages
*/

#include "cmd.h"
#include "parser.h"
#include "data.h"

void messages(server_t *server, client_t *c, char const * const *data)
{
    parser_result_t *r = parse(data, &UUID_PARSER);
    dm_t *dm;

    if (r == NULL || *r->remainer != NULL) {
        write_q(c, "500");
    } else {
        if (get_user_by_uuid(server, r->data) == NULL)
            return write_q_responce_objet(c, 400, r->data, uuid_serialize);
        dm = get_dms(server, c->user->uuid, r->data);
        write_q_responce_objet_list(c, 200, dm->msgs,
            msg_serializer);
    }
    parser_result_clean(&UUID_PARSER, r);
}