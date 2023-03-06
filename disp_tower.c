/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** disp_tower
*/

#include "defender.h"

void disp_tower2(data_t *data, int i)
{
    if (data->t_data->tab_tower[i]->act == 1 || data->\
t_data->tab_tower[i]->act == 2 || data->t_data->tab_tower[i]->act == 3) {
        sfRenderWindow_drawSprite(data->setting->window\
->r_window, data->t_data->tab_tower[i]->loading_black_sprite, NULL);
        sfRenderWindow_drawSprite(data->setting->window\
->r_window, data->t_data->tab_tower[i]->loading_blue_sprite, NULL);
    }
}

void disp_tower(data_t *data)
{
    for (int i = 0; i != 20; i ++) {
        if (data->t_data->tab_tower[i]->act == 69) {
            sfRenderWindow_drawSprite(data->setting->window\
->r_window, data->t_data->tab_tower[i]->baliste, NULL);
            sfRenderWindow_drawSprite(data->setting->window\
->r_window, data->t_data->tab_tower[i]->canon, NULL);
            sfRenderWindow_drawSprite(data->setting->window\
->r_window, data->t_data->tab_tower[i]->lazer, NULL);
            sfRenderWindow_drawSprite(data->setting->window\
->r_window, data->t_data->tab_tower[i]->crystal, NULL);
        }
        disp_tower2(data, i);
        sfRenderWindow_drawSprite(data->setting->window->\
r_window, data->t_data->tab_tower[i]->sprite, NULL);
    }
}