/*
** EPITECH PROJECT, 2021
** Tower_Defense
** File description:
** animate_char
*/

#include "game.h"

list_elem_char *facing_char_two(int facing, list_elem_char *character)
{
    switch (facing) {
    case 4:
        facing_south(character);
        break;
    case 5:
        facing_south_west(character);
        break;
    case 6:
        facing_west(character);
        break;
    case 7:
        facing_north_west(character);
        break;
    default:
        facing_stop(character);
    }
    return(character);
}

list_elem_char *facing_char(int facing, list_elem_char *character)
{
    switch (facing) {
    case 0:
        facing_north(character);
        break;
    case 1:
        facing_north_east(character);
        break;
    case 2:
        facing_east(character);
        break;
    case 3:
        facing_south_east(character);
        break;
    default:
        facing_char_two(facing, character);
    }
    return (character);
}

void ennemies_annimation(st_global *global)
{
    list_char li = malloc(sizeof(li));
    li = global->character_list;

    while (li != NULL) {
        li->object->timer->time = sfClock_getElapsedTime(li->object->timer->clock);
        li->object->timer->seconds = li->object->timer->time.microseconds / 10000;
        if (li->object->timer->seconds > 5.5) {
            facing_char(li->variable.facing, li);
        }
        li = li->next;
    }
}