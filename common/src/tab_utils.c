/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** tab_utils
*/

#include <stdlib.h>
#include <stdio.h>

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

size_t get_tab_len(char **t)
{
    size_t i = 0;

    if (t == NULL)
        return (0);
    while (t[i])
        i++;
    return (i);
}