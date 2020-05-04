/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** write_q_destructor
*/

#include <stdlib.h>

void client_destructor(void *data)
{
    if (data)
        free(data);
}