/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** comment
*/

#include "data.h"
#include "server.h"
#include <string.h>
#include "logging_server.h"

static team_t *get_team(server_t *server, thread_t *thread)
{
    ll_foreach(server->teams, team_t, team,
        ll_foreach(team->channels, channel_t, channel,
            ll_foreach(channel->threads, thread_t, t,
                if (t == thread) {
                    return team;
                }
            );
        );
    );
    return NULL;
}

static void comment_create_notify(thread_t *thread, comment_t *comment,
    user_t *user)
{
    server_t *server = server_address(NULL);
    team_t *t = get_team(server, thread);
    char *ser = comment_serializer(comment);
    char *tmp = calloc(3*37, sizeof(char));
    char *r;
    char uuid_str_team[37];
    char uuid_str_thread[37];

    uuid_unparse(t->uuid, uuid_str_team);
    uuid_unparse(thread->uuid, uuid_str_thread);
    sprintf(tmp, "%s %s %s", uuid_str_team, uuid_str_thread, ser);
    r = strcat_alloc("\"event\" \"message\" \"thread\" ", tmp);
    server_team_notify_users(server_address(NULL), t, r, user->uuid);
    free(r);
    free(ser);
    free(tmp);
}

comment_t *comment_create(thread_t *thread, user_t *creator, const char *body)
{
    comment_t *comment = malloc(sizeof(comment_t));
    char id_thread[37];
    char id_user[37];

    strcpy(comment->body, body);
    comment->time = time(NULL);
    uuid_copy(comment->u_creator, creator->uuid);
    uuid_generate(comment->uuid);
    uuid_unparse(thread->uuid, id_thread);
    uuid_unparse(creator->uuid, id_user);
    comment_create_notify(thread, comment, creator);
    server_event_thread_new_message(id_thread, id_user, body);
    thread_add_comment(thread, comment);
    return comment;
}

comment_t *comment_reload(user_t *creator, const char *body)
{
    comment_t *comment = malloc(sizeof(comment_t));

    strcpy(comment->body, body);
    comment->time = time(NULL);
    uuid_copy(comment->u_creator, creator->uuid);
    uuid_generate(comment->uuid);
    return comment;
}