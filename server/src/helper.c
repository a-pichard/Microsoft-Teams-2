/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** helper
*/

#include <stdio.h>
#include <stdlib.h>

void helper(const char *prg_name, int exit_status)
{
    dprintf(1, "USAGE: %s port\n\n\tport is the port number", prg_name);
    dprintf(1, " on which the server socket listens.\n");
    exit(exit_status);
}