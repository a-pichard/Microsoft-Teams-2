/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** parse_cmd
*/

#include "common.h"
#include <string.h>
#include <stdlib.h>

static char *check_strdup(const char *s)
{
    char *res = strdup(s);

    ASSERT(res != NULL);
    return (res);
}

char *bufferizer(char **pbuf, const char *req)
{
    char *tmp;

    if (strstr(req, REQ_END) != NULL) {
        if (*pbuf == NULL) {
            return (check_strdup(req));
        } else {
            tmp = strcat_alloc(*pbuf, req);
            free(*pbuf);
            *pbuf = NULL;
            return (tmp);
        }
    } else {
        if (*pbuf == NULL) {
            *pbuf = check_strdup(req);
        } else {
            tmp = strcat_alloc(*pbuf, req);
            free(*pbuf);
            *pbuf = tmp;
        }
        return (NULL);
    }
}