/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** disp_tower_fire
*/

#include "defender.h"

void disp_tower_fire(data_t *data)
{
    for (int i = 0; i != 20; i++) {
        if ((data->t_data->tab_tower[i]->angle == 2 || data->\
t_data->tab_tower[i]->angle == 4) && data->t_data->tab_tower[i]\
->proj->active == 1 && data->t_data->tab_tower[i]->proj->act \
!= 2 && data->t_data->tab_tower[i]->proj->act != 0)
            sfRenderWindow_drawSprite(data->setting->window->\
r_window, data->t_data->tab_tower[i]->proj->sprite, NULL);
    }
    disp_tower(data);
    for (int i = 0; i != 20; i++) {
        if ((data->t_data->tab_tower[i]->angle == 1 || data->\
t_data->tab_tower[i]->angle == 3) && data->t_data->tab_tower[i]\
->proj->active == 1 && data->t_data->tab_tower[i]->proj->act \
!= 2 && data->t_data->tab_tower[i]->proj->act != 0)
            sfRenderWindow_drawSprite(data->setting->window->\
r_window, data->t_data->tab_tower[i]->proj->sprite, NULL);
    }
}

int range_tower(data_t *data, int i, sfVector2f pos)
{
    if ((pow(pos.x - (data->t_data->tab_tower[i]->pos.x + \
255), 2)) + (pow((data->t_data->tab_tower[i]->pos.y+240) - \
pos.y, 2)) < (pow(data->t_data->tab_tower[i]->range, 2))) {
        return (1);
    }
    return (0);
}

void change_angle1(data_t *data, int i)
{
    if (data->t_data->tab_tower[i]->tower == 1 && data->\
t_data->tab_tower[i]->angle == 1) {
        sfSprite_setTexture(data->t_data->tab_tower[i]\
->sprite, data->t_data->texture_tower->t_baliste_E, sfTrue);
        data->t_data->tab_tower[i]->proj->pos.x += 98;
        data->t_data->tab_tower[i]->proj->pos.y -= 12;
        data->t_data->tab_tower[i]->proj->rot = 120;
        sfSprite_setRotation(data->t_data->tab_tower[i]->\
proj->sprite, data->t_data->tab_tower[i]->proj->rot);
    }
    if (data->t_data->tab_tower[i]->tower == 1 && data\
->t_data->tab_tower[i]->angle == 2) {
        sfSprite_setTexture(data->t_data->tab_tower[i]\
->sprite, data->t_data->texture_tower->t_baliste_N, sfTrue);
        data->t_data->tab_tower[i]->proj->pos.x += 90;
        data->t_data->tab_tower[i]->proj->pos.y -= 45;
        data->t_data->tab_tower[i]->proj->rot = 65;
        sfSprite_setRotation(data->t_data->tab_tower[i]\
->proj->sprite, data->t_data->tab_tower[i]->proj->rot);
    }
}

void change_angle2(data_t *data, int i)
{
    if (data->t_data->tab_tower[i]->tower == 1 && data\
->t_data->tab_tower[i]->angle == 3) {
        sfSprite_setTexture(data->t_data->tab_tower[i]\
->sprite, data->t_data->texture_tower->t_baliste_S, sfTrue);
        data->t_data->tab_tower[i]->proj->pos.x += 35;
        data->t_data->tab_tower[i]->proj->pos.y += 2;
        data->t_data->tab_tower[i]->proj->rot = 245;
        sfSprite_setRotation(data->t_data->tab_tower[i]\
->proj->sprite, data->t_data->tab_tower[i]->proj->rot);
    }
    if (data->t_data->tab_tower[i]->tower == 1 && data\
->t_data->tab_tower[i]->angle == 4) {
        sfSprite_setTexture(data->t_data->tab_tower[i]\
->sprite, data->t_data->texture_tower->t_baliste_W, sfTrue);
        data->t_data->tab_tower[i]->proj->pos.x += 30;
        data->t_data->tab_tower[i]->proj->pos.y -= 30;
        data->t_data->tab_tower[i]->proj->rot = 295;
        sfSprite_setRotation(data->t_data->tab_tower[i]\
->proj->sprite, data->t_data->tab_tower[i]->proj->rot);
    }
}

void change_angle3_2(data_t *data, int i)
{
    if (data->t_data->tab_tower[i]->tower == 2 && data\
->t_data->tab_tower[i]->angle == 3) {
        sfSprite_setTexture(data->t_data->tab_tower[i]\
->sprite, data->t_data->texture_tower->t_canon_S, sfTrue);
        data->t_data->tab_tower[i]->proj->pos.x += 30;
        data->t_data->tab_tower[i]->proj->pos.y -= 20;
    }
    if (data->t_data->tab_tower[i]->tower == 2 && data\
->t_data->tab_tower[i]->angle == 4) {
        sfSprite_setTexture(data->t_data->tab_tower[i]\
->sprite, data->t_data->texture_tower->t_canon_W, sfTrue);
        data->t_data->tab_tower[i]->proj->pos.x += 30;
        data->t_data->tab_tower[i]->proj->pos.y -= 48;
    }
}