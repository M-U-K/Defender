/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** move
*/

#include "defender.h"

void change_angle(data_t *data, int i, sfVector2f pos)
{
    if (pos.x > data->t_data->tab_tower[i]->pos.x+255 && \
pos.y > data->t_data->tab_tower[i]->pos.y+240)
        data->t_data->tab_tower[i]->angle = 1;
    if (pos.x > data->t_data->tab_tower[i]->pos.x+255 && \
pos.y < data->t_data->tab_tower[i]->pos.y+240)
        data->t_data->tab_tower[i]->angle = 2;
    if (pos.x < data->t_data->tab_tower[i]->pos.x+255 && \
pos.y > data->t_data->tab_tower[i]->pos.y+240)
        data->t_data->tab_tower[i]->angle = 3;
    if (pos.x < data->t_data->tab_tower[i]->pos.x+255 && \
pos.y < data->t_data->tab_tower[i]->pos.y+240)
        data->t_data->tab_tower[i]->angle = 4;
}

sfVector2f move(sfVector2f pos, sfVector2f target, float cel)
{
    float vector[3] = {0, 0, 0};
    float x = 0;
    float y = 0;

    vector[0] = target.x - pos.x;
    vector[1] = target.y - pos.y;
    if (vector[0] != 0 && vector[1] != 0) {
        vector[2] = sqrt(pow(vector[0], 2) + pow(vector[1], 2));
        if (vector[2] > cel) {
            x = vector[0] / (vector[2] / cel);
            y = vector[1] / (vector[2] / cel);
        }
    }
    return ((sfVector2f){x, y});
}

void set_up_anim_proj3(data_t *data, int i, sfVector2f pos, sfVector2f tmp)
{
    if (data->t_data->tab_tower[i]->angle == 2) {
        pos.x += 13;
        pos.y -= 22;
    }
    if (data->t_data->tab_tower[i]->angle == 3) {
        pos.x -= 15;
        pos.y += 15;
    }
    if (data->t_data->tab_tower[i]->angle == 4) {
        pos.x -= 20;
        pos.y -= 0;
    }
}

void set_up_anim_proj1(data_t *data, int i, sfVector2f pos, sfVector2f tmp)
{
    if (data->t_data->tab_tower[i]->tower == 2) {
        pos.x -= 16;
        pos.y -= 10;
    }
    if (data->t_data->tab_tower[i]->tower == 1) {
        if (data->t_data->tab_tower[i]->angle == 1) {
            pos.x += 18;
            pos.y += 5;
        }
        set_up_anim_proj3(data, i, pos, tmp);
    }
}

void set_up_anim_proj2(data_t *data, int i, sfVector2f pos, sfVector2f tmp)
{
    if (data->t_data->tab_tower[i]->tower == 3) {
        if (data->t_data->tab_tower[i]->angle == 1) {
            pos.x += 15;
            pos.y -= 0;
        }
        if (data->t_data->tab_tower[i]->angle == 2) {
            pos.x += 10;
            pos.y -= 15;
        }
        if (data->t_data->tab_tower[i]->angle == 3) {
            pos.x -= 10;
            pos.y += 10;
        }
        if (data->t_data->tab_tower[i]->angle == 4) {
            pos.x -= 15;
            pos.y -= 0;
        }
    }
}