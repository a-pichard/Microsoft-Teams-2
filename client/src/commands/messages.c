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

static void get_messages_info(int status_code, char const * const * remainer)
{
    time_t date;
    size_t i;

    if (status_code != 200) {
        dprintf(1, "%s\n", *(remainer));
        return;
    }
    for (i = 1; i < get_tab_len(remainer)-2; i += 4) {
        date = (time_t)remainer[i+2];
        client_private_message_print_messages(remainer[i], date, remainer[i + 3]);
    }
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
        get_messages_info(*(int *)(r_status->data), r_status->remainer);
    destroy_tab(data);
    parser_result_clean(&INT_PARSER, r_status);
}