/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** test_bufferization
*/

#include "common.h"
#include <criterion/criterion.h>

Test(Test_bufferization, bufferization_case_1)
{
    char *buffer = NULL;
    char *req = strdup("mdr\r\n");
    char *res = bufferizer(&buffer, req, REQ_END);

    cr_assert_str_eq(req, res);
    cr_assert_eq(buffer, NULL);
}

Test(Test_bufferization, bufferization_case_2)
{
    char *buffer = strdup("xd");
    char *req = strdup("mdr\r\n");
    char *res = bufferizer(&buffer, req, REQ_END);

    cr_assert_neq(res, NULL);
    cr_assert_eq(buffer, NULL);
}

Test(Test_bufferization, bufferization_case_3)
{
    char *buffer = NULL;
    char *req = strdup("mdr");
    char *res = bufferizer(&buffer, req, REQ_END);

    cr_assert_str_eq(buffer, req);
    cr_assert_eq(res, NULL);
}

Test(Test_bufferization, bufferization_case_4)
{
    char *buffer = strdup("xd");
    char *req = strdup("mdr");
    char *res = bufferizer(&buffer, req, REQ_END);

    cr_assert_neq(buffer, NULL);
    cr_assert_eq(res, NULL);
}