/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** init_map
*/

#include "defender.h"

m_data_t *init_map(data_t *data)
{
    m_data_t *new = malloc(sizeof(m_data_t));
    new->texture_map = sfTexture_createFromFile("texture/map.png", NULL);
    new->sprite_map = sfSprite_create();
    new->size_map = sfRenderWindow_getSize(data->setting->window->r_window);
    new->center_map = (sfVector2i) {2000, 800};
    new->view = sfView_createFromRect((sfFloatRect) \
{new->center_map.x, new->center_map.y, new->size_map.x, new->size_map.y});
    new->t_map = (sfVector2i) {0, 0};
    new->t_diff_map = (sfVector2i) {0, 0};
    new->move_center_map = (sfVector2f) {0, 0};
    sfSprite_setTexture(new->sprite_map, new->texture_map, sfTrue);
    return (new);
}