/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** messages
*/

#include "cmd.h"
#include "parser.h"
#include "data.h"

void messages(server_t *server, client_t *client, char const * const *data)
{
    parser_result_t *r = parse(data, &UUID_PARSER);
    dm_t *dm;
    char *result;
    char *temp;

    if (r == NULL || *r->remainer != NULL) {
        write_q(client, "300");
    } else {
        dm = get_dms(server, client->user->uuid, r->data);
        if (dm == NULL) {
            write_q(client, "404");
        } else {
            temp = ll_serialize(&dm->msgs, &msg_serializer);
            printf("[%s]\n", temp);
            result = strcat_alloc("200 ", temp);
            free(temp);
            write_q(client, result);
            free(result);
        }
    }
    parser_result_clean(&UUID_PARSER, r);
}