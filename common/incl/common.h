/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** common
*/

#ifndef COMMON_H_
#define COMMON_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define UNUSED __attribute__((unused))

#define BUFFER_READ_SIZE 4096
#define REQ_END "\r\n"

#define ASSERT(expr) \
    if (!(expr)) {  \
        fprintf(stdout, "Assertion fail %s:%d: %s\n", \
        __FILE__, __LINE__, #expr);\
        exit(84);   \
    }

// utils
bool is_str_digit(const char *str);
char *strcat_alloc(const char *s1, const char *s2);

// tab
char **str_to_wordtab(char *s, char delim, bool quotes);
void destroy_tab(char **t);
void print_tab(char **t);

char *bufferizer(char **pbuf, const char *req);

#endif /* !COMMON_H_ */