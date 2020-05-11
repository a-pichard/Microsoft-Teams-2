/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** thread_destructor
*/

#include "server.h"
#include <stdlib.h>

void thread_destructor(void *data)
{
    thread_t *thread = (thread_t *)data;

    if (thread) {
        ll_destroy(&thread->comments, &free);
        free(thread);
    }
}