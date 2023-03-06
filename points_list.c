/*
** EPITECH PROJECT, 2019
** Test
** File description:
** points_list.c
*/

#include "defender.h"

void create_new_point(points_list_t *list, \
sfVector2f pos, float wait, float cel)
{
    point_t *new = malloc(sizeof(point_t));

    new->pos = pos;
    new->wait = wait;
    new->is_waiting = true;
    new->cel = cel;
    new->time = init_game_time();
    new->next = NULL;
    if (list->first == NULL) {
        list->first = new;
        list->actual = new;
    }
    if (list->last != NULL)
        list->last->next = new;
    list->last = new;
}

points_list_t *create_a_points_list(float loop_time)
{
    points_list_t *new = malloc(sizeof(points_list_t));

    new->first = NULL;
    new->last = NULL;
    new->loop_time = loop_time;
    new->time = init_game_time();
    return (new);
}

void check_loop2(points_list_t *list, sfClock *clock)
{
    list->time->dif += list->time->actual - list->time->last;
    if (list->loop_time != -1 && list->time->dif >= list->loop_time) {
        list->actual = list->first;
        list->time->dif = 0;
    }
}

bool check_loop(points_list_t *list, sfClock *clock)
{
    list->time->last = list->time->actual;
    list->time->actual = sfTime_asSeconds(sfClock_getElapsedTime(clock));
    if (list->actual != NULL) {
        list->actual->time->last = list->actual->time->actual;
        list->actual->time->actual = sfTime_asSeconds\
(sfClock_getElapsedTime(clock));
        list->actual->time->dif += list->actual->time->\
actual - list->actual->time->last;
        if (list->actual->is_waiting == true && list->actual\
->time->dif < list->actual->wait)
            return (true);
        list->actual->is_waiting = false;
        if (list->actual->time->dif < list->actual->cel)
            return (true);
        list->actual->time->dif = 0;
    } else {
        check_loop2(list, clock);
        return (true);
    }
    return (false);
}

sfVector2f move_transform_to_point
(sfSprite *spr, points_list_t *list, sfClock *clock)
{
    sfVector2f spr_pos = sfSprite_getPosition(spr);
    float vector[3] = {0, 0, 0};
    float x = 0;
    float y = 0;

    if (check_loop(list, clock) == true)
        return ((sfVector2f) {0, 0});
    vector[0] = list->actual->pos.x - spr_pos.x;
    vector[1] = list->actual->pos.y - spr_pos.y;
    if (vector[0] != 0 && vector[1] != 0) {
        vector[2] = sqrt(pow(vector[0], 2) + pow(vector[1], 2));
        if (vector[2] > 2) {
            x = vector[0] / (vector[2] / 2);
            y = vector[1] / (vector[2] / 2);
        }
    }
    if (x == 0 && y == 0 && list->actual != NULL) {
        list->actual = list->actual->next;
        list->time->dif = 0;
    }
    return ((sfVector2f){x, y});
}