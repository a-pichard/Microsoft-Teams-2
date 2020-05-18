/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** send
*/

#include "client.h"
#include "logging_client.h"
#include "common.h"
#include "parser.h"

static void get_user_infos(char **data)
{
    char uuid_str[37];
    
    uuid_unparse((void *)data[1], uuid_str);
    client_error_unknown_user(uuid_str);
}

void send(client_t *client UNUSED, char const * recept)
{
    char **data = str_to_wordtab((char *)recept, ' ', true);

    if (atoi(*data) == 404)
        get_user_infos(data);
    destroy_tab(data);
}