/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** str_to_wordtab
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "common.h"

static size_t get_array_size(char *s, char *delim)
{
    size_t size = 0;
    char *r;

    r = strtok(s, delim);
    while (r) {
        r = strtok(NULL, delim);
        size++;
    }
    free(s);
    return (size);
}

void destroy_tab(char **t)
{
    if (t == NULL)
        return;
    for (size_t i = 0; t[i] != NULL; i++)
        free(t[i]);
    free(t);
}

void print_tab(char **t)
{
    if (t == NULL)
        return;
    for (size_t i = 0; t[i] != NULL; i++)
        dprintf(1, "%s\n", t[i]);
}

char **str_to_wordtab(char *s, char *delim)
{
    char **res = NULL;
    char *sdup = NULL;
    size_t size = 0;

    if (s == NULL)
        return (NULL);
    sdup = strdup(s);
    ASSERT(sdup != NULL);
    size = get_array_size(sdup, delim);
    res = calloc(sizeof(char *), (size + 1));
    ASSERT(res != NULL);
    if (size == 0)
        return (res);
    res[0] = strdup(strtok(s, delim));
    ASSERT(res[0] != NULL);
    for (size_t i = 1; i < size; i++) {
        res[i] = strdup(strtok(NULL, delim));
        ASSERT(res[i] != NULL);
    }
    return (res);
}