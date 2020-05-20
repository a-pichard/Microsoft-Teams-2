/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** load_server
*/

#include <sys/file.h>
#include <fcntl.h>
#include "server.h"
#include "common.h"
#include "parser.h"

static void load_data(server_t *server, const char *const *data)
{
    const char * const *current = data;
    if (strcmp(*current, "users"))
        return;
    current = load_user(server, (current+1));
    if (strcmp(*current, "dms"))
        return;
    current = load_message(server, current+1);
    if (strcmp(*current, "teams"))
        return;
    current = load_teams(server, current+1);
}

static char **read_file(FILE *file, long size)
{
    char *buffer = malloc(sizeof(char) * (size + 1));
    char **data = NULL;

    int r = fread(buffer, 1, size, file);
    buffer[r] = '\0';
    data = str_to_wordtab(buffer, ' ', true);
    for (int i = 0; data[i]; i++) {
        if (!strcmp(data[i], "]\n")) {
            data[i][1] = '\0';
        }
    }
    free(buffer);
    return data;
}

void load_server_from_file(server_t *server, const char *file_name)
{
    FILE *file = fopen(file_name, "r");
    long size;
    char **data;

    if (file == NULL)
        return;
    fseek(file, 0, SEEK_END);
    size = ftell(file);
    fseek(file, 0, SEEK_SET);
    data = read_file(file, size);
    load_data(server, (const char * const *)data);
    destroy_tab(data);
    fclose(file);
}