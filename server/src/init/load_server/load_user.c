/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace) [WSL: Debian]
** File description:
** load_user
*/

#include "server.h"
#include "common.h"
#include "parser.h"

const char * const *load_user(server_t *server, const char * const *data)
{
    AND_PARSER(user_parser, &UUID_PARSER, &STRING_PARSER, &INT_PARSER);
    TAB_PARSER(users_parser, &user_parser);
    const char * const *remain = NULL;
    parser_result_t *r = parse(data, &users_parser);

    if (r != NULL) {
        ll_foreach(r->data, ll_t, usr,
            user_t *t = user_reload(
                (const char *)usr->next->data,
                (unsigned char *)usr->data,
                *(int *)(usr->next->next->data));
            ll_push_back(&server->users, t);
        );
    }
    remain = r->remainer;
    parser_result_clean(&users_parser, r);
    return remain;
}