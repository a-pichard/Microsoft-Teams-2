/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** uuid_parser
*/

#include <uuid/uuid.h>
#include <stdlib.h>

void *parse_uuid_function(const char *token)
{
    void *uuid = malloc(sizeof(char)*16);
    int r = uuid_parse(token, uuid);

    if (r == -1) {
        free(uuid);
        return NULL;
    } else {
        return uuid;
    }
}
