/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** messages
*/

#include "cmd.h"
#include "parser.h"
#include "data.h"

static int test_user_exit(server_t *server, client_t *client, uuid_t uuid)
{
    user_t *user = get_user_by_uuid(server, uuid);
    char res[50] = "404 ";

    if (user != NULL) {
        return true;
    } else {
        uuid_unparse(uuid, res + 4);
        write_q(client, res);
        return false;
    }
}

static void send_dm(client_t *client, dm_t *dm)
{
    char *result;
    char *temp;

    temp = ll_serialize(&dm->msgs, &msg_serializer);
    result = strcat_alloc("200 ", temp);
    free(temp);
    write_q(client, result);
    free(result);
}

void messages(server_t *server, client_t *client, char const * const *data)
{
    parser_result_t *r = parse(data, &UUID_PARSER);
    dm_t *dm;

    if (r == NULL || *r->remainer != NULL) {
        write_q(client, "300");
    } else {
        if (!test_user_exit(server, client, (unsigned char *)(r->data))) {
            return;
        }
        dm = get_dms(server, client->user->uuid, r->data);
        if (dm == NULL) {
            write_q(client, "200 [ ]");
        } else {
            send_dm(client, dm);
        }
    }
    parser_result_clean(&UUID_PARSER, r);
}