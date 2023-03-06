/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** tower
*/

#include "defender.h"

void hit_secondary(data_t *data, sfVector2f pos, int i)
{
    if (data->t_data->tab_tower[i]->tower == 3 && data->t_data\
->tab_tower[i]->proj->act == 0) {
        sfSprite_setTexture(data->t_data->tab_tower[i]->proj->\
sprite, data->t_data->texture_tower->lazer, sfTrue);
        data->t_data->tab_tower[i]->proj->act = 1;
    }
    if (data->t_data->tab_tower[i]->tower == 4 && data->t_data\
->tab_tower[i]->proj->act == 0) {
        sfSprite_setTexture(data->t_data->tab_tower[i]->proj->\
sprite, data->t_data->texture_tower->fire, sfTrue);
        data->t_data->tab_tower[i]->proj->act = 1;
    }
}

void hit_tower2(data_t *data, sfVector2f pos, int i)
{
    if (data->t_data->tab_tower[i]->tower == 1 && data->t_data\
->tab_tower[i]->proj->act == 0) {
        sfSprite_setTexture(data->t_data->tab_tower[i]->proj->\
sprite, data->t_data->texture_tower->arrow, sfTrue);
        data->t_data->tab_tower[i]->proj->act = 1;
    }
    if (data->t_data->tab_tower[i]->tower == 2 && data->t_data\
->tab_tower[i]->proj->act == 0) {
        sfSprite_setTexture(data->t_data->tab_tower[i]->proj->\
sprite, data->t_data->texture_tower->canonball, sfTrue);
        data->t_data->tab_tower[i]->proj->act = 1;
    }
    hit_secondary(data, pos, i);
}

int hit_fire_tower(data_t *data, sfVector2f pos, int tmp, int i)
{
    if (data->t_data->tab_tower[i]->proj->act == 0) {
        change_angle(data, i, pos);
        change_tower_angle(data, i);
        data->t_data->tab_tower[i]->proj->dest = pos;
        data->t_data->tab_tower[i]->proj->actual_time = \
sfTime_asMilliseconds(sfClock_getElapsedTime(data->setting->time->clock));
        data->t_data->tab_tower[i]->proj->active = 1;
        hit_tower2(data, pos, i);
    }
    if (data->t_data->tab_tower[i]->tower != 4)
        anim_proj(data, i, data->t_data->tab_tower[i]->proj->dest);
    if (data->t_data->tab_tower[i]->tower == 4)
        anim_proj_dot(data, i, data->t_data->tab_tower[i]->proj->dest);
    if (data->t_data->tab_tower[i]->dommage_return != 0) {
        tmp = data->t_data->tab_tower[i]->dommage_return;
        data->t_data->tab_tower[i]->dommage_return = 0;
        return (tmp);
    }
    return (0);
}

int hit_tower(data_t *data, sfVector2f pos)
{
    int tmp = 0;
    for (int i = 0; i != 20; i++) {
        data->t_data->tab_tower[i]->dommage_return = 0;
        if (data->t_data->tab_tower[i]->act == 4 && (range_tower(data, i, pos) \
|| data->t_data->tab_tower[i]->proj->act == 1 || data->t_data->tab_tower[i]->\
proj->act == 2)) {
            tmp = hit_fire_tower(data, pos, tmp, i);
        }
        if (tmp != 0)
            return (tmp);
    }
    return (0);
}