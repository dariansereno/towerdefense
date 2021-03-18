/*
** EPITECH PROJECT, 2021
** Tower_Defense
** File description:
** list_action_astar
*/

#include "game.h"

path_node *list_astar_min_value(list_astar li)
{
    int max = 0;
    path_node *max_node;

    while (li != NULL) {
        if (max < li->node->global_goal) {
            max = li->node->global_goal;
            max_node = li->node;
        }
        li = li->next;
    }
    return (max_node);
}

list_astar pop_pos_astar(list_astar li, sfVector2i pos)
{
    list_elem_astar *temp = NULL;
    list_elem_astar *buffer = NULL;

    if (li == NULL)
        return (li);
    temp = li;
    buffer = li;
    while ((temp->node->pos.x != pos.x && temp->node->pos.y != pos.y) && li != NULL) {
        buffer = temp;
        temp = temp->next;
    }
    buffer->next = NULL;
    free(temp);
    temp = NULL;
    return (li);
}

int size_list_astar(list_astar li)
{
    int i = 0;

    while (li != NULL) {
        i++;
        li = li->next;
    }
    return (i);
}

void print_list_astar_fcost(list_astar li)
{
    while (li != NULL) {
        printf("%d\n", li->node->global_goal);
        li = li->next;
    }
}