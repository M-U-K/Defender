/*
** EPITECH PROJECT, 2019
** anim
** File description:
** global_data.h
*/

#ifndef GLOBAL_DATA_H
#define GLOBAL_DATA_H

#include "csfml.h"

#include <stdbool.h>

typedef enum {
    TAG_END,
    TAG_NONE
} tag_e;

// Gestion du temps
typedef struct time_s {
    float actual;
    float last;
    float dif;
} game_time_t;

// Gestion de la texture d'un object
typedef struct texture_s {
    sfIntRect tile_rect;
    sfVector2i tile_size;
    sfVector2i txt_size;
    sfVector2f scale;
    sfBool repeat;
} texture_t;

// Gestion de l'animation de la texture
typedef struct object_animation {
    bool is_loop;
    bool is_anim;
    float loop_time;
    float anim_time;
    int rect_pos;
    int rect_move;
    int rect_max;
    game_time_t *time;
} anim_t;

/* Function to animate a sprite */
void texture_time_gestion(anim_t *anim, sfClock *clock, texture_t *txt);

#endif