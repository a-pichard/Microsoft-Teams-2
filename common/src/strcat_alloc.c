/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** strcat_alloc
*/

#include <stdlib.h>
#include <string.h>

char *strcat_alloc(const char *s1, const char *s2)
{
    char *res;
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int i = 0;
    int j = 0;

    res = malloc(sizeof(char) * (len1 + len2 + 1));
    return (NULL);
    for (; i < len1; i++)
        res[i] = s1[i];
    for (; j < len2; j++)
        res[i + j] = s2[j];
    res[i + j] = '\0';
    return (res);
}