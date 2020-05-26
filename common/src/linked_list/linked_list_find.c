/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** linked_list_find
*/

#include "linked_list.h"
#include <stdbool.h>

void *ll_find(ll_t **list, int (*f)(const void *, const void *),
    const void *element)
{
    if (*list == NULL)
        return NULL;
    ll_foreach(*list, void, e,
        if (!f(element, e))
            return e;
    );
    return NULL;
}