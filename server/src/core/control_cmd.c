/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** control_cmd
*/

#include "cmd.h"
#include "server.h"
#include <string.h>
#include <stdlib.h>

static cmd_t index_of(const char **narr, cmd_t *funcs, char *cmd)
{
    int i = 0;
    cmd_t command = NULL;

    while (narr[i] != NULL) {
        if (!strcasecmp(narr[i], cmd)) {
            command = funcs[i];
            break;
        }
        i++;
    }
    free(cmd);
    return (command);
}