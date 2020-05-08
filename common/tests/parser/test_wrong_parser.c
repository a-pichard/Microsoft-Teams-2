/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** test_wrong_parser
*/

#include <criterion/criterion.h>
#include "parser.h"

Test(Test_parser, parser_wrong_parser)
{
    const char *token[] = {"42", "a", NULL};
    parser_t int_parser = INT_PARSER;
    int_parser.type = 10;

    TAB_PARSER(p, &int_parser);
    parser_result_t *r = parse(token, &p);
    cr_assert_eq(r, NULL);
}
