/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** linked_list_erase
*/

#include <linked_list.h>
#include <stdlib.h>

void ll_erase(ll_t **list, void *data, void(*destructor)(void*))
{
    ll_t **current = list;
    ll_t *tmp = NULL;

    while ((*current) != NULL) {
        if ((*current)->data == data) {
            tmp = *current;
            *current = (*current)->next;
            destructor(tmp->data);
            free(tmp);
            break;
        }
        current = &(*current)->next;
    }
}