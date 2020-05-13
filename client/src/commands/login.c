/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** login
*/

#include "client.h"
#include <logging_client.h>

void login(client_t *client, char const * recept)
{
    //TODO NEED TO SEND GOOD DATA (ie user_uuid username)
    client_event_loggedin(recept, recept);
}
