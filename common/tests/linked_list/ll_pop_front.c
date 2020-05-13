/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** ll_pop_front
*/

#include <linked_list.h>
#include <criterion/criterion.h>

Test(Test_linked_list, linked_list_pop_front)
{
    ll_t *l = NULL;
    char *data = strdup("toto");
    char *data2 = strdup("toto2");
    char *ret = NULL;

    ll_push_front(&l, data);
    ll_push_front(&l, data2);
    ret = ll_pop_front(&l);
    cr_assert_eq(l->data, data);
    cr_assert_eq(l->next, NULL);
    cr_assert_eq(ret, data2);
    ret = ll_pop_front(&l);
    cr_assert_eq(l, NULL);
    ret = ll_pop_front(&l);
    cr_assert_eq(l, NULL);
    free(data);
    free(data2);
}