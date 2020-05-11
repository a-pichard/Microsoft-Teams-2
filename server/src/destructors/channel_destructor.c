/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** channel_destructor
*/

#include "server.h"
#include <stdlib.h>

void channel_destructor(void *data)
{
    channel_t *channel = (channel_t *)data;

    if (channel) {
        ll_destroy(&channel->threads, &thread_destructor);
        free(channel);
    }
}