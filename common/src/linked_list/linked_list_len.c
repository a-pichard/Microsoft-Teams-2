/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** linked_list_len
*/

#include <linked_list.h>
#include <stdlib.h>

size_t ll_len(ll_t **list)
{
    ll_t *current = *list;
    size_t i = 0;

    while (current != NULL) {
        i++;
        current = current->next;
    }
    return i;
}