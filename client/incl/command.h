/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** command
*/

#ifndef COMMAND_H_
#define COMMAND_H_

#include "client.h"

#define F_NAME {    \
    "/login",   \
    "/logout",  \
    "/users",   \
    "/user",    \
    "/send",    \
    "/messages",    \
    "/subscribe",   \
    "/subscribed",  \
    "/unsubscribe", \
    "/use", \
    "/create",  \
    "/list",    \
    "/info",    \
    NULL    \
};

#define F_FUNC {    \
    &login, \
    &logout,    \
    NULL    \
}

#endif /* !COMMAND_H_ */
