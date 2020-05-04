/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** is_str_number
*/

#include <stdbool.h>

bool is_str_digit(const char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9')
            return (false);
        i++;
    }
    return (true);
}