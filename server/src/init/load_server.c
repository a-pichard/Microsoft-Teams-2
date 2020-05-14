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

static char **load_user(server_t *server, const char * const *data)
{
    AND_PARSER(user_parser, &UUID_PARSER, &STRING_PARSER, &INT_PARSER);
    parser_t sep = SEP_PARSER(' ', &user_parser);
    parser_t suroud_parser = SUROUNDE_PARSER('"', &sep);
    TAB_PARSER(users_parser, &suroud_parser);
    const char * const *remain = NULL;
    parser_result_t *r = parse(data, &users_parser);

    if (r != NULL) {
        ll_foreach(r->data, ll_t, l,
            user_t *t = user_reload(
                (const char *)l->next->data,
                (unsigned char *)l->data,
                *(int*)(l->next->next->data));
            ll_push_back(&server->users, t);
        );
    }
    remain = r->remainer;
    parser_result_clean(&users_parser, r);
    return (char **)remain;
}

static char **load_message(server_t *server, const char * const *data)
{
    print_tab(data);
    parser_t suroud_parser = SUROUNDE_PARSER('"', &STRING_PARSER);
    AND_PARSER(message, &UUID_PARSER, &UUID_PARSER, &INT_PARSER, &suroud_parser);
    
    TAB_PARSER(messages_parser, &message);
    AND_PARSER(dm, &UUID_PARSER, &UUID_PARSER, &messages_parser);
    TAB_PARSER(p, &dm);
    
    const char * const *remain = NULL;
    parser_result_t *r = parse(data, &p);
    if (r == NULL) {
        printf("nop");
        return NULL;
    }
    ll_foreach(r->data, ll_t, dm,
        ll_foreach(dm->next->next->data, ll_t, l,
            msg_t *msg = message_reload(
                (unsigned char *)l->data,
                (unsigned char *)l->next->data,
                *(time_t*)(l->next->next->data),
                (char*)(l->next->next->next->data));
            server_add_private_message(server, msg);
        );
    );

    remain = r->remainer;
    parser_result_clean(&p, r);
    return (char **)remain;
}

static void load_data(server_t *server, const char *const *data)
{
    const char * const *current = data;
    if (strcmp(*current, "\"users\""))
        return;
    current = load_user(server, (current+1));
    if (strcmp(*current, "\"dms\""))
        return;
    current = load_message(server, current+1);
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
    dprintf(1, "%s\n", buffer);
    data = str_to_wordtab(buffer, ' ', true);
    for (int i = 0; data[i]; i++) {
        if (!strcmp(data[i], "]\n")) {
            data[i][1] = '\0';
        }
    }
    load_data(server, data);
    destroy_tab(data);
    free(buffer);
    fclose(file);
}