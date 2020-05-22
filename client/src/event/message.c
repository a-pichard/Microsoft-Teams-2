/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** message
*/

#include "client.h"
#include "event.h"
#include "logging_client.h"

static void dm(const char * const *recept)
{
    char uuid_str[37];
    AND_PARSER(dm_p, &UUID_PARSER, &STRING_PARSER);
    parser_result_t *r = parse(recept, &dm_p);
    ll_t *dm = NULL;

    if (r) {
        dm = r->data;
        uuid_unparse(dm->data, uuid_str);
        client_event_private_message_received(uuid_str, dm->next->data);
    }
    parser_result_clean(&dm_p, r);
}

static void thread(const char * const *recept)
{
    char team_uuid[37];
    char thread_uuid[37];
    char user_uuid[37];
    AND_PARSER(tm_p, &UUID_PARSER, &UUID_PARSER, &UUID_PARSER, &INT_PARSER,
        &STRING_PARSER);
    parser_result_t *r = parse(recept, &tm_p);
    ll_t *tm = NULL;

    if (r) {
        tm = r->data;
        uuid_unparse(tm->data, team_uuid);
        uuid_unparse(tm->next->data, thread_uuid);
        uuid_unparse(tm->next->next->data, user_uuid);
        client_event_thread_message_received(team_uuid, thread_uuid, user_uuid,
        tm->next->next->next->next->data);
    }
    parser_result_clean(&tm_p, r);
}

void message_e(const char * const *recept)
{
    char *f_name[] = {"user", "thread", NULL};
    event_t f[] = {&dm, &thread, NULL};
    parser_result_t *r = parse(recept, &STRING_PARSER);

    for (size_t i = 0; f_name[i]; i++) {
        if (!strcmp(f_name[i], (char *)r->data))
            (f[i])(r->remainer);
    }
    parser_result_clean(&STRING_PARSER, r);
}