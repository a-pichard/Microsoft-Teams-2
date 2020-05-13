/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** parser
*/

#include "parser.h"
#include <stdlib.h>
#include "common.h"
#include <stdbool.h>

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

static parser_result_t *parse_surounded(char const *const *token, parser_t *p)
{
    char *data[] = {NULL, NULL};
    char *str = NULL;
    parser_result_t *p_r;

    if (strlen(*token) < 2) {
        return NULL;
    }
    if ((*token)[0] != p->sep || (*token)[strlen(*token)-1] != p->sep)
        return NULL;
    str = strdup(*token+1);
    str[strlen(str)-1] = '\0';
    data[0] = str;
    p_r = parse((char const * const *)data, p->parser);
    p_r->remainer = token + 1;
    free(str);
    return p_r;
}

static parser_result_t *parse_sep(char const *const *token, parser_t *p)
{
    parser_result_t *p_r;
    const char * const *tab = (const char * const *)str_to_wordtab((char*)(*token), p->sep, true);

    p_r = parse(tab, p->parser);
    destroy_tab((char **)tab);
    return p_r;
}

parser_result_t* parse(char const * const * token, parser_t *p)
{
    if (*token == NULL)
        return NULL;
    if (p->type == VALUE) {
        return parse_value(token, p);
    } else if (p->type == AND) {
        return parse_and(token, p);
    } else if (p->type == TAB) {
        return parse_tab(token, p);
    } else if (p->type == SUROUNDED) {
        return parse_surounded(token, p);
    } else if (p->type == SEP) {
        return parse_sep(token, p);
    } else {
        return NULL;
    }
}