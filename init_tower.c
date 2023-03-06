/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** init_tower
*/

#include "defender.h"



void init_tab_tower2(t_data_t *data, tab_tower_t **new, int i)
{
    sfSprite_setPosition(new[i]->crystal, (sfVector2f) \
{new[i]->pos.x + 110, new[i]->pos.y + 100});
    sfSprite_setTexture(new[i]->baliste, data->texture_\
tower->choice_baliste, sfTrue);
    sfSprite_setTexture(new[i]->canon, data->texture_tower\
->choice_canon, sfTrue);
    sfSprite_setTexture(new[i]->lazer, data->texture_tower\
->choice_lazer, sfTrue);
    sfSprite_setTexture(new[i]->crystal, data->texture_tower\
->choice_crystal, sfTrue);
    sfSprite_setTexture(new[i]->sprite, data->texture_tower\
->tower_base, sfTrue);
    sfSprite_setTexture(new[i]->loading_blue_sprite, data\
->texture_tower->loading, sfTrue);
    sfSprite_setTextureRect(new[i]->loading_blue_sprite, \
(sfIntRect) {0, 23, 0, 23});
    sfSprite_setTexture(new[i]->loading_black_sprite, data\
->texture_tower->loading, sfTrue);
    sfSprite_setTextureRect(new[i]->loading_black_sprite, \
(sfIntRect) {0, 0, 129, 23});
}

void init_tab_tower3(t_data_t *data, tab_tower_t **new, int i)
{
    new[i]->sprite = sfSprite_create();
    new[i]->loading_black_sprite = sfSprite_create();
    new[i]->loading_blue_sprite = sfSprite_create();
    new[i]->baliste = sfSprite_create();
    new[i]->canon = sfSprite_create();
    new[i]->lazer = sfSprite_create();
    new[i]->crystal = sfSprite_create();
    new[i]->globalBounds = sfSprite_getGlobalBounds(new[i]->sprite);
    set_pos_tower(new, i);
    sfSprite_setPosition(new[i]->sprite, new[i]->pos);
    sfSprite_setPosition(new[i]->loading_blue_sprite, \
(sfVector2f) {new[i]->pos.x, new[i]->pos.y+120});
    sfSprite_setPosition(new[i]->loading_black_sprite, \
(sfVector2f) {new[i]->pos.x, new[i]->pos.y+120});
    sfSprite_setPosition(new[i]->baliste, (sfVector2f) \
{new[i]->pos.x - 70, new[i]->pos.y - 50});
    sfSprite_setPosition(new[i]->canon, (sfVector2f) \
{new[i]->pos.x - 70, new[i]->pos.y + 100});
    sfSprite_setPosition(new[i]->lazer, (sfVector2f) \
{new[i]->pos.x + 110, new[i]->pos.y - 50});
}

tab_tower_t **init_tab_tower(t_data_t *data)
{
    tab_tower_t **new = malloc(sizeof(tab_tower_t) * 20);

    for (int i = 0; i != 20; i++) {
        new[i] = malloc(sizeof(tab_tower_t));
        new[i]->id = i;
        new[i]->act = 0;
        new[i]->tower = 0;
        new[i]->speed = 1;
        new[i]->past_time = 0;
        new[i]->actual_time = 0;
        new[i]->diff_time = 0;
        new[i]->angle = 0;
        new[i]->diff_time_speed = 0;
        new[i]->dommage_return = 0;
        init_tab_tower3(data, new, i);
        init_tab_tower2(data, new, i);
        new[i]->proj = init_proj(new[i]);
    }
    return (new);
}

tools_tower_t *init_tools_tower(void)
{
    tools_tower_t *new = malloc(sizeof(tools_tower_t));
    return (new);
}

t_data_t *init_tower(void)
{
    t_data_t *new = malloc(sizeof(t_data_t));
    new->texture_tower = init_texture_tower();
    new->tools_tower = init_tools_tower();
    new->image_tower = init_image_tower();
    new->tab_tower = init_tab_tower(new);

    return (new);
}