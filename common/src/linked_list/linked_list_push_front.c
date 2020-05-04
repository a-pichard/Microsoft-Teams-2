/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** linked_list_push_front
*/

#include <linked_list.h>

void ll_push_front(ll_t **first, void *data)
{
    ll_t *new = ll_create(data);

    new->next = *first;
    *first = new;
}