/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** animation.c
*/

#include "defender.h"

game_time_t *init_game_time(void)
{
    game_time_t *new = malloc(sizeof(game_time_t));

    new->actual = 0;
    new->dif = 0;
    new->last = 0;
    return (new);
}

texture_t *create_texture_struct(sfVector2i tile_size, \
sfTexture *txt, sfVector2i tile_pos, sfVector2f scale)
{
    texture_t *new = malloc(sizeof(texture_t));
    sfVector2u txt_size = sfTexture_getSize(txt);

    if (new == NULL)
        return (print_error("ERROR: Can't create a new texture\n"), NULL);
    new->tile_rect = \
(sfIntRect){tile_pos.x, tile_pos.y, tile_size.x, tile_size.y};
    new->tile_size = tile_size;
    new->txt_size.x = txt_size.x;
    new->txt_size.y = txt_size.y;
    new->repeat = sfFalse;
    new->scale.x = scale.x;
    new->scale.y = scale.y;
    return (new);
}

anim_t *create_animation_struct(anim_t ref)
{
    anim_t *new = malloc(sizeof(anim_t));

    if (new == NULL)
        return (print_error("ERROR: Can't create a new animation\n"), NULL);
    new->is_loop = ref.is_loop;
    new->is_anim = ref.is_anim;
    new->loop_time = ref.loop_time;
    new->anim_time = ref.anim_time;
    new->rect_pos = ref.rect_pos;
    new->rect_move = ref.rect_move;
    new->rect_max = ref.rect_max;
    new->time = init_game_time();
    return (new);
}

void move_texture_rect(anim_t *anim)
{
    if (anim->rect_pos < anim->rect_max - anim->rect_move)
        anim->rect_pos += anim->rect_move;
    else if (anim->is_loop == false || anim->loop_time != 0) {
        anim->is_anim = false;
        anim->rect_pos = 0;
    } else
        anim->rect_pos = 0;
    anim->time->dif = 0;
}

void texture_time_gestion(anim_t *anim, sfClock *clock, texture_t *txt)
{
    if (anim->is_anim == false && anim->is_loop == false)
        return;
    anim->time->last = anim->time->actual;
    anim->time->actual = sfTime_asSeconds(sfClock_getElapsedTime(clock));
    anim->time->dif += anim->time->actual - anim->time->last;
    if (anim->is_anim == false && anim->loop_time != 0) {
        if (anim->time->dif < anim->loop_time)
            return;
        else
            anim->is_anim = true;
    }
    if (anim->time->dif >= anim->anim_time)
        move_texture_rect(anim);
    txt->tile_rect.left = anim->rect_pos;
}