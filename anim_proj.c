/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** anim_proj
*/

#include "defender.h"

void anim_proj2(data_t *data, int i, sfVector2f pos, sfVector2f tmp)
{
    if (data->t_data->tab_tower[i]->proj->diff_time >= data->t_data->\
tab_tower[i]->proj->speed2 && data->t_data->tab_tower[i]->proj->act == 1) {
        tmp = move(data->t_data->tab_tower[i]->proj->pos, pos, data->\
t_data->tab_tower[i]->proj->speed);
        data->t_data->tab_tower[i]->proj->pos.x += tmp.x;
        data->t_data->tab_tower[i]->proj->pos.y += tmp.y;
        sfSprite_setPosition(data->t_data->tab_tower[i]->proj->sprite, \
data->t_data->tab_tower[i]->proj->pos);
        data->t_data->tab_tower[i]->proj->diff_time = 0;
        if (data->t_data->tab_tower[i]->proj->pos.x <= pos.x + 10 && \
data->t_data->tab_tower[i]->proj->pos.x >= pos.x - 10 && data->t_data->tab_\
tower[i]->proj->pos.y <= pos.y + 10 && data->t_data->tab_tower[i]->proj->pos\
.y >= pos.y - 10) {
            data->t_data->tab_tower[i]->proj->act = 2;
            data->t_data->tab_tower[i]->proj->pos = data->t_data->tab\
_tower[i]->proj->pos_save;
        }
    }
}

void anime_proj3(data_t *data, int i, sfVector2f pos, sfVector2f tmp)
{
    if (data->t_data->tab_tower[i]->proj->act == 1)
        data->t_data->tab_tower[i]->proj->diff_time += (data->t_data->\
tab_tower[i]->proj->actual_time - data->t_data->tab_tower[i]->proj->pas\
t_time * (data->setting->time->game_speed));
    data->t_data->tab_tower[i]->proj->diff_time2 += (data->t_data->\
tab_tower[i]->proj->actual_time - data->t_data->tab_tower[i]->proj->past\
_time * (data->setting->time->game_speed));
    data->t_data->tab_tower[i]->proj->diff_time_speed = (data->t_data\
->tab_tower[i]->proj->actual_time - data->t_data->tab_tower[i]->proj->past\
_time) * (data->setting->time->game_speed);
    anim_proj2(data, i, pos, tmp);
    if (data->t_data->tab_tower[i]->proj->diff_time2 >= data->t_data\
->tab_tower[i]->proj->rate && data->t_data->tab_tower[i]->proj->act == 2) {
        data->t_data->tab_tower[i]->proj->act = 0;
        data->t_data->tab_tower[i]->proj->diff_time2 = 0;
        data->t_data->tab_tower[i]->dommage_return = data->t_data->\
tab_tower[i]->dommage;
    }
}

void anim_proj(data_t *data, int i, sfVector2f pos)
{
    sfVector2f tmp;
    set_up_anim_proj1(data, i, pos, tmp);
    set_up_anim_proj2(data, i , pos, tmp);
    if (data->t_data->tab_tower[i]->proj->active == 1 && (data->t_data->\
tab_tower[i]->proj->act == 1 || data->t_data->tab_tower[i]->proj->act == 2)) {
        data->t_data->tab_tower[i]->proj->past_time = data->t_data->tab_\
tower[i]->proj->actual_time;
        data->t_data->tab_tower[i]->proj->actual_time = sfTime_asMillis\
econds(sfClock_getElapsedTime(data->setting->time->clock));
        anime_proj3(data, i, pos, tmp);
    }
}

void anime_proj_dot2(data_t *data, int i, sfVector2f pos)
{
    if (data->t_data->tab_tower[i]->proj->diff_time >= data->t_data->\
tab_tower[i]->proj->speed2 && data->t_data->tab_tower[i]->proj->act == 1) {
        data->t_data->tab_tower[i]->proj->pos.x = pos.x;
        data->t_data->tab_tower[i]->proj->pos.y = pos.y;
        sfSprite_setPosition(data->t_data->tab_tower[i]->proj->sprite\
, data->t_data->tab_tower[i]->proj->pos);
        data->t_data->tab_tower[i]->proj->diff_time = 0;
        data->t_data->tab_tower[i]->dommage_return = data->t_data->\
tab_tower[i]->dommage;
        data->t_data->tab_tower[i]->proj->act = 0;
    }
}

void anim_proj_dot(data_t *data, int i, sfVector2f pos)
{
    pos.x -= 50;
    pos.y -= 60;
    if (data->t_data->tab_tower[i]->proj->active == 1 && data->t_data->tab_t\
ower[i]->proj->act == 1) {
        data->t_data->tab_tower[i]->proj->past_time = data->t_data->tab_towe\
r[i]->proj->actual_time;
        data->t_data->tab_tower[i]->proj->actual_time = sfTime_asMillisecon\
ds(sfClock_getElapsedTime(data->setting->time->clock));
        data->t_data->tab_tower[i]->proj->diff_time += (data->t_data->tab_\
tower[i]->proj->actual_time - data->t_data->tab_tower[i]->proj->past_time \
* (data->setting->time->game_speed));
        data->t_data->tab_tower[i]->proj->diff_time_speed = (data->t_data\
->tab_tower[i]->proj->actual_time - data->t_data->tab_tower[i]->proj->past\
_time) * (data->setting->time->game_speed);
        anime_proj_dot2(data, i, pos);
    }
}