/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** help
*/

#include <stdlib.h>
#include <stdio.h>

void helper(const char *prg, int exit_status)
{
    dprintf(1, "USAGE: %s ip port\n", prg);
    dprintf(1, "\tip is the server ip address on ");
    dprintf(1, "which the server socket listens\n\tport is");
    dprintf(1, " the port number on which the server socket listens\n");
    exit(exit_status);
}