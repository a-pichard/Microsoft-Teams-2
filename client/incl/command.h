/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** command
*/

#ifndef COMMAND_H_
#define COMMAND_H_

#include "client.h"

#define DEFAULT_NAME_LENGTH 32
#define DEFAULT_DESCRIPTION_LENGTH 255
#define DEFAULT_BODY_LENGTH 512

#define F_NAME {    \
    "/help",    \
    "/create",  \
    "/info",    \
    "/list",    \
    "/login",   \
    "/logout",  \
    "/messages",    \
    "/send",    \
    "/subscribe",   \
    "/subscribed",  \
    "/unsubscribe", \
    "/use", \
    "/user",    \
    "/users",   \
    NULL    \
};

#define F_FUNC {    \
    &help,  \
    &create, \
    &info,  \
    &list,  \
    &login, \
    &logout,    \
    &messages,  \
    &send,  \
    &subscribe, \
    &subscribed,    \
    &unsubscribe,   \
    &use,   \
    &user,  \
    &users, \
    NULL    \
}

void help(client_t *client, char const * recept);
void create(client_t *client, char const * recept);
void info(client_t *client, char const * recept);
void list(client_t *client, char const * recept);
void login(client_t *client, char const * recept);
void logout(client_t *client, char const * recept);
void messages(client_t *client, char const * recept);
void send(client_t *client, char const * recept);
void subscribe(client_t *client, char const * recept);
void subscribed(client_t *client, char const * recept);
void unsubscribe(client_t *client, char const * recept);
void use(client_t *client, char const * recept);
void user(client_t *client, char const * recept);
void users(client_t *client, char const * recept);

#endif /* !COMMAND_H_ */
