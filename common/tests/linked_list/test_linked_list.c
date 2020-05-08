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

Test(Test_linked_list, linked_list_push_front)
{
    ll_t *l = NULL;
    char *data = strdup("toto");
    char *data2 = strdup("toto2");

    ll_push_front(&l, data);
    cr_assert_neq(l, NULL);
    cr_assert_eq(l->data, data);
    cr_assert_eq(l->next, NULL);
    ll_push_front(&l, data2);
    cr_assert_eq(l->data, data2);
    cr_assert_eq(l->next->next, NULL);
    free(data);
    free(data2);
}

void destructor(void *data)
{
    if (data)
        free(data);
}

Test(Test_linked_list, linked_list_erase)
{
    ll_t *l = NULL;
    char *data = strdup("toto");
    char *data2 = strdup("toto2");

    ll_push_front(&l, data);
    ll_push_front(&l, data2);
    ll_erase(&l, l->next->data, &destructor);
    cr_assert_eq(l->data, data2);
    cr_assert_eq(l->next, NULL);
    free(data2);
}

Test(Test_linked_list, linked_list_destroy)
{
    ll_t *l = NULL;
    char *data = strdup("toto");
    char *data2 = strdup("toto2");

    ll_push_front(&l, data);
    ll_push_front(&l, data2);
    ll_destroy(&l, &destructor);
    cr_assert_eq(l, NULL);
}

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