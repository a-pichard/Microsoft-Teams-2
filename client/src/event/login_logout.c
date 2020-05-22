/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** login_logout
*/

#include "client.h"
#include "logging_client.h"

static void handle_auth_event(const char * const *recept,
    int (*f)(char const *, const char *))
{
    char uuid_str[37];
    AND_PARSER(user_p, &UUID_PARSER, &STRING_PARSER, &INT_PARSER);
    parser_result_t *r = parse(recept, &user_p);
    ll_t *user;

    if (r) {
        user = r->data;
        uuid_unparse(user->data, uuid_str);
        (f)(uuid_str, user->next->data);
    }
    parser_result_clean(&user_p, r);
}

void login_e(const char * const *recept)
{
    handle_auth_event(recept, &client_event_loggedin);
}

void logout_e(const char * const *recept)
{
    handle_auth_event(recept, &client_event_loggedout);
}