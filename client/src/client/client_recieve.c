/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** client_recieve
*/

#include <client.h>
#include <stdlib.h>
#include <unistd.h>
#include "common.h"

char *client_recieve(client_t *client)
{
    char buffer[BUFFER_READ_SIZE] = { 0 };
    int ret = 0;

    ret = read(client->fd, buffer, BUFFER_READ_SIZE);
    
    ASSERT(ret >= 0);
    return bufferizer(&client->req, buffer);
}