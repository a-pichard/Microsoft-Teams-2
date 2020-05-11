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
    char name[DEFAULT_NAME_LENGTH];
} user_t;

typedef struct {
    int fd;
    char *username;
    char *req;
    ll_t *write_q;
} client_t;

typedef struct {
    int server_fd;
    int port;
    ll_t *users;
    ll_t *clients;
} server_t;

// Init
void input_error_handling(int, char **);
void init_server(server_t *, int port);
server_t *server_address(server_t *server);
int init_main_server_socket(int port);
void init_users(server_t *);
void destroy_server(void);

//helper
void helper(const char *prg_name, int exit_status);

//main function
void run_server(server_t *);

// Server
void handle_client(server_t *server, client_t *client);
char **parse_cmd(char **buffer, const char *req);

// write queue
void write_q(client_t *client, const char *msg);
void send_message(server_t *server, client_t *client);

// destructors
void classic_destructor(void *data);
void client_destructor(void *data);
void write_q_destructor(void *data);
void thread_destructor(void *data);
void channel_destructor(void *data);
void dm_destructor(void *data);
void msg_destructor(void *data);

#endif /* !SERVER_H_ */