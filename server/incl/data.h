/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** data
*/

#ifndef DATA_H_
#define DATA_H_

#include <uuid/uuid.h>
#include "common.h"
#include "linked_list.h"

#define MAX_NAME_LENGTH 32
#define MAX_DESCRIPTION_LENGTH 255
#define MAX_BODY_LENGTH 512

// direct messages

typedef struct {
    time_t time;
    uuid_t from;
    uuid_t to;
    char *msg;
} msg_t;

typedef struct {
    uuid_t user1;
    uuid_t user2;
    ll_t *msgs;
} dm_t;

// teams, channels, threads and comments
typedef struct {
    char body[MAX_BODY_LENGTH + 1];
    long time;
    uuid_t u_creator;
    uuid_t uuid;
} comment_t;

typedef struct {
    char title[MAX_NAME_LENGTH + 1];
    char body[MAX_BODY_LENGTH + 1];
    ll_t *comments;
    long time;
    uuid_t uuid;
    uuid_t u_creator;
} thread_t;

typedef struct {
    char name[MAX_NAME_LENGTH + 1];
    char description[MAX_DESCRIPTION_LENGTH + 1];
    ll_t *threads;
    uuid_t uuid;
    uuid_t u_creator;
} channel_t;

typedef struct {
    char name[MAX_NAME_LENGTH + 1];
    char description[MAX_DESCRIPTION_LENGTH + 1];
    uuid_t uuid;
    ll_t *channels;
    ll_t *users_uuid;
    uuid_t u_creator;
} team_t;

// Dm
void dm_destructor(void *data);
char *dm_serializer(const void *data);
dm_t *dm_create(uuid_t user1, uuid_t user2);

// Msg
char *msg_serializer(const void *data);
msg_t *msg_create(uuid_t from, uuid_t to, const char *content);
msg_t *message_reload(uuid_t from, uuid_t to, time_t time, const char *content);
void msg_destructor(void *data);

// Team
char *team_serializer(const void *team);
void team_destructor(void *data);
char *team_saver(const void *data);

// Thread
void thread_destructor(void *data);
char *thread_serializer(const void *data);

// Channel
void channel_destructor(void *data);
char *channel_serializer(const void *data);


#endif /* !DATA_H_ */