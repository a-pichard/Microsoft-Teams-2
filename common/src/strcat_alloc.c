/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** strcat_alloc
*/

#include "common.h"
#include <stdlib.h>
#include <string.h>

char *strcat_alloc(const char *s1, const char *s2)
{
    char *res;
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    res = malloc(sizeof(char) * (len1 + len2 + 1));
    ASSERT(res != NULL);
    strcpy(res, s1);
    strcat(res, s2);
    return (res);
}

char *strcat_alloc3(const char *s1, const char *s2, const char *s3)
{
    char *res;
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int len3 = strlen(s3);

    res = malloc(sizeof(char) * (len1 + len2 + len3 + 1));
    ASSERT(res != NULL);
    strcpy(res, s1);
    strcat(res, s2);
    strcat(res, s3);
    return (res);
}