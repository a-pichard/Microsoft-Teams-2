/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** login
*/

#include "client.h"
#include "logging_client.h"
#include "common.h"
#include "parser.h"

void login(client_t *client, char const * recept)
{
    char **data = str_to_wordtab(recept, ' ', true);
    char uuid_str[37];
    AND_PARSER(user_p, &UUID_PARSER, &STRING_PARSER, &INT_PARSER);
    parser_t sep_p = SEP_PARSER(' ', &user_p);
    parser_t suround = SUROUNDE_PARSER('"', &sep_p);
    parser_result_t *r_status = parse(data, &INT_PARSER);

    if (r_status == NULL) {
        return; // invalid args
    }
    printf("status=%d\n", *(int *)(r_status->data));
    if (*(int *)(r_status->data) != 200) {
        //error
    } else {
        print_tab(r_status->remainer);
        parser_result_t *r = parse(r_status->remainer, &suround);
        if (r) {
            ll_t *user = r->data;
            uuid_unparse(user->data, uuid_str);
            client_event_loggedin(uuid_str, user->next->data);
        } else {
            //error
        }
    }
    parser_result_clean(&p, r);
}
