/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** tab_parser
*/

#include "parser.h"

parser_result_t *parse_tab(char const * const * token, const parser_t *parser)
{
    ll_t *result_list = NULL;
    char const * const * current = token+1;
    parser_result_t *result = NULL;

    if (strcmp(*token, "["))
        return NULL;
    while (*current != NULL && strcmp("]", *current)) {
        result = parse(current, parser->parser);
        if (result == NULL)
            break;
        ll_push_back(&result_list, result->data);
        current = result->remainer;
        free(result);
    }
    if (*current == NULL || strcmp("]", *current)) {
        ll_destroy(&result_list, parser->parser->destructor);
        return NULL;
    }
    return create_result(result_list, current+1);
}