/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** linked_list_create
*/

#include <linked_list.h>
#include <stdlib.h>

ll_t *ll_create(void *data)
{
    ll_t *list = calloc(1, sizeof(ll_t));

    list->data = data;
    return list;
}
