/*
** EPITECH PROJECT, 2021
** Tower_Defense
** File description:
** path
*/

#include "game.h"

path_node ***create_all_neighbor(st_global *global, path_node ***map_nodes)
{
    for (int y = 0; y < global->map->map_height; y++) {
        for (int x = 0; x < global->map->map_width; x++) {
            map_nodes[y][x] = malloc(sizeof(path_node *));
            if (y > 0)
                map_nodes[y][x]->neighbours = push_back_list_astar(map_nodes
                [y][x]->neighbours, map_nodes[y - 1][x], map_nodes[y][x]);
            if (y > 0 && x > 0)
                map_nodes[y][x]->neighbours = push_back_list_astar(map_nodes
                [y][x]->neighbours, map_nodes[y - 1][x - 1], map_nodes[y][x]);
            if (y < global->map->map_height - 1)
                map_nodes[y][x]->neighbours = push_back_list_astar(map_nodes
                [y][x]->neighbours, map_nodes[y + 1][x], map_nodes[y][x]);
            if (y < global->map->map_height - 1 && x < global->map->map_width - 1)
                map_nodes[y][x]->neighbours = push_back_list_astar(map_nodes
                [y][x]->neighbours, map_nodes[y + 1][x + 1], map_nodes[y][x]);
            if (x > 0)
                map_nodes[y][x]->neighbours = push_back_list_astar(map_nodes
                [y][x]->neighbours, map_nodes[y][x - 1], map_nodes[y][x]);
            if (x > 0 && y < global->map->map_height - 1)
                map_nodes[y][x]->neighbours = push_back_list_astar(map_nodes
                [y][x]->neighbours, map_nodes[y + 1][x - 1], map_nodes[y][x]);
            if (x < global->map->map_width - 1)
                map_nodes[y][x]->neighbours = push_back_list_astar(map_nodes
                [y][x]->neighbours, map_nodes[y][x + 1], map_nodes[y][x]);
            if (x < global->map->map_width - 1 && y > 0)
                map_nodes[y][x]->neighbours = push_back_list_astar(map_nodes
                [y][x]->neighbours, map_nodes[y - 1][x + 1], map_nodes[y][x]);
        }
    }
    return (map_nodes);
}

path_node ***convert_map_to_node(st_global *global)
{
    path_node ***tab_node = malloc(sizeof(path_node **) * global->map->map_height);
    for (int i = 0; i < global->map->map_height; i++) {
        tab_node[i] = malloc(sizeof(path_node *) * global->map->map_width);
        for (int j = 0; j < global->map->map_width; j++) {
            tab_node[i][j] = malloc(sizeof(path_node));
            tab_node[i][j]->pos.x = j;
            tab_node[i][j]->pos.y = i;
            tab_node[i][j]->local_goal = 10000;
            tab_node[i][j]->global_goal = 10000;
            tab_node[i][j]->bVisited = sfFalse;
            tab_node[i][j]->bObstacle = sfFalse;
            if (global->map->props[find_index(global->map->props, global->map->map[i][j], global->map)].filled == 1)
                tab_node[i][j]->bObstacle = sfTrue;
            tab_node[i][j]->parent = NULL;
        }
    }
    tab_node = create_all_neighbor(global, tab_node);
    return (tab_node);
}

path_node return_pos_value(st_global *global, sfVector2i pos, path_node **tab)
{
    for (int i = 0; i < global->map->map_height; i++) {
        for (int j = 0; j < global->map->map_width; j++) {
            if (pos.x == tab[i][j].pos.x && pos.y == tab[i][j].pos.y)
                return (tab[i][j]);
        }
    }
    return (tab[0][0]);
}

a_star *initialise_struct_astar(st_global *global, sfVector2i pos_start, sfVector2i target)
{
    a_star *astar = malloc(sizeof(*astar));
    astar->current = malloc(sizeof(path_node *));
    astar->current->parent = malloc(sizeof(path_node *));
    astar->closed = NULL;
    astar->open = NULL;
    astar->map_nodes = convert_map_to_node(global);
    astar->start = malloc(sizeof(path_node *));
    astar->start = astar->map_nodes[pos_start.y][pos_start.x];
    astar->target = malloc(sizeof(path_node *));
    astar->target = astar->map_nodes[target.y][target.x];

    return (astar);
}

list_astar compute_path(a_star *astar)
{
    list_astar path = NULL;

    while (astar->target->parent != NULL) {
        path = push_front_list_astar(path, astar->target, astar->target->parent);
        astar->target = astar->target->parent;
    }
    return (path);
}

int heuristic(path_node *current,path_node *target)
{
    sfVector2i start = current->pos;
    sfVector2i stop = target->pos;
    int price = 0;

    while (1) {
        if (start.x < stop.x && start.y < stop.y) {
            price += 14;
            start.x += 1;
            start.y += 1;
        }
        if (start.x > stop.x && start.y > stop.y) {
            price += 14;
            start.x -= 1;
            start.y -= 1;
        }
        if (start.x > stop.x && start.y == stop.y) {
            price += 10;
            start.x += 1;
        }
        if (start.x < stop.x && start.y == stop.y) {
            price += 10;
            start.x -= 1;
        }
        if (start.x == stop.x && start.y < stop.y) {
            price += 10;
            start.y += 1;
        }
        if (start.x == stop.x && start.y > stop.y) {
            price += 10;
            start.y -= 1;
        }
        if (start.x == stop.x && start.y == stop.y)
            break;
    }
    return (price);
}

void path_finding(st_global *global, sfVector2i pos_start, sfVector2i target)
{
    a_star *astar = initialise_struct_astar(global, pos_start, target);
    int possibly_local_goal = 0;

    astar->current = astar->start;
    astar->current->local_goal = 0;
    astar->start->local_goal = heuristic(astar->start, astar->target);
    astar->open = push_back_list_astar(astar->open, astar->start, NULL);
    print_list_astar_fcost(astar->open);
    while (size_list_astar(astar->open) != 0) {
        merge_sort(&astar->open);

        while (size_list_astar(astar->open) != 0 && astar->open->node->bVisited)
            astar->open = pop_front_astar(astar->open);
        
        if (size_list_astar(astar->open) == 0)
            break;
        
        astar->current = astar->open->node;
        astar->current->bVisited = sfTrue;

        // printf("%d\n", size_list_astar(astar->current->neighbours));
            printf("lol\n");
        print_list_astar_fcost(astar->current->neighbours);
        while (astar->current->neighbours != NULL) {
            // printf("%d\n", astar->current->neighbours->node->bObstacle);
            if (astar->current->neighbours->node->bVisited != sfFalse && astar->current->neighbours->node->bObstacle != sfFalse)
                astar->open = push_back_list_astar(astar->open, astar->current->neighbours->node, astar->current);
            possibly_local_goal = astar->current->local_goal + heuristic(astar->current, astar->current->neighbours->node);
            if (possibly_local_goal < astar->current->neighbours->node->local_goal) {
                astar->current->neighbours->node->parent = astar->current;
                astar->current->neighbours->node->local_goal = possibly_local_goal;
                astar->current->neighbours->node->global_goal = astar->current->neighbours->node->local_goal + heuristic(astar->current->neighbours->node, astar->target);
            }
        }
    }
}