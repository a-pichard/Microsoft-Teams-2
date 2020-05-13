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

void load_user(server_t *server, const char * const *data)
{
    parser_t string_parser = STRING_PARSER;
    parser_t uuid_parser = UUID_PARSER;
    parser_t int_parser = INT_PARSER;
    AND_PARSER(user_parser, &uuid_parser, &string_parser, &int_parser);
    TAB_PARSER(users_parser, &user_parser);
    parser_t sep = SEP_PARSER(' ', &users_parser);
    parser_t suroud_parser = SUROUNDE_PARSER('"', &sep);
    parser_result_t *r = parse(data, &suroud_parser);

    if (r == NULL) {
        printf("merde\n");
    } else {
        printf("yes\n");
    }
}

void load_server_from_file(server_t *server, const char *file_name)
{
    FILE *file = fopen(file_name, "r");
    long size;
    char *buffer;
    char **data = NULL;
    // char *data[] = {"\"users\"",
    //     "[",
    //     "\"e58e7786-fad5-45cb-9410-ceaff8aff871 toto 0\"",
    //     "\"1aa5aab3-ce9a-42f7-87db-4628f20ecbb0 armand 0\"",
    //     "]", 
    //     NULL};

    if (file == NULL)
        return;
    // load_user(server, data+1);
    fseek(file, 0, SEEK_END);
    size = ftell(file);
    fseek(file, 0, SEEK_SET);
    buffer = malloc(sizeof(char)*(size+1));
    int r = fread(buffer, 1, size, file);
    buffer[r] = '\0';
    printf("buffer={%s}\n", buffer);
    data = str_to_wordtab(buffer, ' ', true);
    print_tab(data);
    destroy_tab(data);
    // free(buffer);
}