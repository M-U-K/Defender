/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** gest_tower
*/

#include "defender.h"



void loading_tower4(data_t *data, double perc, int i)
{
    if (data->t_data->tab_tower[i]->tower == 1) {
        data->t_data->tab_tower[i]->pos.x -= 166;
        data->t_data->tab_tower[i]->pos.y -= 203;
        data->t_data->tab_tower[i]->dommage = 50;
        data->t_data->tab_tower[i]->range = 500;
        data->t_data->tab_tower[i]->proj->speed2 = 2;
        data->t_data->tab_tower[i]->proj->rate = 500;
        sfSprite_setPosition(data->t_data->tab_tower[i]\
->sprite, data->t_data->tab_tower[i]->pos);
        sfSprite_setTexture(data->t_data->tab_tower[i]\
->sprite, data->t_data->texture_tower->t_baliste_E, sfTrue);
    }
}

void loading_tower5(data_t *data, double perc, int i)
{
    if (data->t_data->tab_tower[i]->diff_time >= 2500 && \
data->t_data->tab_tower[i]->act == 2) {
        data->t_data->tab_tower[i]->pos.x += 10;
        data->t_data->tab_tower[i]->pos.y += 10;
        sfSprite_setPosition(data->t_data->tab_tower[i]->\
sprite, data->t_data->tab_tower[i]->pos);
        sfSprite_setTexture(data->t_data->tab_tower[i]->\
sprite, data->t_data->texture_tower->tower_build2, sfTrue);
        data->t_data->tab_tower[i]->act = 3;
    }
    if (data->t_data->tab_tower[i]->diff_time >= 5000 && \
data->t_data->tab_tower[i]->act == 3) {
        data->t_data->tab_tower[i]->act = 4;
        loading_tower1(data, perc, i);
        loading_tower2(data, perc, i);
        loading_tower3(data, perc, i);
        loading_tower4(data, perc, i);
    }
}

void loading_tower7(data_t *data, double perc, int i)
{
    if (data->t_data->tab_tower[i]->diff_time >= 0 && data->t_data\
->tab_tower[i]->act == 1) {
        data->t_data->tab_tower[i]->pos.x -= 33;
        data->t_data->tab_tower[i]->pos.y -= 34;
        sfSprite_setPosition(data->t_data->tab_tower[i]->sprite, \
data->t_data->tab_tower[i]->pos);
        sfSprite_setTexture(data->t_data->tab_tower[i]->sprite, \
data->t_data->texture_tower->tower_build1, sfTrue);
        data->t_data->tab_tower[i]->act = 2;
    }
}

void loading_tower6(data_t *data, double perc, int i)
{
    data->t_data->tab_tower[i]->past_time = data->t_data->tab_tower\
[i]->actual_time;
    data->t_data->tab_tower[i]->actual_time = sfTime_asMilliseconds\
(sfClock_getElapsedTime(data->setting->time->clock));
    data->t_data->tab_tower[i]->diff_time += (data->t_data->tab_tow\
er[i]->actual_time - data->t_data->tab_tower[i]->past_time);
    data->t_data->tab_tower[i]->diff_time_speed = (data->t_data->ta\
b_tower[i]->actual_time - data->t_data->tab_tower[i]->past_time) * \
(data->setting->time->game_speed);
    perc = 1000;
    perc = (((perc*data->t_data->tab_tower[i]->diff_time)/5000*100)\
/perc);
    sfSprite_setTextureRect(data->t_data->tab_tower[i]->loading_bl\
ue_sprite, (sfIntRect) {0, 23, (perc * 129/100), 23});
    loading_tower7(data, perc, i);
}

void loading_tower(data_t *data)
{
    double perc = 1000;
    for (int i = 0; i != 20; i++) {
        if (data->t_data->tab_tower[i]->act == 1 || data->\
t_data->tab_tower[i]->act == 2 || data->t_data->tab_tower[i]->act == 3) {
            loading_tower5(data, perc, i);
            loading_tower6(data, perc, i);
        }
    }
}
