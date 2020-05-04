/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** raise_err
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

void raise_err(bool valid, const char *msg)
{
    if (!valid) {
        fprintf(stdout, "%s\n", msg);
        exit(84);
    }
}