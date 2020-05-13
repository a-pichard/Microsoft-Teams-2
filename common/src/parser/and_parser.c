/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** and_parser
*/

#include "parser.h"

static void parse_and_cancel(const parser_t *parser, ll_t **list, int done)
{
    for (int j = 0; j < done; j++) {
        void *elem = ll_pop_front(list);
        parser->parsers[j]->destructor(elem);
    }
}

parser_result_t *parse_and(char const * const *token, const parser_t *parser)
{
    ll_t *result_list = NULL;
    char const * const *current = token;
    int i = 0;
    parser_result_t *result = NULL;

    for (; parser->parsers[i]; i++) {
        if (*current == NULL)
            break;
        result = parse(current, parser->parsers[i]);
        if (result == NULL)
            break;
        ll_push_back(&result_list, result->data);
        current = result->remainer;
        free(result);
    }
    if (parser->parsers[i]) {
        parse_and_cancel(parser, &result_list, i);
        return NULL;
    } else
        return create_result(result_list, current);
}