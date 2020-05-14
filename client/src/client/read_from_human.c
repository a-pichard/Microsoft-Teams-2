/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019 [WSL: Debian]
** File description:
** read_from_human
*/

#include "client.h"
#include "command.h"
#include "string.h"
#include <unistd.h>

cmd_t check_cmd(char **data, const char **command_string)
{
    int i;
    void *funcs[] = F_FUNC;

    for (i = 0; command_string[i]; i++)
        if (strcmp(command_string[i], data[0]) == 0)
            return (funcs[i]);
    return NULL;
}

char **clean(char **data)
{
    int i = 0;
    for (; data[i]; i++);
    if (i == 0)
        return NULL;
    data[i - 1][strlen(data[i - 1]) - 1] = 0;
    return (data);
}

cmd_t read_from_human(client_t *client)
{
    char buff[512] = { 0 };
    char **data;
    const char *command_string[] = F_NAME;
    cmd_t func;
    int r = read(0, buff, 512);

    ASSERT(r >= 0);
    buff[r] = '\0';
    data = clean(str_to_wordtab(buff, ' ', true));
    if ((func = check_cmd(data, command_string)))
        client_send(client, buff);
    destroy_tab(data);
    return func;
}