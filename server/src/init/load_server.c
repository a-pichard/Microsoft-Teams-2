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

char **load_user(server_t *server, const char * const *data)
{
    AND_PARSER(user_parser, &UUID_PARSER, &STRING_PARSER, &INT_PARSER);
    parser_t sep = SEP_PARSER(' ', &user_parser);
    parser_t suroud_parser = SUROUNDE_PARSER('"', &sep);
    TAB_PARSER(users_parser, &suroud_parser);
    char *remain = NULL;
    parser_result_t *r = parse(data, &users_parser);

    if (r != NULL) {
        ll_foreach(r->data, ll_t, l,
            user_t *t = user_reload(l->next->data, l->data, l->next->next->data);
            ll_push_back(&server->users, t);
        );
    }
    remain = r->remainer;
    parser_result_clean(&users_parser, r);
    return remain;
}

void load_server_from_file(server_t *server, const char *file_name)
{
    FILE *file = fopen(file_name, "r");
    long size;
    char *buffer;
    char **data = NULL;

    if (file == NULL)
        return;
    fseek(file, 0, SEEK_END);
    size = ftell(file);
    fseek(file, 0, SEEK_SET);
    buffer = malloc(sizeof(char)*(size+1));
    int r = fread(buffer, 1, size, file);
    buffer[r] = '\0';
    printf("buffer={%s}\n", buffer);
    data = str_to_wordtab(buffer, ' ', true);
    for (int i = 0; data[i]; i++) {
        if (!strcmp(data[i], "]\n")) {
            data[i][1] = '\0';
        }
    }
    print_tab(data);
    load_user(server, data+1);
    destroy_tab(data);
    free(buffer);
    fclose(file);
}