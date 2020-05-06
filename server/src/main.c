/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** main
*/

#include "server.h"
#include <stdlib.h>
#include <signal.h>
#include <common.h>

static void sig_handler(int sig UNUSED)
{
    destroy_server();
    exit(0);
}

int main(int ac, char **av)
{
    server_t serv = { 0 };

    signal(SIGINT, &sig_handler);
    if (ac != 2 || !is_str_digit(av[1]))
        helper(av[0], 84);
    init_server(&serv, atoi(av[1]));
    run_server(&serv);
    return (0);
}