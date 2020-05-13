/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** ll_push_back
*/

#include <linked_list.h>
#include <criterion/criterion.h>

Test(Test_linked_list, linked_list_push_back)
{
    ll_t *l = NULL;
    char *data = strdup("toto");
    char *data2 = strdup("toto2");

    ll_push_back(&l, data);
    cr_assert_neq(l, NULL);
    cr_assert_eq(l->data, data);
    cr_assert_eq(l->next, NULL);
    ll_push_back(&l, data2);
    cr_assert_eq(l->next->data, data2);
    cr_assert_eq(l->next->next, NULL);
    free(data);
    free(data2);
}