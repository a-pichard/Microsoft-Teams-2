/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** main
*/

#include <stdio.h>
#include <string.h>
#include <client.h>
#include <stdlib.h>
#include "common.h"
#include <unistd.h>

client_t *init_client(const char *ip, const char *port_str)
{
    client_t *client = NULL;
    char *end;
    int port = -1;

    port = strtol(port_str, &end, 10);
    if (*end != '\0')
        return NULL;
    client = client_create(ip, port);
    return client;
}

int main(int ac, const char * const * av)
{
    client_t *client = NULL;

    if (ac == 2 && !strcmp("-help", av[1])) {
        helper(av[0], 0);
    } else if (ac == 3) {
        client = init_client(av[1], av[2]);
        printf("You'r welcome bamboula\n");
        client_run(client);
        client_destroy(client);
    } else {
        helper(av[0], 84);
    }
}