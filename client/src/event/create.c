/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** create
*/

#include "client.h"
#include "event.h"
#include "logging_client.h"

static void team(const char * const *recept)
{
    char uuid_str[37];
    AND_PARSER(ct_p, &UUID_PARSER, &STRING_PARSER, &STRING_PARSER);
    parser_result_t *r = parse(recept, &ct_p);
    ll_t *ct = NULL;
    char *team_name = NULL;
    char *team_desc = NULL;

    if (r) {
        ct = r->data;
        uuid_unparse(ct->data, uuid_str);
        team_name = ct->next->data;
        team_desc = ct->next->next->data;
        client_event_team_created(uuid_str, team_name, team_desc);
    }
    parser_result_clean(&ct_p, r);
}

static void channel(const char * const *recept)
{
    char uuid_str[37];
    AND_PARSER(cc_p, &UUID_PARSER, &STRING_PARSER, &STRING_PARSER);
    parser_result_t *r = parse(recept, &cc_p);
    ll_t *cc = NULL;
    char *channel_name = NULL;
    char *channel_desc = NULL;

    if (r) {
        cc = r->data;
        uuid_unparse(cc->data, uuid_str);
        channel_name = cc->next->data;
        channel_desc = cc->next->next->data;
        client_event_channel_created(uuid_str, channel_name, channel_desc);
    }
    parser_result_clean(&cc_p, r);
}

static void thread(const char * const *recept)
{
}

void create_e(const char * const *recept)
{
    char *f_name[] = {"team", "channel", "thread", NULL};
    event_t f[] = {&team, &channel, &thread, NULL};
    parser_result_t *r = parse(recept, &STRING_PARSER);

    for (size_t i = 0; f_name[i]; i++) {
        if (!strcmp(f_name[i], (char *)r->data))
            (f[i])(r->remainer);
    }
    parser_result_clean(&STRING_PARSER, r);
}