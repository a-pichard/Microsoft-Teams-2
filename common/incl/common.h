/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** common
*/

#ifndef COMMON_H_
#define COMMON_H_

bool is_str_digit(const char *str);
char *strcat_alloc(const char *s1, const char *s2);
char **str_to_wordtab(char *s, char *delim);
void destroy_tab(char **t);
void print_tab(char **t);

#endif /* !COMMON_H_ */