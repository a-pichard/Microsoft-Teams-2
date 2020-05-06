/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** test_linked_list_
*/

#include <linked_list.h>
#include <criterion/criterion.h>

Test(Test_linked_list, linked_list_push_back)
{
    ll_t *l = NULL;
    char *data = strdup("toto");

    ll_push_back(&l, data);
    cr_assert_neq(l, NULL);
    cr_assert_eq(l->data, data);
    cr_assert_eq(l->next, NULL);
    free(data);
}
