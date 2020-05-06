/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** linked_list_push_back
*/

#include <linked_list.h>
#include <stdlib.h>

void ll_push_back(ll_t **first, void *data)
{
    ll_t *new = ll_create(data);
    ll_t **current = first;

    while (*current)
        current = &(*current)->next;
    *current = new;
}