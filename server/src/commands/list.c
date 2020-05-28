/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** list
*/

#include "server.h"
#include <string.h>

static char *serial_comment(thread_t *thread, comment_t *comment)
{
    size_t len = strlen(comment->body) + 37 + 37 + 24;
    char *str = malloc(sizeof(char) * (len + 6));
    char time[24];
    char str_uuid[37];

    ASSERT(str != NULL);
    uuid_unparse(thread->uuid, str_uuid);
    strcpy(str, str_uuid);
    strcat(str, " ");
    uuid_unparse(comment->u_creator, str_uuid);
    strcat(str, str_uuid);
    strcat(str, " ");
    sprintf(time, "%ld", comment->time);
    strcat(str, time);
    strcat(str, " \"");
    strcat(str, comment->body);
    strcat(str, "\"");
    return str;
}

static void list_team(client_t *client)
{
    team_t *team = client->use_ptr;

    write_q_responce_objet_list(client, 201, team->channels,
        channel_serializer);
}

static void list_channel(client_t *client)
{
    channel_t *channel = client->use_ptr;

    write_q_responce_objet_list(client, 202, channel->threads,
        thread_serializer);
}

static void list_thread(client_t *client)
{
    thread_t *thread = client->use_ptr;
    char *str = strdup("[ ");
    char *temp_ser = NULL;
    char *temp = NULL;

    ll_foreach(thread->comments, comment_t, comment,
        temp_ser = serial_comment(thread, comment);
        temp = strcat_alloc3(str, " ", temp_ser);
        free(str);
        free(temp_ser);
        str = temp;
    );
    temp = strcat_alloc(str, " ]");
    write_q_responce(client, 203, temp);
    free(temp);
    free(str);
}

void list(server_t *server, client_t *client, char const * const *data)
{
    if (*data != NULL) {
        write_q(client, "500");
        return;
    }
    if (client->state == NONE)
        write_q_responce_objet_list(client, 200, server->teams,
            team_serializer);
    if (client->state == TEAM)
        list_team(client);
    if (client->state == CHANNEL)
        list_channel(client);
    if (client->state == THREAD)
        list_thread(client);
}
