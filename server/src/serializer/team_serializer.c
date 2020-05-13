/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** team_serializer
*/

#include "server.h"
#include <stdlib.h>
#include <string.h>

char *team_serializer(const void *data)
{
    team_t *team = (team_t *)data;
    size_t len = strlen(team->name) + strlen(team->description) + 37;
    char *str = malloc(sizeof(char) * (len + 5));
    char str_uuid[37];

    ASSERT(str != NULL);
    uuid_unparse(team->uuid, str_uuid);
    strcpy(str, "\"");
    strcat(str, str_uuid);
    strcat(str, " ");
    strcat(str, team->name);
    strcat(str, " ");
    strcat(str, team->description);
    strcat(str, "\"");
    return str;
}