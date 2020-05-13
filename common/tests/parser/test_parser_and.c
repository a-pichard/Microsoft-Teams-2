/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** test_uuid_parser
*/

#include <criterion/criterion.h>
#include "parser.h"
#include <uuid/uuid.h>

Test(Test_parser, parser_paser_and_ok)
{
    const char *token[] = {"10", "42", NULL};
    parser_t int_parser = INT_PARSER;

    AND_PARSER(p, &int_parser, &int_parser);

    parser_result_t *r = parse(token, &p);
    ll_t *r_list = r->data;
    cr_assert_neq(r, NULL);
    cr_assert_eq(*(int *)(ll_pop_front(&r_list)), 10);
    cr_assert_eq(*(int *)(ll_pop_front(&r_list)), 42);
    cr_assert_eq(*r->remainer, NULL);
}

Test(Test_parser, parser_paser_and_fail_not_enof1)
{
    const char *token[] = {"10", NULL};
    parser_t int_parser = INT_PARSER;

    AND_PARSER(p, &int_parser, &int_parser);

    parser_result_t *r = parse(token, &p);
    cr_assert_eq(r, NULL);
}

Test(Test_parser, parser_paser_and_fail_not_enof2)
{
    const char *token[] = {NULL};
    parser_t int_parser = INT_PARSER;

    AND_PARSER(p, &int_parser, &int_parser);

    parser_result_t *r = parse(token, &p);
    cr_assert_eq(r, NULL);
}

Test(Test_parser, parser_paser_and_fail_parser1)
{
    const char *token[] = {"toto", "10", NULL};
    parser_t int_parser = INT_PARSER;

    AND_PARSER(p, &int_parser, &int_parser);

    parser_result_t *r = parse(token, &p);
    cr_assert_eq(r, NULL);
}

Test(Test_parser, parser_paser_and_fail_parser2)
{
    const char *token[] = {"10", "toto", NULL};
    parser_t int_parser = INT_PARSER;

    AND_PARSER(p, &int_parser, &int_parser);

    parser_result_t *r = parse(token, &p);
    cr_assert_eq(r, NULL);
}
