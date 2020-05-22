/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** messages
*/

#include "client.h"
#include <logging_client.h>
#include "common.h"
#include "parser.h"
#include "command.h"

static void get_messages_info(char const * const * remainer)
{
    char uuid_str[37];
    AND_PARSER(message_parser, &UUID_PARSER, &UUID_PARSER, 
    &INT_PARSER, &STRING_PARSER);
    TAB_PARSER(messages_parser, &message_parser);
    parser_result_t *r = parse(remainer, &messages_parser);

    if (r != NULL) {
        ll_foreach(r->data, ll_t, l,
            uuid_unparse(l->data, uuid_str);
            client_private_message_print_messages(uuid_str, 
            *(int *)l->next->next->data,
            l->next->next->next->data);
        );
    } else {
        dprintf(1, "Bad reponse.\n");
    }
    parser_result_clean(&messages_parser, r);
}

void messages(client_t *client UNUSED, char const * recept)
{
    char **data = str_to_wordtab((char *)recept, ' ', true);
    parser_result_t *r_status = parse((const char * const *)data, &INT_PARSER);

    if (r_status == NULL)
        dprintf(1, "Bad reponse.\n");
    else if (*(int *)(r_status->data) == 404)
        client_error_unknown_user(data[1]);
    else
        get_messages_info(r_status->remainer);
    destroy_tab(data);
    parser_result_clean(&INT_PARSER, r_status);
}