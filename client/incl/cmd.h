/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** cmd
*/

#ifndef CMD_H_
#define CMD_H_

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

#endif /* !CMD_H_ */
