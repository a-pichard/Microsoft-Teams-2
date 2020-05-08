/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** linked_list_apply
*/

#include <linked_list.h>

void ll_apply(ll_t **list, void(*fn)(void *))
{
    ll_t *current = *list;

    while (current) {
        fn(current->data);
        current = current->next;
    }
}