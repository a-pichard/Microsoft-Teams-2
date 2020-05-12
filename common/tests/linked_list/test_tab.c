/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** test_str_to_wordtab
*/

#include "common.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(Test_tab, str_to_wordtab_success)
{
    char *to_parse = strdup("wesh la zone \"ca dit quoi lo\"");
    char **res = str_to_wordtab(to_parse, ' ', true);

    cr_assert_str_eq(res[0], "wesh");
    cr_assert_str_eq(res[1], "la");
    cr_assert_str_eq(res[2], "zone");
    cr_assert_str_eq(res[3], "\"ca dit quoi lo\"");
    cr_assert_eq(res[4], NULL);
    free(to_parse);
}

Test(Test_tab, str_to_wordtab_err)
{
    char **res = str_to_wordtab(NULL, ' ', true);

    cr_assert_eq(res, NULL);
}

Test(Test_tab, tab_len)
{
    char *to_parse = strdup("wesh la zone \"ca dit quoi lo\"");
    char **res = str_to_wordtab(to_parse, ' ', true);
    int len = get_tab_len((char const * const *)res);

    cr_assert_eq(len, 4);
    len = get_tab_len(NULL);
    cr_assert_eq(len, 0);
}

Test(Test_tab, destroy_tab)
{
    char *to_parse = strdup("wesh la zone \"ca dit quoi lo\"");
    char **res = str_to_wordtab(to_parse, ' ', true);

    cr_redirect_stdout();
    destroy_tab(res);
    destroy_tab(NULL);
    cr_assert_str_eq("no crash", "no crash");
}

Test(Test_tab, print_tab, .init=cr_redirect_stdout)
{
    char *to_parse = strdup("wesh la zone \"ca dit quoi lo\"");
    char **res = str_to_wordtab(to_parse, ' ', true);

    print_tab((char const * const *)res);
    print_tab(NULL);
    cr_assert_stdout_eq_str("wesh\nla\nzone\n\"ca dit quoi lo\"\n");
}