/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** linked_list_destroy
*/

#include <linked_list.h>
#include <stdlib.h>

void ll_destroy(ll_t **list, void(*destructor)(void*))
{
    ll_t *current = *list;

    while (*list != NULL) {
        current = *list;
        list = &current->next;
        destructor(current);
        free(current);
    }
}