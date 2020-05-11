/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** dm_destructor
*/

#include "server.h"
#include <stdlib.h>

void dm_destructor(void *data)
{
    dm_t *dm = (dm_t *)data;

    if (dm) {
        ll_destroy(&dm->msgs, &msg_destructor);
        free(dm);
    }
}