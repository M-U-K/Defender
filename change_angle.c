/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** change_angle
*/

#include "defender.h"

void change_angle3(data_t *data, int i)
{
    if (data->t_data->tab_tower[i]->tower == 2 && data\
->t_data->tab_tower[i]->angle == 1){
        sfSprite_setTexture(data->t_data->tab_tower[i]\
->sprite, data->t_data->texture_tower->t_canon_E, sfTrue);
        data->t_data->tab_tower[i]->proj->pos.x += 80;
        data->t_data->tab_tower[i]->proj->pos.y -= 20;
    }
    if (data->t_data->tab_tower[i]->tower == 2 && data\
->t_data->tab_tower[i]->angle == 2) {
        sfSprite_setTexture(data->t_data->tab_tower[i]\
->sprite, data->t_data->texture_tower->t_canon_N, sfTrue);
        data->t_data->tab_tower[i]->proj->pos.x += 80;
        data->t_data->tab_tower[i]->proj->pos.y -= 48;
    }
    change_angle3_2(data, i);
}

void change_angle4(data_t *data, int i)
{
    if (data->t_data->tab_tower[i]->tower == 3 && data->\
t_data->tab_tower[i]->angle == 1) {
        sfSprite_setTexture(data->t_data->tab_tower[i]->\
sprite, data->t_data->texture_tower->t_lazer_E, sfTrue);
        data->t_data->tab_tower[i]->proj->pos.x += 100;
        data->t_data->tab_tower[i]->proj->pos.y -= 20;
        data->t_data->tab_tower[i]->proj->rot = 120;
        sfSprite_setRotation(data->t_data->tab_tower[i]->\
proj->sprite, data->t_data->tab_tower[i]->proj->rot);
    }
    if (data->t_data->tab_tower[i]->tower == 3 && data->\
t_data->tab_tower[i]->angle == 2) {
        sfSprite_setTexture(data->t_data->tab_tower[i]->\
sprite, data->t_data->texture_tower->t_lazer_N, sfTrue);
        data->t_data->tab_tower[i]->proj->pos.x += 70;
        data->t_data->tab_tower[i]->proj->pos.y -= 25;
        data->t_data->tab_tower[i]->proj->rot = 65;
        sfSprite_setRotation(data->t_data->tab_tower[i]\
->proj->sprite, data->t_data->tab_tower[i]->proj->rot);
    }
}

void change_angle5(data_t *data, int i)
{
    if (data->t_data->tab_tower[i]->tower == 3 && data->\
t_data->tab_tower[i]->angle == 3) {
        sfSprite_setTexture(data->t_data->tab_tower[i]->\
sprite, data->t_data->texture_tower->t_lazer_S, sfTrue);
        data->t_data->tab_tower[i]->proj->pos.x += 35;
        data->t_data->tab_tower[i]->proj->pos.y -= 10;
        data->t_data->tab_tower[i]->proj->rot = 245;
        sfSprite_setRotation(data->t_data->tab_tower[i]->\
proj->sprite, data->t_data->tab_tower[i]->proj->rot);
    }
    if (data->t_data->tab_tower[i]->tower == 3 && data->\
t_data->tab_tower[i]->angle == 4) {
        sfSprite_setTexture(data->t_data->tab_tower[i]->\
sprite, data->t_data->texture_tower->t_lazer_W, sfTrue);
        data->t_data->tab_tower[i]->proj->pos.x += 30;
        data->t_data->tab_tower[i]->proj->pos.y -= 30;
        data->t_data->tab_tower[i]->proj->rot = 295;
        sfSprite_setRotation(data->t_data->tab_tower[i]->\
proj->sprite, data->t_data->tab_tower[i]->proj->rot);
    }
}

void change_angle6(data_t *data, int i)
{
    if (data->t_data->tab_tower[i]->tower == 4 && data->t_data->\
tab_tower[i]->angle == 1) {
        sfSprite_setTexture(data->t_data->tab_tower[i]->sprite, \
data->t_data->texture_tower->t_crystal_E, sfTrue);
    }
    if (data->t_data->tab_tower[i]->tower == 4 && data->t_data\
->tab_tower[i]->angle == 2) {
        sfSprite_setTexture(data->t_data->tab_tower[i]->sprite\
, data->t_data->texture_tower->t_crystal_N, sfTrue);
    }
    if (data->t_data->tab_tower[i]->tower == 4 && data->t_data\
->tab_tower[i]->angle == 3) {
        sfSprite_setTexture(data->t_data->tab_tower[i]->sprit\
e, data->t_data->texture_tower->t_crystal_S, sfTrue);
    }
    if (data->t_data->tab_tower[i]->tower == 4 && data->t_da\
ta->tab_tower[i]->angle == 4) {
        sfSprite_setTexture(data->t_data->tab_tower[i]->spri\
te, data->t_data->texture_tower->t_crystal_W, sfTrue);
    }
}

void change_tower_angle(data_t *data, int i)
{
    change_angle1(data, i);
    change_angle2(data, i);
    change_angle3(data, i);
    change_angle4(data, i);
    change_angle5(data, i);
    change_angle6(data, i);
}
