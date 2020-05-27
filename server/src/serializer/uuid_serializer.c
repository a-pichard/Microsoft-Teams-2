/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** uuid_serializer
*/

#include <uuid/uuid.h>
#include <stdlib.h>

char *uuid_serialize(const void *data)
{
    char *str = malloc(sizeof(char) * 37);
    const unsigned char *uuid = data;

    uuid_unparse(uuid, str);
    return str;
}