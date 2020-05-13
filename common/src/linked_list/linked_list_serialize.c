/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** linked_list_serialize
*/

#include <linked_list.h>
#include <common.h>
#include <string.h>

char *ll_serialize(ll_t **list, serialize_fn serializer_fn)
{
    char *str = strdup("[ ");
    char *tmp = NULL;
    char *cereal = NULL;

    ll_foreach(*list, void, e,
        cereal = serializer_fn(e);
        tmp = strcat_alloc3(str, " ", cereal);
        free(cereal);
        free(str);
        str = tmp;
    );
    tmp = strcat_alloc(str, " ]");
    free(str);
    return tmp;
}