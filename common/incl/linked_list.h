/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** linked_list
*/


typedef struct linked_list_s {
    void *data;
    struct linked_list_s *next;
} ll_t;

// create a list node
ll_t *ll_create(void *data);

//function to add element
void ll_push_back(ll_t **first, void *data);
void ll_push_front(ll_t **first, void *data);

//function to remove element
void ll_erase(ll_t **list, void *data, void(*destructor)(void*));
void ll_destroy(ll_t **list, void(*destructor)(void*));

//TODO create the lib