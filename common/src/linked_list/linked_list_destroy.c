/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** linked_list_destroy
*/

#include <linked_list.h>
#include <stdlib.h>

void ll_destroy(ll_t **list, void(*destructor)(void *))
{
    ll_t **start = list;
    ll_t *current = NULL;
    ll_t *it = *list;

    while (it != NULL) {
        current = it;
        it = current->next;
        if (destructor)
            destructor(current->data);
        free(current);
    }
    *start = NULL;
}