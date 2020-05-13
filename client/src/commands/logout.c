/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** logout
*/

#include "client.h"
#include <logging_client.h>

void logout(client_t *client, char const * recept)
{
    //TODO NEED GOOD DATA (ie user_uuid username)
    client_event_loggedout(recept, recept);
}
