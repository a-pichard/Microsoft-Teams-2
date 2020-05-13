/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** parser_result_clean
*/

#include "parser.h"
#include "linked_list.h"

static void parser_clean(parser_t *p, void *r);

static void and_parser_destructor(parser_t *p, void *r) {
    int i = 0;

    ll_foreach((ll_t*)(r), void, v,
        parser_clean(p->parsers[i], v);
        i++;
    );
    ll_destroy(&r, NULL);
}

static void tab_parser_destructor(parser_t *p, void *r) {
    ll_foreach((ll_t*)(r), void, v,
        parser_clean(p->parser, v);
    );
    ll_destroy(&r, NULL);
}

static void parser_clean(parser_t *p, void *r) {
    if (p->type == VALUE) {
        p->destructor(r);
    } else if (p->type == AND) {
        and_parser_destructor(p, r);
    } else if (p->type == TAB) {
        tab_parser_destructor(p, r);
    } else if (p->type == SUROUNDED || p->type == SEP) {
        parser_clean(p->parser, r);
    }
}

void parser_result_clean(parser_t *p, parser_result_t *r)
{
    if (r == NULL)
        return;
    parser_clean(p, r->data);
    free(r);
}