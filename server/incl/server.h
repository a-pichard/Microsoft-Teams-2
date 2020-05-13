/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** server
*/

#ifndef SERVER_H_
#define SERVER_H_

#define MAX_CLIENTS_QUEUE 5

#include <stdbool.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <linked_list.h>
#include <common.h>
#include "data.h"

#define DEFAULT_NAME_LENGTH 32
#define DEFAULT_DESCRIPTION_LENGTH 255
#define DEFAULT_BODY_LENGTH 512

#ifdef DEBUG
#define LOG(...) fprintf(stdout, "LOG:");  \
fprintf(stdout, __VA_ARGS__);
#else
#define LOG(...)
#endif

typedef struct {
    uuid_t uuid;
    char name[DEFAULT_NAME_LENGTH];
    int status;
} user_t;

typedef struct {
    int fd;
    char *req;
    ll_t *write_q;
    user_t *user;
} client_t;

typedef struct {
    int server_fd;
    int port;
    ll_t *users;
    ll_t *clients;
    ll_t *teams;
    ll_t *dms;
} server_t;

// Init
void input_error_handling(int, char **);
void init_server(server_t *, int port);
server_t *server_address(server_t *server);
int init_main_server_socket(int port);
void destroy_server(void);

//helper
void helper(const char *prg_name, int exit_status);

//main function
void run_server(server_t *);

// Server
void handle_client(server_t *server, client_t *client);
char **parse_cmd(char **buffer, const char *req);
void load_server_from_file(server_t *server, const char *file_name);

//User
user_t *user_create(const char *name);
user_t *user_reload(const char *name, uuid_t uuid, int status);
char *user_serialize(const user_t *user);

user_t *get_user_by_name(server_t *server, const char *username);
user_t *get_user_by_uuid(server_t *server, uuid_t uuid);
user_t *server_add_user_with_name(server_t *server, const char *username);

//Team
char *team_serializer(const void *team);

// write queue
void write_q(client_t *client, const char *msg);
void send_message(server_t *server, client_t *client);

// destructors
void client_destructor(void *data);
void write_q_destructor(void *data);
void thread_destructor(void *data);
void channel_destructor(void *data);
void team_destructor(void *data);
void dm_destructor(void *data);
void msg_destructor(void *data);

#endif /* !SERVER_H_ */