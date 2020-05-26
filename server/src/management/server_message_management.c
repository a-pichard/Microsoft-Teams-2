/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** server_message_management
*/

#include "server.h"
#include "logging_server.h"

static void notify(server_t *server, msg_t *message)
{
    client_t *to = server_get_client_by_uuid(server, message->to);
    char *r = NULL;
    char *msg = NULL;
    char user_id[37];

    if (to == NULL)
        return;
    uuid_unparse(message->from, user_id);
    msg = strcat_alloc3(user_id, " \"", message->msg);
    r = strcat_alloc3("\"event\" \"message\" \"user\" ", msg, "\"");
    write_q(to, r);
    free(r);
    free(msg);
}

void server_add_private_message(server_t *server, msg_t *message)
{
    dm_t *dms = NULL;

    notify(server, message);
    ll_foreach(server->dms, dm_t, dm,
        if ((!uuid_compare(dm->user1, message->from) &&
            !uuid_compare(dm->user2, message->to)) ||
            (!uuid_compare(dm->user1, message->to) &&
            !uuid_compare(dm->user2, message->from))) {
            ll_push_back(&dm->msgs, message);
            return;
        }
    );
    dms = dm_create(message->from, message->to);
    ll_push_back(&dms->msgs, message);
    ll_push_back(&server->dms, dms);
}

dm_t *get_dms(server_t *server, uuid_t user1, uuid_t user2)
{
    ll_foreach(server->dms, dm_t, dm,
        if ((!uuid_compare(dm->user1, user1) &&
            !uuid_compare(dm->user2, user2)) ||
            (!uuid_compare(dm->user1, user2) &&
            !uuid_compare(dm->user2, user1))) {
            return dm;
        }
    );
    return NULL;
}