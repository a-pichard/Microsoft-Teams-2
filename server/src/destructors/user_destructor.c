/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** user_destructor
*/

#include <stdlib.h>

void user_destructor(void *data)
{
    if (data)
        free(data);
}