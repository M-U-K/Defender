/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** update_mob.c
*/

#include "defender.h"
void mob_update2(mob_t *mob, sfClock *clock, bool *left_click, sfVector2f move)
{
    if (move.x > 0 && move.y > 0 && mob->statut != MOBS_MOVE_BR) {
        mob->statut = MOBS_MOVE_BR;
        mob->txt->tile_rect.top = 840;
        mob->anim->rect_pos = 0;
    }
    else if (move.x > 0 && move.y < 0 && mob->statut != MOBS_MOVE_TR) {
        mob->statut = MOBS_MOVE_TR;
        mob->txt->tile_rect.top = 720;
        mob->anim->rect_pos = 0;
    }
    else if (move.x < 0 && move.y > 0 && mob->statut != MOBS_MOVE_BL) {
        mob->statut = MOBS_MOVE_BL;
        mob->txt->tile_rect.top = 480;
        mob->anim->rect_pos = 0;
    }
    else if (move.x < 0 && move.y < 0 && mob->statut != MOBS_MOVE_TL) {
        mob->statut = MOBS_MOVE_TL;
        mob->txt->tile_rect.top = 600;
        mob->anim->rect_pos = 0;
    }
}

int mob_update(mob_t *mob, sfClock *clock, bool *left_click)
{
    sfVector2f move;

    if (mob->spr == NULL)
        return (0);
    move = move_transform_to_point(mob->spr, mob->points_list, clock);
    if (mob->statut != MOBS_ATT) {
        mob_update2(mob, clock, left_click, move);
    }
    if (mob->points_list->actual == NULL || mob->vit <= 0) {
        mob->spr = NULL;
        return (1);
    }
    texture_time_gestion(mob->anim, clock, mob->txt);
    sfSprite_setTextureRect(mob->spr, mob->txt->tile_rect);
    sfSprite_move(mob->spr, move);
    return (0);
}