/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** team_saver
*/

#include "server.h"

static char *thread_saver(const thread_t *data)
{
    char *thread_ser = thread_serializer(data);
    char *comments = ll_serialize(&data->comments, comment_serializer);
    char *r = strcat_alloc3(thread_ser, " ", comments);

    free(thread_ser);
    free(comments);
    return r;
}

static char *channel_saver(const channel_t *data)
{
    char *channel_ser = channel_serializer(data);
    char *threads = ll_serialize(&data->threads, (serialize_fn)thread_saver);
    char *r = strcat_alloc3(channel_ser, " ", threads);

    free(channel_ser);
    free(threads);
    return r;
}

char *team_saver(const void *data)
{
    team_t *team = (team_t *)(data);
    char *ser = team_serializer(data);
    char *channels = ll_serialize(&team->channels, (serialize_fn)channel_saver);
    char *r = strcat_alloc3(ser, " ", channels);

    free(ser);
    free(channels);
    return r;
}