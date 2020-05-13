/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** ll_apply
*/

#include <linked_list.h>
#include <criterion/criterion.h>

void add_1(void *a)
{
    int *v = (int *)(a);
    *v = *v + 1;
}

Test(Test_linked_list, linked_list_apply)
{
    ll_t *l = NULL;
    int *ret = NULL;
    int *a = malloc(sizeof(int));
    int *b = malloc(sizeof(int));

    *a = 10;
    *b = 42;
    ll_push_front(&l, a);
    ll_push_front(&l, b);
    ll_apply(&l, add_1);
    ret = ll_pop_front(&l);
    cr_assert_eq(*(int *)(ret), 43);
    ret = ll_pop_front(&l);
    cr_assert_eq(*(int *)(ret), 11);
}