/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** tower
*/

#include "csfml.h"

#ifndef TOWER_H
#define TOWER_H

typedef struct proj_s
{
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f dest;
    sfVector2f pos_save;
    int active;
    int act;
    float rot;
    double speed;
    double speed2;
    double rate;
    double past_time;
    double actual_time;
    double diff_time;
    double diff_time2;
    double diff_time_speed;

}proj_t;

typedef struct tab_tower_s
{
    int id;
    int act;
    int tower;
    int angle;
    int on_fire;
    int dommage;
    int dommage_return;
    double range;
    sfSprite *sprite;
    sfSprite *loading_black_sprite;
    sfSprite *loading_blue_sprite;
    sfSprite *canon;
    sfSprite *lazer;
    sfSprite *baliste;
    sfSprite *crystal;
    sfFloatRect globalBounds;
    double speed;
    double past_time;
    double actual_time;
    double diff_time;
    double diff_time_speed;
    sfVector2f pos;
    proj_t *proj;
}tab_tower_t;

typedef struct texture_tower_s
{
    sfTexture *fire;
    sfTexture *arrow;
    sfTexture *lazer;
    sfTexture *canonball;
    sfTexture *tower_base;
    sfTexture *tower_build1;
    sfTexture *tower_build2;
    sfTexture *choice_crystal;
    sfTexture *choice_canon;
    sfTexture *choice_lazer;
    sfTexture *choice_baliste;
    sfTexture *loading;
    sfTexture *t_crystal_E;
    sfTexture *t_crystal_N;
    sfTexture *t_crystal_S;
    sfTexture *t_crystal_W;
    sfTexture *t_baliste_E;
    sfTexture *t_baliste_N;
    sfTexture *t_baliste_S;
    sfTexture *t_baliste_W;
    sfTexture *t_canon_E;
    sfTexture *t_canon_N;
    sfTexture *t_canon_S;
    sfTexture *t_canon_W;
    sfTexture *t_lazer_E;
    sfTexture *t_lazer_N;
    sfTexture *t_lazer_S;
    sfTexture *t_lazer_W;
}texture_tower_t;

typedef struct image_tower_s
{
    sfImage *tower_base;
    sfImage *tower_build1;
    sfImage *tower_build2;
}image_tower_t;

typedef struct tools_tower_s
{
    sfColor color_pixel;
}tools_tower_t;

typedef struct tower_data_s
{
    tools_tower_t *tools_tower;
    tab_tower_t **tab_tower;
    texture_tower_t *texture_tower;
    image_tower_t *image_tower;
}t_data_t;

#endif
