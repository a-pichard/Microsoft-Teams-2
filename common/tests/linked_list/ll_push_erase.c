/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** ll_push_erase
*/

#include <linked_list.h>
#include <criterion/criterion.h>

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