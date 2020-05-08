/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** parser
*/

#include "parser.h"
#include <stdlib.h>

parser_result_t *create_result(void *data, char const * const * token)
{
    parser_result_t *r = malloc(sizeof(parser_result_t));

    r->data = data;
    r->remainer = token;
    return r;
}

static parser_result_t *parse_value(char const * const *token, parser_t *p)
{
    void *r = NULL;

    if (*token == NULL)
        return NULL;
    r = p->parser_function(*token);                
    if (r == NULL) {
        return NULL;
    } else {
        return create_result(r, token+1);
    }
}

parser_result_t* parse(char const * const * token, parser_t *p)
{
    if (p->type == VALUE) {
        return parse_value(token, p);
    } else if (p->type == AND) {
        return parse_and(token, p);
    } else if (p->type == TAB) {
        return parse_tab(token, p);
    } else {
        return NULL;
    }
}