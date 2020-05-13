/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** user
*/

#include "server.h"
#include "parser.h"
#include <uuid/uuid.h>

static char *get_responce_user(user_t *user)
{
    char *str = malloc(sizeof(char) * (strlen(user->name) + 37 + 10));
    char *temp = user_serializer(user);

    strcpy(str, "200 ");
    strcat(str, temp);
    free(temp);
    return str;
}

void user(server_t *server, client_t *client, char const * const *data)
{
    parser_t string_parser = UUID_PARSER;
    parser_result_t *r;
    user_t *user = NULL;
    char *result;

    r = parse(data, &string_parser);
    if (r == NULL) {
        write_q(client, "500 \"Bad argument\"");
        return;
    } else {
        user = get_user_by_uuid(server, (unsigned char *) r->data);
        if (user == NULL) {
            write_q(client, "404 \"user not found\"");
        } else {
            result = get_responce_user(user);
            write_q(client, result);
            free(result);
        }
    }
    parser_result_clean(&string_parser, r);
}
