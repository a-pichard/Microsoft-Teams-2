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

typedef enum use_state {
    NONE,
    TEAM,
    CHANNEL,
    THREAD,
} use_state_t;

typedef struct {
    use_state_t state;
    void *use_ptr;
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
void load_server_from_file(server_t *server, const char *file_name);
const char * const *load_message(server_t *server, const char * const *data);
const char * const *load_user(server_t *server, const char * const *data);

//helper
void helper(const char *prg_name, int exit_status);

//main function
void run_server(server_t *);

// Server
void handle_client(server_t *server, client_t *client);
char **parse_cmd(char **buffer, const char *req);

//User
user_t *user_create(const char *name);
user_t *user_reload(const char *name, uuid_t uuid, int status);
char *user_serializer(const void *user);

user_t *get_user_by_name(server_t *server, const char *username);
user_t *get_user_by_uuid(server_t *server, uuid_t uuid);
user_t *server_add_user_with_name(server_t *server, const char *username);

//teams
team_t *server_get_teams_by_uuid(server_t *server, uuid_t uuid);
team_t *server_get_teams_by_name(server_t *server, char *name);
void server_add_team(server_t *server, team_t *team);
team_t *team_create(user_t *user, const char *name, const char *description);

channel_t *team_get_channel_by_uuid(team_t *team, uuid_t uuid);
channel_t *team_get_channel_by_name(team_t *team, const char *name);
void team_add_channel(team_t *team, channel_t *channel);

//channel
channel_t *channel_create(const char *name, const char *description);
thread_t *channel_get_thread_by_uuid(channel_t *channel, uuid_t uuid);
thread_t *channel_get_thread_by_name(channel_t *channel, const char *name);

void channel_add_thread(channel_t *channel, thread_t *thread);


//thread
thread_t *thread_create(user_t *creator, const char *name, const char *body);
void thread_add_comment(thread_t *thread, comment_t *comment);


//comment
comment_t *comment_create(user_t *creator, const char *body);


// write queue
void write_q(client_t *client, const char *msg);
void write_q_responce(client_t *client, int code, const char *msg);
void write_q_responce_objet(client_t *client, int code, void *objet,
    serialize_fn serilizer);
void write_q_responce_objet_list(client_t *client, int code, ll_t *objets,
    serialize_fn serilizer);
void send_message(server_t *server, client_t *client);

// destructors
void client_destructor(void *data);
void write_q_destructor(void *data);

void server_add_private_message(server_t *server, msg_t *message);
dm_t *get_dms(server_t *server, uuid_t user1, uuid_t user2);

#endif /* !SERVER_H_ */