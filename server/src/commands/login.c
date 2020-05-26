/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** login
*/

#include "cmd.h"
#include "parser.h"
#include "common.h"
#include <logging_server.h>

static void event_user_login(server_t *server, user_t *user)
{
    char *ser = user_serializer(user);
    char *msg = strcat_alloc("\"event\" \"login\" ", ser);
    ll_t *todo = get_user_to_notify(server, user);

    ll_foreach(server->clients, client_t, client,
        ll_foreach(todo, user_t, to_not,
            if (client->user == to_not) {
                write_q(client, msg);
            }
        );
    );
    ll_destroy(&todo, NULL);
    free(ser);
    free(msg);
}

void login(server_t *server, client_t *client, char const * const *data)
{
    user_t *user = NULL;
    char uuid_str[37];
    parser_result_t *r = parse(data, &STRING_PARSER);

    if (r == NULL || *r->remainer != NULL ||
        strlen((const char *)(r->data)) > DEFAULT_NAME_LENGTH) {
        write_q(client, "500 \"Bad argument\"");
    } else {
        if (client->user != NULL)
            return write_q(client, "300 \"user already slogged\"");
        user = get_user_by_name(server, r->data);
        if (user == NULL)
            user = server_add_user_with_name(server, r->data);
        client->user = user;
        client->user->status++;
        uuid_unparse(user->uuid, uuid_str);
        event_user_login(server, client->user);
        server_event_user_logged_in(uuid_str);
        write_q_responce_objet(client, 200, client->user, user_serializer);
    }
    parser_result_clean(&STRING_PARSER, r);
}