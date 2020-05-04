/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** init_socket
*/

#include <sys/types.h>
#include <sys/socket.h>
#include "server.h"

static struct sockaddr_in get_default_sin(int port)
{
    struct sockaddr_in sin = { 0 };

    sin.sin_family = AF_INET;
    sin.sin_port = htons(port);
    sin.sin_addr.s_addr = htonl(INADDR_ANY);
    return (sin);
}

int init_main_server_socket(int port)
{
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in sin = get_default_sin(port);
    int ret;

    raise_err(fd != -1, "socket() ");
    ret = bind(fd, (struct sockaddr *)(&sin), sizeof(sin));
    raise_err(ret != -1, "bind() ");
    ret = listen(fd, MAX_CLIENTS_QUEUE);
    raise_err(ret != -1, "listen() ");
    return (fd);
}