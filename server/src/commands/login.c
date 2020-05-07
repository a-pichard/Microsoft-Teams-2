/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** login
*/

#include "cmd.h"

void login(server_t *server UNUSED, client_t *client, char **data UNUSED)
{
    write_q(client, "200 login success");
}