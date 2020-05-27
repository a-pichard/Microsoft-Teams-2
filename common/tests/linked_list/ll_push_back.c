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
    ll_t *list = NULL;
    char *data = strdup("toto");
    char *data2 = strdup("toto2");

    ll_push_back(&list, data);
    cr_assert_neq(list, NULL);
    cr_assert_eq(list->data, data);
    cr_assert_eq(list->next, NULL);
    ll_push_back(&list, data2);
    cr_assert_eq(list->next->data, data2);
    cr_assert_eq(list->next->next, NULL);
    free(data);
    free(data2);
}