/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** event
*/

#include "client.h"
#include "event.h"

static event_t get_event_type(const char *type)
{
    char *event_names[] = EVENT_NAME;
    void *event_funcs[] = EVENT_FUNC;

    for (size_t i = 0; event_names[i]; i++)
        if (strcmp(event_names[i], type) == 0)
            return (event_funcs[i]);
    return NULL;
}

void parse_event(char *event_str)
{
    char **event_tab = str_to_wordtab(event_str, ' ', true);
    AND_PARSER(event_p, &STRING_PARSER, &STRING_PARSER);
    parser_result_t *r = parse((const char * const *)event_tab, &event_p);
    event_t event;

    if (r) {
        event = get_event_type((char *)((ll_t *)(r->data))->next->data);
        if (event)
            (event)(r->remainer);
    }
    parser_result_clean(&event_p, r);
    destroy_tab(event_tab);
}