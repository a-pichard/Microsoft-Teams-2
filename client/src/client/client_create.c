/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** client
*/

#include "client.h"
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

static int connect_to_server(const char *ip, int port)
{
    int fd;
    struct sockaddr_in server_addr = { 0 };

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip);
    fd = socket(AF_INET, SOCK_STREAM, 0);
    ASSERT(fd != -1);
    ASSERT(connect(fd, (struct sockaddr *)&server_addr,
        sizeof(struct sockaddr_in)) != -1);
    return (fd);
}

static client_t *client_create(client_t *client, const char *ip, int port)
{
    client->fd = connect_to_server(ip, port);
    ASSERT(client->fd != -1);
    client->req = NULL;
    client->to_send = NULL;
}

client_t *client_save(client_t *client)
{
    static client_t *save = NULL;

    if (client == NULL)
        return (save);
    save = client;
    return (save);
}

client_t *init_client(const char *ip, const char *port_str)
{
    client_t *client = NULL;
    char *end;
    int port = -1;

    port = strtol(port_str, &end, 10);
    if (*end != '\0')
        return NULL;
    client = malloc(sizeof(client_t));
    ASSERT(client != NULL);
    client_create(client, ip, port);
    client_save(client);
    return (client);
}
