/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** dm_serializer
*/

#include "data.h"

char *dm_serializer(const void *data)
{
    dm_t *dms = (dm_t *)data;
    char uuid_str1[37];
    char uuid_str2[37];
    char *str = NULL;
    char *tmp;
    char *msgs = ll_serialize(&dms->msgs, msg_serializer);

    uuid_unparse(dms->user1, uuid_str1);
    uuid_unparse(dms->user2, uuid_str2);
    str = strcat_alloc3(uuid_str1, " ", uuid_str2);
    tmp = strcat_alloc3(str, " ", msgs);
    free(msgs);
    free(str);
    return tmp;
}