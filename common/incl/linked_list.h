/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** linked_list
*/

#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <stdlib.h>

typedef struct linked_list_s {
    void *data;
    struct linked_list_s *next;
} ll_t;

typedef char *(*serialize_fn)(const void *);

// create a list node
ll_t *ll_create(void *data);

//function to add element
void ll_push_back(ll_t **first, void *data);
void ll_push_front(ll_t **first, void *data);

//function to remove element
void ll_erase(ll_t **list, void *data, void(*destructor)(void *));
void ll_destroy(ll_t **list, void(*destructor)(void *));

//function to get element
void *ll_pop_front(ll_t **list);

//function to apply a function to each element
void ll_apply(ll_t **list, void(*fn)(void *));
char *ll_serialize(ll_t **list, serialize_fn);

//len
size_t ll_len(ll_t **list);

#define ll_foreach(list, type, element, code) do {    \
    for (ll_t *current_foreach = list; current_foreach != NULL; \
        current_foreach = current_foreach->next) {    \
        type *element = (type*)(current_foreach->data); \
        code;   \
    }   \
} while (0);

#endif