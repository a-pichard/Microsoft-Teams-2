/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** ll_push_erase
*/

#include <linked_list.h>
#include <criterion/criterion.h>

static void destructor(void *data)
{
    if (data)
        free(data);
}

Test(Test_linked_list, linked_list_erase)
{
    ll_t *list = NULL;
    char *data = strdup("toto");
    char *data2 = strdup("toto2");

    ll_push_front(&list, data);
    ll_push_front(&list, data2);
    ll_erase(&list, list->next->data, &destructor);
    cr_assert_eq(list->data, data2);
    cr_assert_eq(list->next, NULL);
    free(data2);
}