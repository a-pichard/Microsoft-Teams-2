/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** str_to_wordtab
*/

#include <string.h>
#include "common.h"

static char **init_tab(char *s, char *delim, bool quotes)
{
    char delimiters[3] = {delim[0], quotes ? '\"' : '\0', '\0'};
    size_t size = 1;
    size_t length = 0;

    while (length != strlen(s)) {
        length = strcspn(s, delimiters);
        if (s[length] == delim[0]) {
            s = &s[length];
            length = strspn(s, delim);
            s = &s[length];
        } else if (quotes && s[length] == '\"') {
            s = &s[length + 1];
            length = strcspn(s, "\"");
            s = &s[length + 1];
        }
        size++;
    }
    return calloc(sizeof(char *), size + 1);
}

static void set_value(char **res, size_t *i, char *s, int length)
{
    if (!!length) {
        res[(*i)++] = strndup(s, length);
        res[(*i)] = NULL;
    }
}

static void loop_in_string(char **res, char *s, char *delim, bool quotes)
{
    char delimiters[3] = {delim[0], quotes ? '\"' : '\0', '\0'};
    size_t length = 0;
    size_t i = 0;

    while (length != strlen(s)) {
        length = strcspn(s, delimiters);
        if (s[length] == delim[0]) {
            set_value(res, &i, s, length);
            s = &s[length];
            length = strspn(s, delim);
            s = &s[length];
        } else if (quotes && s[length] == '\"') {
            set_value(res, &i, s, length);
            s = &s[length];
            length = strcspn(s + 1, "\"") + 1;
            set_value(res, &i, s, length + 1);
            s = &s[length + 1];
        }
    }
    set_value(res, &i, s, length);
}

char **str_to_wordtab(char *s, char delim, bool quotes)
{
    char delimiter[2] = {delim, '\0'};
    char **res = NULL;

    if (s == NULL)
        return (NULL);
    res = init_tab(s, delimiter, quotes);
    ASSERT(res != NULL);
    loop_in_string(res, s, delimiter, quotes);
    return (res);
}