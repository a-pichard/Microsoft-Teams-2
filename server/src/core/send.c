/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** send
*/

#include "server.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void write_q(client_t *client, const char *msg)
{
    ll_push_back(&client->write_q, strdup(msg));
}

void write_q_responce(client_t *client, int code, const char *msg)
{ 
    char *str = calloc(sizeof(char), strlen(msg) + 10);

    sprintf(str, "%d %s", code, msg);
    ll_push_back(&client->write_q, str);
}

void write_q_responce_objet(client_t *client, int code, void *objet,
    serialize_fn serilizer)
{
    char *objet_str = serilizer(objet);
    char *str = calloc(sizeof(char), strlen(objet_str) + 10);

    sprintf(str, "%d %s", code, objet_str);
    ll_push_back(&client->write_q, str);
    free(objet_str);
}

void write_q_responce_objet_list(client_t *client, int code, ll_t *objets,
    serialize_fn serilizer)
{
    char *objet_str = ll_serialize(&objets, serilizer);
    char *str = calloc(sizeof(char), strlen(objet_str) + 10);

    sprintf(str, "%d %s", code, objet_str);
    ll_push_back(&client->write_q, str);
    free(objet_str);
}

void send_message(server_t *server, client_t *client)
{
    void *data = ll_pop_front(&client->write_q);

    dprintf(client->fd, "%s\r\n", (char *)data);
    LOG("send:%s\n", (char *)data)
    if (!strcmp((char *)data, "200 logged out"))
        return ll_erase(&server->clients, client, &client_destructor);
    write_q_destructor(data);
}