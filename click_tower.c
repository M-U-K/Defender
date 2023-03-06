/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** event_tower2
*/

#include "defender.h"

void click_tower2(data_t *data, int i)
{
    if ((data->t_data->tools_tower->color_pixel.a != 0 && \
data->t_data->tools_tower->color_pixel.b != 0) && (data->t_data->t\
ools_tower->color_pixel.g != 0 && data->t_data->tools_tower->color_\
pixel.r != 0)) {
        data->t_data->tab_tower[i]->act = 69;
        data->setting->cursor->act_mouse = 1;
    }
}

void click_tower(data_t *data, int i)
{
    if (data->t_data->tab_tower[i]->act == 69)
        data->t_data->tab_tower[i]->act = 0;
    data->t_data->tab_tower[i]->globalBounds = sfSprite_getGlobalBo\
unds(data->t_data->tab_tower[i]->sprite);
    if (sfFloatRect_contains(&data->t_data->tab_tower[i]->globalBou\
nds, data->setting->cursor->pos_cursor_onMap.x, data->setting->curs\
or->pos_cursor_onMap.y) && data->setting->cursor->act_mouse == 0) {
        if (data->t_data->tab_tower[i]->act == 0) {
            data->t_data->tools_tower->color_pixel = sfImage_getPi\
xel(data->t_data->image_tower->tower_base, (unsigned int) (data->s\
etting->cursor->pos_cursor_onMap.x - data->t_data->tab_tower[i]->p\
os.x), (unsigned int) (data->setting->cursor->pos_cursor_onMap.y - \
data->t_data->tab_tower[i]->pos.y));
            click_tower2(data, i);
        }
    }
}