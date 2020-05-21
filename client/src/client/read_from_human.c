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

    if (!data || !data[0])
        return NULL;
    for (i = 0; command_string[i]; i++)
        if (strcmp(command_string[i], data[0]) == 0)
            return (funcs[i]);
    return NULL;
}

static char *get_client_request(client_t *client)
{
    char *rbuff = NULL;
    size_t n = 0;
    int r = getline(&rbuff, &n, stdin);

    if (r == -1) {
        client_destroy(client);
        free(rbuff);
        exit(0);
    }
    rbuff[strlen(rbuff) - 1] = '\0';
    return rbuff;
}

cmd_t read_from_human(client_t *client)
{
    char *req;
    char **data;
    const char *command_string[] = F_NAME;
    cmd_t func;

    req = get_client_request(client);
    data = str_to_wordtab(req, ' ', true);
    if ((func = check_cmd(data, command_string)))
        client_send(client, req);
    free(req);
    destroy_tab(data);
    return func;
}