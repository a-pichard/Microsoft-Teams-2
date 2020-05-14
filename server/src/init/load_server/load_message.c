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
        ll_foreach(dm->next->next->data, ll_t, l,
            msg_t *msg = message_reload(
                (unsigned char *)l->data,
                (unsigned char *)l->next->data,
                *(time_t *)(l->next->next->data),
                (char *)(l->next->next->next->data));
            server_add_private_message(server, msg);
        );
    );
}

const char * const *load_message(server_t *server, const char * const *data)
{
    parser_t suroud_parser = SUROUNDE_PARSER('"', &STRING_PARSER);
    const char * const *remain = NULL;
    parser_result_t *r = NULL;

    AND_PARSER(message, &UUID_PARSER, &UUID_PARSER,
        &INT_PARSER, &suroud_parser);
    TAB_PARSER(messages_parser, &message);
    AND_PARSER(dm, &UUID_PARSER, &UUID_PARSER, &messages_parser);
    TAB_PARSER(p, &dm);
    r = parse(data, &p);
    if (r == NULL)
        return NULL;
    loop_in_dms(server, r);
    remain = r->remainer;
    parser_result_clean(&p, r);
    return remain;
}