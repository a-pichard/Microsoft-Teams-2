/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** server_message_management
*/

#include "server.h"

void server_add_private_message(
    server_t *server, uuid_t from, uuid_t to, const char *content)
{
    msg_t *message = msg_create(from, to, content);
    dm_t *dms = NULL;

    ll_foreach(server->dms, dm_t, dm,
        if ((!uuid_compare(dm->user1, from) && !uuid_compare(dm->user2, to)) ||
             (!uuid_compare(dm->user1, to) && !uuid_compare(dm->user2, from))) {
            ll_push_back(&dm->msgs, message);
            return;
        }
    );
    dms = dm_create(from, to);
    ll_push_back(&dms->msgs, message);
    ll_push_back(&server->dms, dms);
    //todo create new dm and add mesage
}

