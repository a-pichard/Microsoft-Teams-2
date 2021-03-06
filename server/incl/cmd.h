/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** cmd
*/

#ifndef CMD_H_
#define CMD_H_

#include "server.h"

#define F_NAME {    \
    "/help",    \
    "/login",   \
    "/logout",  \
    "/users",   \
    "/user",    \
    "/send",    \
    "/messages",    \
    "/use", \
    "/create",  \
    "/list",    \
    "/info",    \
    "/subscribe",   \
    "/subscribed",  \
    "/unsubscribe", \
    NULL    \
};

#define F_FUNC {    \
    &help,  \
    &login, \
    &logout,    \
    &users, \
    &user,  \
    &my_send,  \
    &messages,  \
    &use,   \
    &create,    \
    &list,  \
    &info,  \
    &subscribe, \
    &subscribed,    \
    &unsubscribe,   \
    NULL    \
}

#define TIMEOUT_IN_SEC 15

// index of functions pointer
typedef void (*cmd_t)(
    server_t *server,
    client_t *client,
    char const * const * data
);

// utils
void auth(client_t *, user_t *, int);
char *get_path(const char *, const char *, const char *);
char *get_relative_path(const char *, const char *);
bool write_in_fork(int, void *, size_t);
int read_in_fork(int, void *, size_t);
int accept_connection(int);
int open_file(client_t *, char *, int);
char *get_cmd_line(const char *);

// cmds
void help(server_t *server, client_t *client, char const * const *data);
void login(server_t *server, client_t *client, char const * const *data);
void logout(server_t *server, client_t *client, char const * const *data);
void users(server_t *server, client_t *client, char const * const *data);
void user(server_t *server, client_t *client, char const * const *data);
void my_send(server_t *server, client_t *client, char const * const *data);
void messages(server_t *server, client_t *client, char const * const *data);
void use(server_t *server, client_t *client, char const * const *data);
void create(server_t *server, client_t *client, char const * const *data);
void list(server_t *server, client_t *client, char const * const *data);
void info(server_t *server, client_t *client, char const * const *data);
void subscribe(server_t *server, client_t *client, char const * const *data);
void subscribed(server_t *server, client_t *client, char const * const *data);
void unsubscribe(server_t *server, client_t *client, char const * const *data);


#endif /* !CMD_H_ */