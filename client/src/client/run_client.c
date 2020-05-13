/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** run_client
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "command.h"
#include <sys/select.h>


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
    data[i-1][strlen(data[i-1]) - 1] = 0;
    return (data);
}

cmd_t read_command(client_t *client)
{
    char buff[512] = { 0 };
    char **data;
    const char *command_string[] = F_NAME;
    cmd_t func;

    read(0, buff, 512);
    data = clean(str_to_wordtab(buff, ' ', true));
    if ((func = check_cmd(data, command_string)))
        client_send(client, buff);
    destroy_tab(data);
    return func;
}

void handle_reception(client_t *client, cmd_t func)
{
    char *recept;

    recept = client_recieve(client);
    if (func) {
        (func)(client, (char const *)recept);
        func = NULL;
    }
    //TODO EVENT
    // else {

    // }
    while ((recept = bufferizer(&client->req, "")) != NULL) {
        printf("recept = [%s]\n", recept);
        if (func) {
            (*func)(client, (char const *)recept);
            func = NULL;
        }
        free(recept);
    }
}

void client_run(client_t *client UNUSED)
{
    fd_set rset;
    cmd_t func = NULL;
    // fd_set wset;

    while (true) {
        // FD_ZERO(&wset);
        FD_ZERO(&rset);
        FD_SET(0, &rset);
        FD_SET(client->fd, &rset);
        // FD_SET(client->fd, &wset);
        select(client->fd+1, &rset, NULL, NULL, NULL);
        if (FD_ISSET(0, &rset)) {
            func = read_command(client);
        } else if (FD_ISSET(client->fd, &rset)) {
            handle_reception(client, func);
            func = NULL;
        }
    }
}