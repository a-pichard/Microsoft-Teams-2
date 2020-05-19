/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** list
*/

#include "server.h"

static void list_none(server_t *server, client_t *client)
{
    write_q_responce_objet_list(client, 200, server->teams, team_serializer);
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
    // thread_t *thread = client->use_ptr;

    write_q_responce(client, 789546546, "not implemented");
    // write_q_responce_objet_list(client, 202, thread->comments, comment);
}

void list(server_t *server, client_t *client, char const * const *data)
{
    if (*data != NULL) {
        write_q(client, "300");
        return;
    }
    if (client->state == NONE) {
        list_none(server, client);
    } else if (client->state == TEAM) {
        list_team(client);
    } else if (client->state == CHANNEL) {
        list_channel(client);
    } else if (client->state == THREAD) {
        list_thread(client);
    }
}
