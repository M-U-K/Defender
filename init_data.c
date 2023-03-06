/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** init_data
*/

#include "defender.h"

window_t *init_window(void)
{
    window_t *new = malloc(sizeof(window_t));
    sfVideoMode mode = {800, 600, 32};

    new->r_window = sfRenderWindow_create(mode, \
"my_defender", sfResize | sfClose, NULL);

    return (new);
}

cursor_t *init_cursor(void)
{
    cursor_t *new = malloc(sizeof(cursor_t));

    new->sensi_move_map = 2;
    new->act_mouse = 0;
    return (new);
}

g_time_t *init_time(void)
{
    g_time_t *new = malloc(sizeof(g_time_t));

    new->clock = sfClock_create();
    new->game_speed = 1;
    return (new);
}

setting_t *init_setting(void)
{
    setting_t *new = malloc(sizeof(setting_t));

    new->time = init_time();
    new->window = init_window();
    new->cursor = init_cursor();
    return (new);
}

data_t *init_global_data(void)
{
    data_t *new = malloc(sizeof(data_t));

    new->game_status = GS_GAME;
    new->setting = init_setting();
    new->m_data = init_map(new);
    new->t_data = init_tower();
    new->convoy = init_convoy(1);
    return (new);
}