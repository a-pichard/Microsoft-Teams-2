/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** test_uuid_parser
*/


#include <criterion/criterion.h>
#include "parser.h"
#include <uuid/uuid.h>

Test(Test_parser, parser_uuid_ok)
{
    char str[100] = { 0 };
    uuid_t uuid;
    uuid_generate(uuid);
    uuid_unparse(uuid, str);

    const char *token[] = {str, NULL};
    parser_t p = UUID_PARSER;
    parser_result_t *r = parse(token, &p);

    cr_assert_neq(r, NULL);
    cr_assert_eq(uuid_compare((unsigned char *)(r->data), uuid), 0);
    cr_assert_eq(*r->remainer, NULL);
}

Test(Test_parser, parser_uuid_fail)
{
    char *str = "toto";
    const char *token[] = {"10", str, NULL};
    parser_t p = UUID_PARSER;
    parser_result_t *r = parse(token, &p);

    cr_assert_eq(r, NULL);
}
