/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** test_is_str_number
*/

#include "common.h"
#include <criterion/criterion.h>

Test(Test_is_str_number, is_str_number_success)
{
    bool ret = is_str_digit("1234");

    cr_assert_eq(ret, true);
}

Test(Test_is_str_number, is_str_number_fail)
{
    bool ret = is_str_digit("mdrxd");

    cr_assert_eq(ret, false);
}