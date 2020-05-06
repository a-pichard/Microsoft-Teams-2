/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** server
*/

#include "server.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

static void init_new_client(client_t *client, int client_sock)
{
    client->fd = client_sock;
    client->req = NULL;
    client->write_q = NULL;
}

static void accept_new_client_connection(server_t *server)
{
    struct sockaddr *client_info = NULL;
    socklen_t size = sizeof(client_info);
    int client_sock;
    client_t *client = malloc(sizeof(client_t));
    char *ok_msg = "TODO: user connected\r\n";

    client_sock = accept(server->server_fd, client_info, &size);
    raise_err(client_sock != -1, "accept() ");
    init_new_client(client, client_sock);
    ll_push_back(&server->clients, (void *)client);
    write_q(client, ok_msg);
}

static int reset_selected_fd(server_t *server, fd_set *rset, fd_set *wset)
{
    int max_fd = server->server_fd;

    FD_ZERO(wset);
    FD_ZERO(rset);
    FD_SET(server->server_fd, rset);
    for (ll_t *c = server->clients; c != NULL; c = c->next) {
        FD_SET(((client_t *)(c->data))->fd, rset);
        if (((client_t *)(c->data))->write_q != NULL)
            FD_SET(((client_t *)(c->data))->fd, wset);
        if (((client_t *)(c->data))->fd > max_fd)
            max_fd = ((client_t *)(c->data))->fd;
    }
    return (max_fd + 1);
}

static void parse_io(server_t *server, fd_set *rset, fd_set *wset)
{
    ll_t *tmp = NULL;
    ll_t *client = NULL;

    for (client = server->clients; client != NULL;) {
        tmp = client->next;
        if (FD_ISSET(((client_t *)(client->data))->fd, rset))
            handle_client(server, client->data);
        client = tmp;
    }
    for (client = server->clients; client != NULL; client = client->next) {
        if (FD_ISSET(((client_t *)(client->data))->fd, wset))
            send_message(client->data);
    }
}

void run_server(server_t *server)
{
    int max_fd;
    int ret;
    fd_set rset;
    fd_set wset;

    while (1) {
        max_fd = reset_selected_fd(server, &rset, &wset);
        ret = select(max_fd, &rset, &wset, NULL, NULL);
        raise_err(ret != -1, "select() ");
        if (FD_ISSET(server->server_fd, &rset)) {
            accept_new_client_connection(server);
            FD_CLR(server->server_fd, &rset);
        }
        parse_io(server, &rset, &wset);
    }
}