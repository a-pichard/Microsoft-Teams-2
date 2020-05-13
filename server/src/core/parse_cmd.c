/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** parse_cmd
*/


#include "server.h"
#include <string.h>

char **parse_cmd(char **pbuf, const char *req)
{
    char **res = NULL;
    char *rqst = bufferizer(pbuf, req);

    if (!rqst)
        return (NULL);
    if (!strtok(rqst, REQ_END)) {
        free(rqst);
        return (NULL);
    }
    res = str_to_wordtab(rqst, ' ', true);
    free(rqst);
    ASSERT(res != NULL);
    return (res);
}