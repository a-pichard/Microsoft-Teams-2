/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019 [WSL: Debian]
** File description:
** read_from_server
*/

#include "client.h"
#include "logging_client.h"
#include <unistd.h>
#include <string.h>

static char *clean(char *data)
{
    if (data)
        data[strlen(data) - 2] = 0;
    return (data);
}

static char *client_recieve(client_t *client)
{
    char buffer[BUFFER_READ_SIZE] = { 0 };
    int ret = 0;

    ret = read(client->fd, buffer, BUFFER_READ_SIZE);
    ASSERT(ret >= 0);
    if (ret == 0) {
        close(client->fd);
        dprintf(1, "The client has been disconnected from the server\n");
        exit(0);
    }
    return (bufferizer(&client->req, buffer, REQ_END));
}

static void not_found_error(char const *recept)
{
    char **data = str_to_wordtab((char *)recept, ' ', false);
    int codes[] = {400, 401, 402, 403, -1};
    int (*f[])(char const *) = {&client_error_unknown_user,
        &client_error_unknown_team, &client_error_unknown_channel,
        &client_error_unknown_thread};
    char uuid_str[37];
    AND_PARSER(error_p, &INT_PARSER, &UUID_PARSER);
    parser_result_t *r = parse((char const * const *)data, &error_p);
    ll_t *err;

    if (!r)
        return destroy_tab(data);
    err = r->data;
    uuid_unparse(err->next->data, uuid_str);
    for (size_t i = 0; codes[i] != -1; i++) {
        if (codes[i] == *(int *)err->data) {
            f[i](uuid_str);
        }
    }
    destroy_tab(data);
}

static bool check_common_error_code(char const *recept)
{
    if (!strncmp(recept, "300", 3)) {
        client_error_unauthorized();
        return (false);
    }
    if (recept[0] == '4') {
        not_found_error(recept);
        return (false);
    }
    if (!strncmp(recept, "600", 3)) {
        client_error_already_exist();
        return (false);
    }
    return (true);
}

void read_from_server(client_t *client, cmd_t *func)
{
    char *recept;

    recept = clean(client_recieve(client));
    if (!recept)
        return;
    if (!strncmp(recept, "\"event\"", 7)) {
        parse_event(recept);
    } else if (*func) {
        if (check_common_error_code((char const *)recept))
            (*func)(client, (char const *)recept);
        *func = NULL;
    }
    free(recept);
}