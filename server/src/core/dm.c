/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** dm
*/

#include "data.h"

dm_t *dm_create(uuid_t user1, uuid_t user2)
{
    dm_t *dm = malloc(sizeof(dm_t));

    ASSERT(dm != NULL);
    uuid_copy(dm->user1, user1);
    uuid_copy(dm->user2, user2);
    dm->msgs = NULL;
    return dm;
}