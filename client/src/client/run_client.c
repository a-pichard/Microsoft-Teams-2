/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** run_client
*/

#include <stdio.h>
#include <string.h>
#include <client.h>
#include <stdlib.h>
#include <unistd.h>
#include "cmd.h"


void check_cmd(char **data, const char **command_string)
{
    int i;

    for (i = 0; command_string[i]; i++)
        if (strcmp(command_string[i], data[0]) == 0)
            printf("ok [%s]\n", command_string[i]);
}

char **clean(char **data)
{
    int i = 0;

    for (; data[i]; i++);
    if (i == 0)
        return NULL;
    data[i-1][strlen(data[i-1]) - 1] = 0;
    return (data);
}

void client_run(client_t *client UNUSED)
{
    char buff[512] = { 0 };
    char **data;
    const char *command_string[] = F_NAME;

    while (true) {
        read(0, buff, 512);
        data = clean(str_to_wordtab(buff, " ", true));
        check_cmd(data, command_string);
        destroy_tab(data);
    }
}