/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** list
*/

#include "client.h"
#include <logging_client.h>
#include "common.h"
#include "parser.h"

static void list_team(char const * const *remainer)
{
    char uuid_str[37];
    AND_PARSER(team_parser, &UUID_PARSER, &STRING_PARSER, &STRING_PARSER);
    TAB_PARSER(teams_parser, &team_parser);
    parser_result_t *r = parse(remainer, &teams_parser);

    if (r != NULL) {
        ll_foreach(r->data, ll_t, list,
            uuid_unparse(list->data, uuid_str);
            client_print_teams(uuid_str, list->next->data,
            list->next->next->data);
        );
    } else {
        dprintf(1, "Bad reponse.\n");
    }
    parser_result_clean(&teams_parser, r);
}

static void list_channel(char const * const *remainer)
{
    AND_PARSER(channel_parser, &UUID_PARSER, &STRING_PARSER, &STRING_PARSER);
    TAB_PARSER(channels_parser, &channel_parser);
    char uuid_str[37];
    parser_result_t *r = parse(remainer, &channels_parser);

    if (r != NULL) {
        ll_foreach(r->data, ll_t, list,
            uuid_unparse(list->data, uuid_str);
            client_print_channel(uuid_str, list->next->data,
            list->next->next->data);
        );
    } else {
        dprintf(1, "Bad reponse.\n");
    }
    parser_result_clean(&channels_parser, r);
}

static void list_thread(char const * const *remainer)
{
    AND_PARSER(thread_parser, &UUID_PARSER, &UUID_PARSER,
    &INT_PARSER, &STRING_PARSER, &STRING_PARSER);
    TAB_PARSER(threads_parser, &thread_parser);
    char uuid_str[37];
    char uuid2_str[37];
    parser_result_t *r = parse(remainer, &threads_parser);

    if (r != NULL) {
        ll_foreach(r->data, ll_t, list,
            uuid_unparse(list->data, uuid_str);
            uuid_unparse(list->next->data, uuid2_str);
            client_channel_print_threads(uuid_str, uuid2_str,
            *(int *)list->next->next->data,
            list->next->next->next->data,
            list->next->next->next->next->data);
        );
    } else
        dprintf(1, "Bad reponse.\n");
    parser_result_clean(&threads_parser, r);
}

static void list_reply(char const * const *remainer)
{
    char uuid_str[37];
    char uuid_str2[37];
    AND_PARSER(user_p, &UUID_PARSER, &UUID_PARSER, &INT_PARSER,
    &STRING_PARSER);
    TAB_PARSER(replys_parser, &user_p);
    parser_result_t *r = parse(remainer, &replys_parser);

    if (r != NULL) {
        ll_foreach(r->data, ll_t, list,
            uuid_unparse(list->data, uuid_str);
            uuid_unparse(list->next->data, uuid_str2);
            client_thread_print_replies(uuid_str, uuid_str2,
            *(int *)list->next->next->data,
            list->next->next->next->data);
        );
    } else {
        dprintf(1, "Bad reponse.\n");
    }
    parser_result_clean(&replys_parser, r);
}

void list(client_t *client UNUSED, char const * recept)
{
    int status[] = {200, 201, 202, 203};
    void (*f[])(char const * const *) = {list_team, list_channel,
    list_thread, list_reply, NULL};
    char **data = str_to_wordtab((char *)recept, ' ', true);
    parser_result_t *r_status = parse((const char * const *)data, &INT_PARSER);
    size_t i = 0;

    if (r_status == NULL) {
        dprintf(1, "Bad reponse.\n");
        return;
    }
    for (i = 0; f[i] != NULL; i++) {
        if (status[i] == *(int *)(r_status->data)) {
            f[i](r_status->remainer);
        }
    }
    if (f[i] == NULL && !*r_status->remainer)
        dprintf(1, "%s\n", *(r_status->remainer));
    destroy_tab(data);
    parser_result_clean(&INT_PARSER, r_status);
}
