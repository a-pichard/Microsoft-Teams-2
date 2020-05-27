/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** ll_len
*/

#include <linked_list.h>
#include <criterion/criterion.h>

Test(Test_linked_list, linked_list_len)
{
    ll_t *list = NULL;

    cr_assert_eq(0, ll_len(&list));
    ll_push_back(&list, NULL);
    cr_assert_eq(1, ll_len(&list));
    ll_push_back(&list, NULL);
    cr_assert_eq(2, ll_len(&list));
}