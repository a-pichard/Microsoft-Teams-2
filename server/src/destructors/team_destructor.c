/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** team_destructor
*/

#include "server.h"
#include <stdlib.h>

void team_destructor(void *data)
{
    team_t *team = (team_t *)data;

    if (team) {
        ll_destroy(&team->channels, &thread_destructor);
        free(team);
    }
}