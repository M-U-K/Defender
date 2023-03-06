/*
** EPITECH PROJECT, 2019
** Test
** File description:
** points_list.h
*/

#ifndef POINTS_LIST_H
#define POINTS_LIST_H

#include "global_struct.h"

typedef struct point_s {
    sfVector2f pos;
    float wait;
    bool is_waiting;
    float cel;
    game_time_t *time;
    struct point_s *next;
} point_t;

typedef struct {
    point_t *first;
    point_t *actual;
    point_t *last;
    float loop_time;
    game_time_t *time;
} points_list_t;

points_list_t *create_a_points_list(float loop_time);
void create_new_point(points_list_t *list, \
sfVector2f pos, float wait, float cel);

bool check_loop(points_list_t *list, sfClock *clock);
sfVector2f move_transform_to_point(sfSprite *spr, \
points_list_t *list, sfClock *clock);

#endif