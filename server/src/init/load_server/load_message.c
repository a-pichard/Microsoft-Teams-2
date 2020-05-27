/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace) [WSL: Debian]
** File description:
** load_message
*/

#include "server.h"
#include "common.h"
#include "parser.h"

static void loop_in_dms(server_t *server, parser_result_t *r)
{
    ll_foreach(r->data, ll_t, dm,
        ll_foreach(dm->next->next->data, ll_t, m,
            msg_t *msg = message_reload(
                (unsigned char *)m->data,
                (unsigned char *)m->next->data,
                *(time_t *)(m->next->next->data),
                (char *)(m->next->next->next->data));
            server_add_private_message(server, msg);
        );
    );
}

const char * const *load_message(server_t *server, const char * const *data)
{
    const char * const *remain = NULL;
    parser_result_t *r = NULL;

    AND_PARSER(message, &UUID_PARSER, &UUID_PARSER,
        &INT_PARSER, &STRING_PARSER);
    TAB_PARSER(messages_parser, &message);
    AND_PARSER(dm, &UUID_PARSER, &UUID_PARSER, &messages_parser);
    TAB_PARSER(p, &dm);
    r = parse(data, &p);
    if (r == NULL) {
        printf("r = NULL\n");
        return NULL;
    }
    loop_in_dms(server, r);
    remain = r->remainer;
    parser_result_clean(&p, r);
    return remain;
}