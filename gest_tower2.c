/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** gest_tower2
*/

#include "defender.h"

void loading_tower1(data_t *data, double perc, int i)
{
    if (data->t_data->tab_tower[i]->tower == 4) {
        data->t_data->tab_tower[i]->pos.x -= 166;
        data->t_data->tab_tower[i]->pos.y -= 203;
        data->t_data->tab_tower[i]->dommage = 10;
        data->t_data->tab_tower[i]->range = 200;
        data->t_data->tab_tower[i]->proj->speed2 = 500;
        data->t_data->tab_tower[i]->proj->rate = 1000;
        sfSprite_setPosition(data->t_data->tab_tower[i]\
->sprite, data->t_data->tab_tower[i]->pos);
        sfSprite_setTexture(data->t_data->tab_tower[i]\
->sprite, data->t_data->texture_tower->t_crystal_E, sfTrue);
    }
}

void loading_tower2(data_t *data, double perc, int i)
{
    if (data->t_data->tab_tower[i]->tower == 3) {
        data->t_data->tab_tower[i]->pos.x -= 166;
        data->t_data->tab_tower[i]->pos.y -= 203;
        data->t_data->tab_tower[i]->dommage = 500;
        data->t_data->tab_tower[i]->range = 1000;
        data->t_data->tab_tower[i]->proj->speed2 = 1;
        data->t_data->tab_tower[i]->proj->rate = 500;
        sfSprite_setPosition(data->t_data->tab_tower[i]\
->sprite, data->t_data->tab_tower[i]->pos);
        sfSprite_setTexture(data->t_data->tab_tower[i]\
->sprite, data->t_data->texture_tower->t_lazer_E, sfTrue);
    }
}

void loading_tower3(data_t *data, double perc, int i)
{
    if (data->t_data->tab_tower[i]->tower == 2) {
        data->t_data->tab_tower[i]->pos.x -= 166;
        data->t_data->tab_tower[i]->pos.y -= 203;
        data->t_data->tab_tower[i]->dommage = 300;
        data->t_data->tab_tower[i]->range = 300;
        data->t_data->tab_tower[i]->proj->speed2 = 5;
        data->t_data->tab_tower[i]->proj->rate = 1000;
        sfSprite_setPosition(data->t_data->tab_tower[i]\
->sprite, data->t_data->tab_tower[i]->pos);
        sfSprite_setTexture(data->t_data->tab_tower[i]\
->sprite, data->t_data->texture_tower->t_canon_E, sfTrue);
    }
}