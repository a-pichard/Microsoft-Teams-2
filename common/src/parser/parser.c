/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** parser
*/

#include "parser.h"
#include <stdlib.h>

parser_result_t *create_result(void *data, const char **token)
{
    parser_result_t *r = malloc(sizeof(parser_result_t));

    r->data = data;
    r->remainer = token;
    return r;
}

parser_result_t *parse_and(const char **token, parser_t *parser)
{
    ll_t *result_list = NULL;
    const char **current = token;
    int i = 0;

    for (; parser->parser[i]; i++) {
        if (*current == NULL) {
            break;
        }
        parser_result_t *result = parse(current, parser->parser[i]);
        if (result == NULL) {
            break;
        }
        ll_push_back(&result_list, result->data);
        current = result->remainer;
        free(result);
    }
    if (parser->parser[i]) {
        for (int j = 0; j < i; j++) {
            void *elem = ll_pop_front(&result_list);
            parser->parser[j]->destructor(elem);
        }
        return NULL;
    } else {
        return create_result(result_list, current);
    }
}

parser_result_t* parse(const char **token, parser_t *p)
{
    void *r = NULL;

    if (p->type == VALUE) {
        if (*token == NULL)
            return NULL;
        r = p->parser_function(*token);                
        if (r == NULL) {
            return NULL;
        } else {
            return create_result(r, token+1);
        }
    } else if (p->type == AND) {
        return parse_and(token, p);
    } else {
        return NULL;
    }
}

