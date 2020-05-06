/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** data
*/

#ifndef DATA_H_
#define DATA_H_

#include <uuid/uuid.h>

#define MAX_NAME_LENGTH 32
#define MAX_DESCRIPTION_LENGTH 255
#define MAX_BODY_LENGTH 512

// Private discussions

typedef struct message_s {
    char text[MAX_BODY_LENGTH];
    uuid_t uid;
    struct message_s *next;
} message_t;

typedef struct discussion_s {
    uuid_t other_uid;
    message_t *messages;
    struct discussion_s *next;
} discussion_t;

typedef struct user_s {
    uuid_t uid;
    char username[MAX_NAME_LENGTH];
    discussion_t *discussions;
} user_t;

// Teams 

typedef struct comment_s {
    char comment[MAX_BODY_LENGTH];
    uuid_t uid;
    struct comment_s *next;
} comment_t;

typedef struct thread_s {
    char description[MAX_DESCRIPTION_LENGTH];
    comment_t *comments;
    uuid_t uid;
    struct thread_s *next;
} thread_t;

typedef struct channel_s {
    char channel_name[MAX_NAME_LENGTH];
    thread_t *threads;
    uuid_t uid;
    struct channel_s *next;
} channel_t;

typedef struct team_s {
    char name[MAX_NAME_LENGTH];
    uuid_t uid;
    channel_t *channels;
    user_t *users;
    struct team_s *next;
} team_t;

#endif /* !DATA_H_ */
