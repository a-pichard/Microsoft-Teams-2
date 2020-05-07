
#include "server.h"
#include <string.h>

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
    ASSERT(res != NULL);
    return (res);
}