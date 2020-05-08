/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** test_string_parser
*/

#include <criterion/criterion.h>
#include "parser.h"

Test(Test_parser, parser_string_ok)
{
    char *str = "toto";
    const char *token[] = {"10", str, NULL};
    parser_t p = STRING_PARSER;
    parser_result_t *r = parse(token, &p);

    cr_assert_neq(r, NULL);
    cr_assert_str_eq((char*)(r->data), "10");
    cr_assert_eq(*r->remainer, str);
}
