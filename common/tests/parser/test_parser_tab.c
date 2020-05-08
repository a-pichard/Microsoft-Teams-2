/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** test_parser_tab
*/

#include <criterion/criterion.h>
#include "parser.h"

Test(Test_parser, parser_paser_tab_ok)
{
    const char *token[] = {"10", "42", NULL};
    parser_t int_parser = INT_PARSER;

    TAB_PARSER(p, &int_parser);

    parser_result_t *r = parse(token, &p);
    cr_assert_neq(r, NULL);
    ll_t *r_list = r->data;
    cr_assert_eq(*(int*)(ll_pop_front(&r_list)), 10);
    cr_assert_eq(*(int*)(ll_pop_front(&r_list)), 42);
    cr_assert_eq(*r->remainer, NULL);
}

Test(Test_parser, parser_paser_tab_fail1)
{
    const char *token[] = {"a", "42", NULL};
    parser_t int_parser = INT_PARSER;

    TAB_PARSER(p, &int_parser);

    parser_result_t *r = parse(token, &p);
    cr_assert_eq(r, NULL);
}

Test(Test_parser, parser_paser_tab_fail2)
{
    const char *token[] = {"42", "a", NULL};
    parser_t int_parser = INT_PARSER;

    TAB_PARSER(p, &int_parser);

    parser_result_t *r = parse(token, &p);
    cr_assert_eq(r, NULL);
}
