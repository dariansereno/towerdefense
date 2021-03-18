/*
** EPITECH PROJECT, 2021
** structs.h
** File description:
** header
*/

#ifndef STRUCTS_H_
#define STRUCTS_H_

#include "CSFML.h"
#include <stdbool.h>

typedef struct drag_s {
    bool moving;
    sfVector2f mousePos;
    sfVector2f mouseReleased;
    sfVector2f origin_pos;
    sfVector2f a;
    sfVector2f b;
    sfVector2f c;
    sfVector2f d;
    sfVector2f p;
    double ab;
    double bc;
    double cd;
    double da;
    double ap;
    double bp;
    double cp;
    double dp;
} st_drag;

typedef struct menu_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfIntRect animation;
} st_menu;

typedef struct st_movement_s
{
    float x;
    float y;
    float velocity_x;
    float velocity_y;
    float acceleration_x;
    float acceleration_y;
} st_movements;

typedef struct st_char_variables_s
{
    float life;
    int dead;
    sfVector2f position;
    int facing;
    int previous_facing;
    int index;
} st_char_variables;

typedef struct st_tower_variables_s
{
    float life;
    int dead;
} st_tower_variables;

typedef struct st_timer_s
{
    sfTime time;
    sfClock *clock;
    float seconds;
}st_timer;

typedef struct st_object_s
{
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfIntRect animation;
    sfFloatRect hitbox;
    st_timer *timer;
} st_object;

typedef struct list_elem_ground
{
    char c;
    sfVertexArray *array;
    sfVector2i pos;
    struct list_elem_ground *next;
} list_elem_ground, *list_ground;

typedef struct list_elem_3D
{
    char c;
    sfVertexArray **array;
    sfVector2f *rlm;
    sfVector2i pos;
    struct list_elem_3D *next;
} list_elem_3D, *list_3D;

typedef struct list_elem_char
{
    st_char_variables variable;
    st_object *object;
    struct list_elem_char *next;
} list_elem_char, *list_char;

typedef struct st_character_s
{
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfIntRect animation;
    sfFloatRect hitbox;
    st_movements movements;
    st_char_variables variables;
} st_character;

typedef struct st_tower_s
{
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfIntRect animation;
    sfFloatRect hitbox;
    st_movements movements;
    st_tower_variables variables;
} st_tower;

typedef struct list_s {
    char *value;
    struct list_s *next;
} list_t;

typedef struct path_node_s path_node;

typedef struct list_astar {
    path_node *node;
    struct list_astar *next;
} *list_astar, list_elem_astar;

typedef struct path_node_s
{
    int local_goal;
    int global_goal;
    sfBool bObstacle;
    sfBool bVisited;
    list_astar neighbours;
    sfVector2i pos;
    path_node *parent;
} path_node;

typedef struct a_star {
    list_astar open;
    list_astar closed;
    path_node ***map_nodes;
    path_node *current;
    path_node *start;
    path_node *target;
    list_astar path;
} a_star;

typedef struct draglist_s {
    int value;
    struct draglist_s *next;
} draglist_t;

typedef unsigned char tileindex;

typedef struct tile_prop{
    st_object *tile;
    char c;
    int filled;
    int height;
    sfTexture **textures;
} tile_prop;

typedef struct interface_s{
    st_object **ui;
    sfText *money_text;
    sfText *heal_text;
    sfFont *font;
} st_interface;

typedef struct map_s {
    int height_tile;
    int width_tile;
    int nb_tile_x;
    int nb_tile_y;
    char *link;
    char **map;
    char **save;
    int map_height;
    int map_width;
    tile_prop *props;
    tileindex **tiles;
    int **map_int;
    sfVector2f **map_vector;
    list_ground li_ground;
    list_3D li_3D;
    int prop_size;
    int x;
    int y;
    int resize;
} st_map;

typedef struct global_variable_s {
    int menu;
    int interface;
    int frame_index;
} st_global_variable;

typedef struct global_s {
    list_char character_list;
    list_t *tower_list;
    st_map *map;
    st_menu **menu;
    st_interface *ui;
    st_global_variable *variable;
    st_drag *drag;
    st_object *background;
    st_object *map_background;
    st_timer *timer;
} st_global;

typedef struct map_vertex_s {
    char **map;
    sfVector2i pos; 
    sfVector2f **d2_map;
    sfTexture *texture;
    sfRenderWindow *window;
    int **intmap;
    int MAP_Y;
    int MAP_X;
} st_map_vertex;

#endif /* !STRUCTS_H_ */