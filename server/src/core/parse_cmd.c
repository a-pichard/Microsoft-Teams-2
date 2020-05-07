/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** parse_cmd
*/

#include "server.h"
#include <string.h>
#include <stdlib.h>

static char *check_strdup(const char *s)
{
    char *res = strdup(s);

    raise_err(res != NULL, "strdup() ");
    return (res);
}

static char *bufferizer(char **pbuf, const char *req)
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

char **parse_cmd(char **pbuf, const char *req)
{
    char **res = NULL;
    char *rqst = bufferizer(pbuf, req);

    if (!rqst)
        return (NULL);
    if (!strtok(rqst, REQ_END))
        return (NULL);
    res = str_to_wordtab(rqst, " ");
    free(rqst);
    raise_err(res != NULL, "str_to_wordtab() ");
    return (res);
}