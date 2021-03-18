/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** game
*/

#ifndef GAME_H_
#define GAME_H_

#include "CSFML.h"
#include "strings.h"
#include "structs.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <math.h>

#define WIDTH 1920
#define HEIGHT 1080

// WINDOW
    sfRenderWindow *window_create(void);

// GAME
    // GAME
        void game_normal(st_global *global, sfRenderWindow *window);
    // DRAG_N_DROP
        void drag(sfRenderWindow *window, sfEvent event, st_global *global);
        void drop(st_global *global, sfRenderWindow *window);
        int frame_selected(st_global *global, sfVector2f pos);
        st_drag *generate_drag_n_drop(st_global *global);
        void drag2(st_global *global, sfEvent event, sfRenderWindow *window);
    // VECTOR_DROP
        bool conditions_intersection(st_global *global);
        bool is_intersection(st_global *global, sfVector2f p);
        double aire_triangle(double a, double b, double c);
    // TEXTURE_DROP
        void texture_drop_fill(st_global *global, list_ground node_ground);
        char frame_letter(st_global *global);
        void texture_drop_empty(st_global *global, list_3D node_3d);
    // ennemies_handling
        list_char generate_random_char_between(int min, int max);

// INTERFACE
    // UI
        void all_bars(sfRenderWindow *window, st_global *global, sfEvent event);
        void top_bar(sfRenderWindow *window, st_global *global);
        void upgrade_coins(st_global *global);
        void upgrade_heal(st_global *global);
        void display_bottom_bar(sfRenderWindow *window, st_global *global);
    // GENERATION_UI
        st_object **generate_ui(void);
        st_object **generate_ui2(st_object **tab);
        st_object **generate_rectangle_ui(st_object **tab);
        st_interface *generate_interface(st_global *global);
    // UI_TEXT
        const char *nb_in_text(int number);
        void ui_text_bars(st_global *global, sfRenderWindow *window);

// EVENT
    // EVENT
        void events_menu(sfEvent event, sfRenderWindow *window, st_global *global);
        void events_close(sfEvent event, sfRenderWindow *window);
        void events_game_normal(sfEvent event, sfRenderWindow *window, st_global *global);
        void menu_button_event(sfEvent event, sfRenderWindow *window, st_global *global);
        void event_character(sfEvent event, sfRenderWindow *window, st_global *global);
// MENU
    // MENULOOP
        void menuloop(sfRenderWindow *window, st_global *global);
        st_menu **generate_menu_tab(void);

// MAP
    // PARSE_TILESET
        st_map *read_file(char *path);
    // PARSE_MAP
        int find_index(tile_prop *prop, char c, st_map *map);
        int **convert_map_to_valid_map(st_map *map);
        void parse_map(char **b_map, st_map *map, int i);
    // DISPLAY_MAP
        void display_map(st_global *global, sfRenderWindow *window);
        int index_prop(char c, st_map *map);
    // DRAWING
        st_map *draw_2d_map(sfRenderWindow *window, st_map *map);
    // CREATE_VERTEX_ARRAY
        sfVector2f project_iso_point(int x, int y, int z);
        sfVector2f **create_2d_map(st_map *map);
        sfVertexArray *create_quad(sfVector2f *point1 , sfVector2f *point2, sfVector2f *point3, sfVector2f *point4);
        sfRenderStates *rendering(sfTexture *texture);

// OBJECT
    // GENERATION
        st_object *generate_tiles(char *path, int x, int y, sfVector2i shift);
        st_object *generate_object(char *path, sfVector2f pos, sfIntRect animation);
        st_global *generate_global(void);
        st_menu *generate_menu(char *path, sfVector2f pos, sfIntRect rect);
    // DESTRUCT
        void destruct_object(st_object *object);
    // ANIMATE_CHAR
        void ennemies_annimation(st_global *global);
    // SOUTH_FACING_ANIMATION
        void facing_south_east(list_elem_char *character);
        void facing_south(list_elem_char *character);
        void facing_south_west(list_elem_char *character);
        void facing_west(list_elem_char *character);
    // NORTH_FACING_ANIMATION
        void facing_north_west(list_elem_char *character);
        void facing_north(list_elem_char *character);
        void facing_north_east(list_elem_char *character);
        void facing_east(list_elem_char *character);
        void facing_stop(list_elem_char *character);

// LIST_FUNCTIONS
    // DRAGLIST_FUNCTIONS
        void drag_pushback(draglist_t **list, int value);
        void drag_print(draglist_t *list);
        int drag_exists(draglist_t *list, int value);
    // 3D_FUNCTIONS
        int size_list_3D(list_3D li);
        void print_list_3D(list_3D li, sfRenderWindow *window, st_map *map, st_global *global);
        list_3D push_back_3D(list_3D li, sfVertexArray **vertex, char c, sfVector2f *rlm, sfVector2i pos);
        void pop_back_3D(list_3D *list);
    // GROUND_FUNCTION
        list_ground push_back_ground(list_ground li, sfVertexArray *vertex, char c, sfVector2i pos);
        void print_list_ground(list_ground li, sfRenderWindow *window, st_map *map);
        sfBool is_in_ground_list(sfVertexArray *vertex, list_ground li);
        int size_list_ground(list_ground li);
        list_ground pop_back_ground(list_ground list);
    // CHAR_FUNCTIONS
        list_char push_back_char(list_char li, st_object *object, st_char_variables variable);
        void pop_position_char(list_char list, sfVector2f position);
        int size_list_char(list_char li);
        void print_char_list(list_char li, sfRenderWindow *window);
//RANDOM
    int random_between(int start, int stop);

// PATH_FINDING
    // MERGE_SORT
        void merge_sort(list_astar *head_ref);
    // LIST_ASTAR
        list_astar push_back_list_astar(list_astar li, path_node *node, path_node *parent);
        list_astar push_front_list_astar(list_astar li, path_node *node, path_node *parent);
        list_astar pop_back_astar(list_astar li);
        list_astar pop_front_astar(list_astar li);
        int is_in_list_astar(list_astar li, sfVector2i pos);
        path_node *list_astar_min_value(list_astar li);
        list_astar pop_pos_astar(list_astar li, sfVector2i pos);
        int size_list_astar(list_astar li);
        void print_list_astar_fcost(list_astar li);
    // PATH
        path_node ***convert_map_to_node(st_global *global);
        void path_finding(st_global *global, sfVector2i pos_start, sfVector2i target);
#endif /* !GAME_H_ */