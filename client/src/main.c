/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** main
*/

#include <stdio.h>
#include <string.h>
#include "client.h"
#include <signal.h>

static void sig_handler(int sig UNUSED)
{
    client_t *client = client_save(NULL);

    if (client) {
        client_destroy(client);
    }
    exit(0);
}

int main(int ac, const char * const * av)
{
    client_t *client = NULL;

    if (ac == 2 && !strcmp("-help", av[1])) {
        helper(av[0], 0);
    } else if (ac == 3) {
        client = init_client(av[1], av[2]);
        if (client == NULL)
            helper(av[0], 84);
        signal(SIGINT, &sig_handler);
        client_run(client);
        client_destroy(client);
    } else {
        helper(av[0], 84);
    }
}