/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** logout
*/

#include "cmd.h"

void logout(server_t *server UNUSED, client_t *client, char **data UNUSED)
{
    write_q(client, "200 \"logged out\"");
}