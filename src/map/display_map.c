/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** display_map
*/

#include "game.h"
#include <stdio.h>

int index_prop(char c, st_map *map)
{
    int i = 0;

    while (i < map->nb_tile_x * map->nb_tile_y) {
        if (c == map->props[i].c)
            return (i);
        i++;
    }
    return (-1);
}

void display_map(st_global *global, sfRenderWindow *window)
{
        sfRenderWindow_drawSprite(window, global->map_background->sprite, NULL);
        print_list_ground(global->map->li_ground, window, global->map);
        print_list_3D(global->map->li_3D, window, global->map, global);
}