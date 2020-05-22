/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** create
*/

#include "client.h"
#include <logging_client.h>
#include "common.h"
#include "parser.h"

static void create_team(char const * const *remainer)
{
    char uuid_str[37];
    AND_PARSER(user_p, &UUID_PARSER, &STRING_PARSER, &STRING_PARSER);
    parser_result_t *r = parse(remainer, &user_p);
    ll_t *user;

    if (r) {
        user = r->data;
        uuid_unparse(user->data, uuid_str);
        client_print_team_created(uuid_str, user->next->data,
        user->next->next->data);
    } else {
        dprintf(1, "Bad reponse.\n");
    }
    parser_result_clean(&user_p, r);
}

static void create_channel(char const * const *remainer)
{
    char uuid_str[37];
    AND_PARSER(user_p, &UUID_PARSER, &STRING_PARSER, &STRING_PARSER);
    parser_result_t *r = parse(remainer, &user_p);
    ll_t *user;

    if (r) {
        user = r->data;
        uuid_unparse(user->data, uuid_str);
        client_print_channel_created(uuid_str, user->next->data,
        user->next->next->data);
    } else {
        dprintf(1, "Bad reponse.\n");
    }
    parser_result_clean(&user_p, r);
}

static void create_thread(char const * const *remainer)
{
    char uuid_str[37];
    char uuid2_str[37];
    AND_PARSER(user_p, &UUID_PARSER, &UUID_PARSER, &STRING_PARSER,
    &STRING_PARSER, &STRING_PARSER);
    parser_result_t *r = parse(remainer, &user_p);
    ll_t *user;

    if (r) {
        user = r->data;
        uuid_unparse(user->data, uuid_str);
        uuid_unparse(user->next->data, uuid2_str);
        client_print_thread_created(uuid_str, uuid2_str,
        (time_t)user->next->next->data,
        user->next->next->next->data, user->next->next->next->next->data);
    } else {
        dprintf(1, "Bad reponse.\n");
    }
    parser_result_clean(&user_p, r);
}

static void create_reply(char const * const *remainer)
{
    char uuid_str[37];
    char uuid_str2[37];
    AND_PARSER(user_p, &UUID_PARSER, &STRING_PARSER, &STRING_PARSER,
    &STRING_PARSER);
    parser_result_t *r = parse(remainer, &user_p);
    ll_t *user;

    if (r) {
        user = r->data;
        uuid_unparse(user->data, uuid_str);
        uuid_unparse(user->next->data, uuid_str2);
        client_print_reply_created(uuid_str, uuid_str2, 
        (time_t)user->next->next->data,
        user->next->next->next->data);
    } else {
        dprintf(1, "Bad reponse.\n");
    }
    parser_result_clean(&user_p, r);
}

void create(client_t *client UNUSED, char const * recept)
{
    char **data = str_to_wordtab((char *)recept, ' ', true);
    parser_result_t *r_status = parse((const char * const *)data, &INT_PARSER);

    if (r_status == NULL)
        dprintf(1, "Bad reponse.\n");
    else
        switch (*(int *)(r_status->data)) {
            case 200:
                create_team(r_status->remainer);
                break;
            case 201:
                create_channel(r_status->remainer);
                break;
            case 202:
                create_thread(r_status->remainer);
                break;
            case 203:
                create_reply(r_status->remainer);
                break;
            default:
                !*r_status->remainer ? 0 : dprintf(1, "%s\n", *(r_status->remainer));
        }
    destroy_tab(data);
    parser_result_clean(&INT_PARSER, r_status);
}