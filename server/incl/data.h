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
    char body[MAX_BODY_LENGTH];
    long time;
    uuid_t u_creator;
    uuid_t uuid;
} comment_t;


typedef struct {
    char title[MAX_NAME_LENGTH];
    char body[MAX_BODY_LENGTH];
    ll_t *comments;
    long time;
    uuid_t uuid;
    uuid_t u_creator;
} thread_t;

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    ll_t *threads;
    uuid_t uuid;
} channel_t;

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    uuid_t uuid;
    ll_t *channels;
    ll_t *users_uuid;
} team_t;

#endif /* !DATA_H_ */