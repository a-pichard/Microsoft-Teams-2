/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** msg_destructor
*/

#include "server.h"
#include <stdlib.h>

void msg_destructor(void *data)
{
    msg_t *msg = (msg_t *)data;

    if (msg) {
        free(msg->msg);
        free(msg);
    }
}