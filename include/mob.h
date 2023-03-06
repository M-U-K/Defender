/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** mob.h
*/

#ifndef MOB_H
#define MOB_H

#include "global_struct.h"
#include "points_list.h"

typedef enum {
    MOBS_NONE,
    MOBS_DIED,
    MOBS_ATT,
    MOBS_MOVE_TR,
    MOBS_MOVE_BR,
    MOBS_MOVE_TL,
    MOBS_MOVE_BL
} mob_statut_e;

typedef struct mob_s {
    sfSprite *spr;
    mob_statut_e statut;
    sfTransformable *transform;
    points_list_t *points_list;
    anim_t *anim;
    texture_t *txt;
    int vit;
    struct mob_s *next;
} mob_t;

#endif