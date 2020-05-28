/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** team_saver
*/

#include "server.h"

static char *channel_serializer_full(const channel_t *c)
{
    char *str = NULL;
    char str_uuid[37];
    char uuid_creator[37];
    int size = 0;
    char *patern = "%s %s \"%s\" \"%s\"";

    uuid_unparse(c->uuid, str_uuid);
    uuid_unparse(c->u_creator, uuid_creator);
    size = snprintf(NULL, 0, patern, str_uuid, uuid_creator, c->name,
        c->description);
    if (size == -1)
        return (NULL);
    str = malloc(sizeof(char) * (size + 1));
    ASSERT(str != NULL);
    size = snprintf(str, size + 1, patern, str_uuid, uuid_creator, c->name,
        c->description);
    if (size == -1)
        return (NULL);
    return str;
}

static char *team_serializer_full(const void *data)
{
    team_t *t = (team_t *)data;
    char *str = NULL;
    char str_uuid[37];
    char str_uuid_creator[37];
    int size = 0;
    char *patern = "%s %s \"%s\" \"%s\"";

    uuid_unparse(t->uuid, str_uuid);
    uuid_unparse(t->u_creator, str_uuid_creator);
    size = snprintf(NULL, 0, patern, str_uuid, str_uuid_creator, t->name,
        t->description);
    if (size == -1)
        return (NULL);
    str = malloc(sizeof(char) * (size + 1));
    ASSERT(str != NULL);
    size = snprintf(str, size + 1, patern, str_uuid, str_uuid_creator, t->name,
        t->description);
    if (size == -1)
        return (NULL);
    return str;
}

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
    char *channel_ser = channel_serializer_full(data);
    char *threads = ll_serialize(&data->threads, (serialize_fn)thread_saver);
    char *r = strcat_alloc3(channel_ser, " ", threads);

    free(channel_ser);
    free(threads);
    return r;
}

char *team_saver(const void *data)
{
    team_t *team = (team_t *)(data);
    char *ser = team_serializer_full(data);
    char *channels = ll_serialize(&team->channels, (serialize_fn)channel_saver);
    char *members = ll_serialize(&team->users_uuid, uuid_serialize);
    char *r = strcat_alloc3(ser, " ", channels);
    char *r2 = strcat_alloc3(r, " ", members);

    free(ser);
    free(r);
    free(members);
    free(channels);
    return r2;
}