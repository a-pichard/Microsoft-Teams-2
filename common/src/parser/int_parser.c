/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** int_parser
*/

#include <stdlib.h>

void *parse_int_function(const char *token)
{
    char *end;
    int *port = malloc(sizeof(int));

    *port = strtol(token, &end, 10);
    if (*end != '\0') {
        free(port);
        return NULL;
    }
    return port;
}