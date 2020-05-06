/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** help
*/

#include <cmd.h>

void help(server_t *server UNUSED, client_t *client UNUSED, const char *data UNUSED)
{
    write_q(client, "bonjour tu veux du shit");
}