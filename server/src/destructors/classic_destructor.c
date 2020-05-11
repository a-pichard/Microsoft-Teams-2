/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** classic_destructor
*/

#include <stdlib.h>

void classic_destructor(void *data)
{
    if (data)
        free(data);
}