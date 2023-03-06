/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** event_tower
*/

#include "defender.h"



void choice_tower1(data_t *data, int i)
{
    data->t_data->tab_tower[i]->globalBounds = sfSprite_\
getGlobalBounds(data->t_data->tab_tower[i]->baliste);
    if (sfFloatRect_contains(&data->t_data->tab_tower[i]\
->globalBounds, data->setting->cursor->pos_cursor_onMap.\
x, data->setting->cursor->pos_cursor_onMap.y) && data->s\
etting->cursor->act_mouse == 0 && data->t_data->tab_tower\
[i]->act == 69) {
        data->setting->cursor->act_mouse = 1;
        data->t_data->tab_tower[i]->act = 1;
        data->t_data->tab_tower[i]->tower = 1;
        data->t_data->tab_tower[i]->range = 200;
        sfSprite_scale(data->t_data->tab_tower[i]->\
proj->sprite, (sfVector2f) {0.8, 0.8});
        data->t_data->tab_tower[i]->actual_time = \
sfTime_asMilliseconds(sfClock_getElapsedTime(data->setting->time->clock));
    }
}

void choice_tower2(data_t *data, int i)
{
    data->t_data->tab_tower[i]->globalBounds = sfS\
prite_getGlobalBounds(data->t_data->tab_tower[i]->canon);
    if (sfFloatRect_contains(&data->t_data->tab_tower\
[i]->globalBounds, data->setting->cursor->pos_cursor_\
onMap.x, data->setting->cursor->pos_cursor_onMap.y) \
&& data->setting->cursor->act_mouse == 0 && data->t_\
data->tab_tower[i]->act == 69) {
        data->setting->cursor->act_mouse = 1;
        data->t_data->tab_tower[i]->act = 1;
        data->t_data->tab_tower[i]->tower = 2;
        data->t_data->tab_tower[i]->range = 200;
        sfSprite_scale(data->t_data->tab_tower[i]\
->proj->sprite, (sfVector2f) {0.1, 0.1});
        data->t_data->tab_tower[i]->actual_time = \
sfTime_asMilliseconds(sfClock_getElapsedTime(data->setting->time->clock));
    }
}

void choice_tower3(data_t *data, int i)
{
    data->t_data->tab_tower[i]->globalBounds = sfSprite\
_getGlobalBounds(data->t_data->tab_tower[i]->lazer);
    if (sfFloatRect_contains(&data->t_data->tab_tower\
[i]->globalBounds, data->setting->cursor->pos_cursor_\
onMap.x, data->setting->cursor->pos_cursor_onMap.y) \
&& data->setting->cursor->act_mouse == 0 && data->t_d\
ata->tab_tower[i]->act == 69) {
        data->setting->cursor->act_mouse = 1;
        data->t_data->tab_tower[i]->act = 1;
        data->t_data->tab_tower[i]->tower = 3;
        data->t_data->tab_tower[i]->range = 200;
        sfSprite_scale(data->t_data->tab_tower[i]->\
proj->sprite, (sfVector2f) {0.05, 0.05});
        data->t_data->tab_tower[i]->actual_time = \
sfTime_asMilliseconds(sfClock_getElapsedTime(data->setting->time->clock));
    }
}

void choice_tower4(data_t *data, int i)
{
    data->t_data->tab_tower[i]->globalBounds = sfSprite_\
getGlobalBounds(data->t_data->tab_tower[i]->crystal);
    if (sfFloatRect_contains(&data->t_data->tab_tower[i]->\
globalBounds, data->setting->cursor->pos_cursor_onMap.x, \
data->setting->cursor->pos_cursor_onMap.y) && data->setti\
ng->cursor->act_mouse == 0 && data->t_data->tab_tower[i]->act == 69) {
        data->setting->cursor->act_mouse = 1;
        data->t_data->tab_tower[i]->act = 1;
        data->t_data->tab_tower[i]->tower = 4;
        data->t_data->tab_tower[i]->range = 200;
        sfSprite_scale(data->t_data->tab_tower[i]->proj->sprite, \
(sfVector2f) {1, 1});
        data->t_data->tab_tower[i]->actual_time = \
sfTime_asMilliseconds(sfClock_getElapsedTime(data->setting->time->clock));
    }
}

void choice_tower(data_t *data, int i)
{
    choice_tower1(data, i);
    choice_tower2(data, i);
    choice_tower3(data, i);
    choice_tower4(data, i);
}