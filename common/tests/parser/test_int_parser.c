/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** test_parser
*/

#include "criterion/criterion.h"
#include "parser.h"

Test(Test_parser, parser_int_ok)
{
    char *str = "toto";
    const char *token[] = {"10", str, NULL};
    parser_t p = INT_PARSER;
    parser_result_t *r = parse(token, &p);

    cr_assert_neq(r, NULL);
    cr_assert_eq(*(int *)(r->data), 10);
    cr_assert_eq(*r->remainer, str);
}

Test(Test_parser, parser_int_fail1)
{
    char *str = "toto";
    const char *token[] = {"a10", str, NULL};
    parser_t p = INT_PARSER;
    parser_result_t *r = parse(token, &p);

    cr_assert_eq(r, NULL);
}

Test(Test_parser, parser_int_fail2)
{
    const char *token[] = {NULL};
    parser_t p = INT_PARSER;
    parser_result_t *r = parse(token, &p);

    cr_assert_eq(r, NULL);
}