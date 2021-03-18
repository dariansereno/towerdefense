/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** parse_map
*/

#include "game.h"

void map_size_parsing(char **b_map, st_map *map, int i)
{
    int j = 0;
    char buff1[32];
    char buff2[32];
    int n = 0;

    while (b_map[i][j] != ' ') {
        if (b_map[i][j] >= '0' && b_map[i][j] <= '9')
            buff1[n++] = b_map[i][j];
        j++;
    }
    map->map_width = my_getnbr(buff1);
    n = 0;
    while (b_map[i][j] != '\0'){
        if (b_map[i][j] >= '0' && b_map[i][j] <= '9')
            buff2[n++] = b_map[i][j];
        j++;
    }
    map->map_height = my_getnbr(buff2);
}

void parse_map(char **b_map, st_map *map, int i)
{
    map_size_parsing(b_map, map, i++);
    map->map = malloc(sizeof(char *) * map->map_height);
    map->save = malloc(sizeof(char *) * map->map_height);
    map->tiles = malloc(sizeof(tileindex *) * map->map_height);
    for (int n = 0; my_strcmp(b_map[i], "#end") != 0; n++) {
        map->map[n] = malloc(sizeof(char) * (map->map_width + 1));
        map->save[n] = malloc(sizeof(char) * (map->map_width + 1));
        map->tiles[n] = malloc(sizeof(tileindex) * map->map_width); 
        for (int j = 0; b_map[i][j] != '\0'; j++) {
            map->map[n][j] = b_map[i][j];
            map->save[n][j] = b_map[i][j];
            map->tiles[n][j] = b_map[i][j];
        }
        map->map[n][map->map_width] = '\0';
        map->save[n][map->map_width] = '\0';
        i++;
    }
}