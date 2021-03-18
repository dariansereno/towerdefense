/*
** EPITECH PROJECT, 2021
** list fonctions
** File description:
** list_functions
*/

#include "game.h"

void push_front(list_t **list, char *value)
{
    list_t *node = malloc(sizeof(*node));

    node->value = value;
    node->next = *list;
    *list = node;
}

void list_print(list_t *list)
{
    while (list != NULL) {
        my_putstr(list->value);
        write(1, "\n", 1);
        list = list->next;
    }
}

void push_back(list_t **list, char *value)
{
    list_t *node = malloc(sizeof(*node));
    list_t *lastnode = *list;

    node->value = value;
    node->next = NULL;
    if (*list == NULL)
        *list = node;
    else {
        while (lastnode->next != NULL)
            lastnode = lastnode->next;
        lastnode->next = node;
    }
}

void pop_position(list_t **list, int position)
{
    list_t *temp = *list;
    list_t *next = NULL;

    if (*list == NULL)
        return;
    if (position == 1) {
        *list = temp->next;
        free(temp);
        return;
    }
    for (int i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->next;
    if (temp == NULL || temp->next == NULL)
        return;
    next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

void int_list_push_front(list_t **list, int value)
{
    list_t *node = malloc(sizeof(*node));

    node->value = value;
    node->next = *list;
    *list = node;
}

size_t int_list_size(list_t *list)
{
    size_t size = 0;

    while (list != NULL) {
        size++;
        list = list->next;
    }
    return (size);
}

int int_list_pop_front(list_t **list)
{
    list_t *node = *list;
    int count = node->value;

    *list = (*list)->next;
    free(node);
    return (count);
}

void int_list_pop_back(list_t **list)
{
    list_t *temp = NULL;
    list_t *buf = NULL;

    if (*list == NULL)
        return;
    if ((*list)->next == NULL) {
        free(list);
        *list = NULL;
        return;
    }
    temp = *list;
    buf = *list;
    while (temp->next != NULL) {
        buf = temp;
        temp = temp->next;
    }
    buf->next = NULL;
    free(temp);
    temp = NULL;
}

int last_value(list_t *list)
{
    while (list->next != NULL)
        list = list->next;
    return (list->value);
}