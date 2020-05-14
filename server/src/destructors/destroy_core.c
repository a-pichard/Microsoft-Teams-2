/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** destroy
*/

#include "server.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

void server_write(const char *users, const char *teams, const char *dm)
{
    int file = open("server.txt", O_CREAT | O_TRUNC | O_WRONLY, 0644);

    ASSERT(file != -1);
    write(file, "\"users\" ", 8);
    write(file, users, strlen(users));
    write(file, "\n\"dms\" ", 7);
    write(file, dm, strlen(dm));
    write(file, "\n\"teams\" ", 9);
    write(file, teams, strlen(teams));
    close(file);
}

void destroy_server(void)
{
    server_t *server = server_address(NULL);
    char *str_users = NULL;
    char *str_teams = NULL;
    char *str_dms = NULL;

    ll_destroy(&server->clients, &client_destructor);
    str_users = ll_serialize(&server->users, (serialize_fn)user_serializer);
    ll_destroy(&server->users, &free);
    str_teams = ll_serialize(&server->teams, (serialize_fn)team_serializer);
    ll_destroy(&server->teams, &team_destructor);
    str_dms = ll_serialize(&server->dms, dm_serializer);
    server_write(str_users, str_teams, str_dms);
    free(str_users);
    free(str_teams);
    free(str_dms);
}