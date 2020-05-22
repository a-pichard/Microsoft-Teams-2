/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** event
*/

#ifndef EVENT_H_
#define EVENT_H_

#define EVENT_NAME {    \
    "login",    \
    "logout",   \
    "message",  \
    "create",   \
    NULL    \
};

#define EVENT_FUNC {    \
    &login_e,   \
    &logout_e,  \
    &message_e, \
    &create_e,  \
    NULL    \
}

void login_e(const char * const *recept);
void logout_e(const char * const *recept);
void message_e(const char * const *recept);
void create_e(const char * const *recept);

typedef void (*event_t)(const char * const *remainer);

#endif /* !EVENT_H_ */