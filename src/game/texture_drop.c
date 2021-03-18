/*
** EPITECH PROJECT, 2021
** mydefender
** File description:
** texture_drop
*/

#include "game.h"

char frame_letter(st_global *global)
{
    char letter;

    switch (global->variable->frame_index) {
        case 12:
            letter = 'j';
            break;
        case 13:
            letter = 'x';
            break;
        case 14:
            letter = 'r';
            break;
        case 15:
            letter = 'j';
            break;
        case 16:
            letter = 'x';
            break;
        default:
            letter = '0';
            break;
    }
    return (letter);
}

void texture_drop_fill(st_global *global, list_ground node_ground)
{
    char letter = frame_letter(global);

    global->map->map[node_ground->pos.y][node_ground->pos.x] = letter;
    global->map->map_int[node_ground->pos.y * 2][node_ground->pos.x * 2] = \
    global->map->props[find_index(global->map->props, letter, global->map)].height;
    global->map->map_int[node_ground->pos.y * 2 + 1][node_ground->pos.x * 2] = \
    global->map->props[find_index(global->map->props, letter, global->map)].height;
    global->map->map_int[node_ground->pos.y * 2 + 1][node_ground->pos.x * 2 + 1] = \
    global->map->props[find_index(global->map->props, letter, global->map)].height;
    global->map->map_int[node_ground->pos.y * 2][node_ground->pos.x * 2 + 1] = \
    global->map->props[find_index(global->map->props, letter, global->map)].height;
}

void texture_drop_empty(st_global *global, list_3D node_3d)
{
    char letter = frame_letter(global);

    global->map->map[node_3d->pos.y][node_3d->pos.x] = letter;
    global->map->map_int[node_3d->pos.y * 2][node_3d->pos.x * 2] = \
    global->map->props[find_index(global->map->props, letter, global->map)].height;
    global->map->map_int[node_3d->pos.y * 2 + 1][node_3d->pos.x * 2] = \
    global->map->props[find_index(global->map->props, letter, global->map)].height;
    global->map->map_int[node_3d->pos.y * 2 + 1][node_3d->pos.x * 2 + 1] = \
    global->map->props[find_index(global->map->props, letter, global->map)].height;
    global->map->map_int[node_3d->pos.y * 2][node_3d->pos.x * 2 + 1] = \
    global->map->props[find_index(global->map->props, letter, global->map)].height;
}