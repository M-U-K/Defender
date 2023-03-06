/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** start.c
*/

#include "defender.h"

void display(sfRenderWindow *rwindow, sfSprite *spr, sfTransformable *transform)
{
    sfRenderStates states;

    states.blendMode = sfBlendAlpha;
    states.shader = NULL;
    states.texture = NULL;
    states.transform = sfTransformable_getTransform(transform);
    if (spr != NULL)
        sfRenderWindow_drawSprite(rwindow, spr, &states);
}

void disp(data_t *data)
{
    sfRenderWindow_clear(data->setting->window->r_window, sfBlack);
    loading_tower(data);
    sfRenderWindow_drawSprite(data->setting->window->r_window, \
data->m_data->sprite_map, NULL);
    disp_tower_fire(data);
    for (mob_t *tmp = data->convoy->mobs; tmp != NULL; tmp = tmp->next) {
        if (tmp->spr != NULL)
            tmp->vit -= hit_tower(data, sfSprite_getPosition(tmp->spr));
        data->convoy->count -= mob_update(tmp, data->setting->\
time->clock, NULL);
        display(data->setting->window->r_window, tmp->spr, tmp->transform);
    }
    if (data->convoy->count <= 0 && data->convoy->count < 4) {
        data->convoy->index += 1;
        data->convoy = init_convoy(data->convoy->index);
    }
    sfRenderWindow_display(data->setting->window->r_window);
}

void event_closed(data_t *data)
{
    if (data->setting->event.type == sfEvtClosed)
        sfRenderWindow_close(data->setting->window->r_window);
}

int start(void)
{
    data_t *data = init_global_data();

    sfRenderWindow_setFramerateLimit(data->setting->window->r_window, 60);
    sfRenderWindow_setView(data->setting->window->r_window, data->m_data->view);
    while (sfRenderWindow_isOpen(data->setting->window->r_window)) {
        while (sfRenderWindow_pollEvent(data->setting->window->r_window\
, &data->setting->event)) {
            event_button_pressed(data);
            event_resized(data);
            event_closed(data);
        }
        disp(data);
    }
    return (0);
}