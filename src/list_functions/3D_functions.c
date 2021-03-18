/*
** EPITECH PROJECT, 2020
** push_swap
** File description:
** list_action
*/

#include "game.h"

list_3D push_back_3D(list_3D li, sfVertexArray **vertex, char c, sfVector2f *rlm, sfVector2i pos)
{
    list_elem_3D *elem;
    elem = malloc(sizeof(*elem));

    for (int i = 0; i < 4; i++)
        elem->array = sfVertexArray_create();
    for (int i = 0; i < 4; i++)
        elem->array[i] = vertex[i];
    elem->rlm = malloc(sizeof(sfVector2f) * 3);
    for (int i = 0; i < 3; i++)
        elem->rlm[i] = rlm[i];
    elem->pos = pos;
    elem->c = c;
    elem->next = NULL;

    if (li == NULL)
        return elem;

    list_elem_3D *temp;
    temp = li;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = elem;

    return (li);
}

void pop_position_3D(list_3D list, int position)
{
    list_3D temp = list;
    list_3D next = NULL;

    if (list == NULL)
        return;
    if (position == 1) {
        list = temp->next;
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

int size_list_3D(list_3D li)
{
    int i = 0;

    while (li != NULL) {
        i++;
        li = li->next;
    }
    return (i);
}

void pop_back_3D(list_3D *list)
{
    list_3D temp = NULL;
    list_3D buf = NULL;

    if (*list == NULL)
        return;
    if ((*list)->next == NULL) {
        for (int i = 0; i < 3; i++)
            sfVertexArray_destroy((*list)->array[i]);
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