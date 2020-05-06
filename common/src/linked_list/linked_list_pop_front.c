/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** linked_list_pop_front
*/

#include <linked_list.h>
#include <stdlib.h>

void *ll_pop_front(ll_t **list)
{
    ll_t *current = *list;
    void *data = NULL;

    if (current == NULL)
        return NULL;
    *list = current->next;
    data = current->data;
    free(current);
    return data;
}