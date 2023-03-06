/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** event_map
*/

#include "defender.h"

void move_cursor(data_t *data)
{
    data->m_data->move_center_map = sfView_getCenter(data->m_data->view);
    data->m_data->t_map = sfMouse_getPositionRenderWindow\
(data->setting->window->r_window);
    while (sfMouse_isButtonPressed(sfMouseLeft)) {
        data->m_data->t_diff_map = sfMouse_getPositionRenderWindow\
(data->setting->window->r_window);
        data->m_data->center_map.x = ((data->m_data->t_diff_map.x \
- data->m_data->t_map.x)*data->setting->cursor->sensi_move_map);
        data->m_data->center_map.y = ((data->m_data->t_diff_map.y \
- data->m_data->t_map.y)*data->setting->cursor->sensi_move_map);
        sfView_setCenter(data->m_data->view, (sfVector2f) {data->\
m_data->move_center_map.x + data->m_data->center_map.x, data->m_d\
ata->move_center_map.y + data->m_data->center_map.y});
        sfRenderWindow_setView(data->setting->window->r_window, \
data->m_data->view);
        disp(data);
    }
}

void event_button_pressed(data_t *data)
{
    if (data->setting->event.type == sfEvtMouseButtonPressed) {
        data->setting->cursor->pos_cursor_onWindow = sfMouse_get\
PositionRenderWindow(data->setting->window->r_window);
        data->setting->cursor->pos_cursor_onMap = sfRenderWindow_\
mapPixelToCoords(data->setting->window->r_window, data->setting->\
cursor->pos_cursor_onWindow, data->m_data->view);
        for (int i = 0; i != 20; i++) {
            choice_tower(data, i);
            click_tower(data, i);
        }
        if (data->setting->cursor->act_mouse == 0)
            move_cursor(data);
    }
    data->setting->cursor->act_mouse = 0;
}

void event_resized(data_t *data)
{
    if (data->setting->event.type == sfEvtResized) {
        data->m_data->size_map.x = data->setting->event.size.width;
        data->m_data->size_map.y = data->setting->event.size.height;
        sfView_setSize(data->m_data->view, (sfVector2f) {data->\
m_data->size_map.x, data->m_data->size_map.y});
        sfRenderWindow_setView(data->setting->window->r_window, \
data->m_data->view);
    }
}