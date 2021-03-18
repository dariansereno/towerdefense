/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** game
*/

#include "game.h"

void game_normal(st_global *global, sfRenderWindow *window)
{
    sfEvent event;
    global->map->map_int = convert_map_to_valid_map(global->map);
    global->map->map_vector = create_2d_map(global->map);
    global->character_list = generate_random_char_between(1, 1);

    path_finding(global, (sfVector2i){0, 0}, (sfVector2i){5, 5});
    exit(0);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfWhite);
        global->map = draw_2d_map(window, global->map);
        while (sfRenderWindow_pollEvent(window, &event)) {
            event_character(event, window, global);
            events_game_normal(event, window, global);
        }
        display_map(global, window);
        all_bars(window, global, event);
        ennemies_annimation(global);
        sfRenderWindow_display(window);
    }
}