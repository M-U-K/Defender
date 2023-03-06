/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** defender.h
*/

#include "text.h"
#include "math.h"
#include "tower.h"
#include "utils.h"
#include "csfml.h"
#include "fct.h"
#include "mob.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#ifndef DEFENDER_H
#define DEFENDER_H

typedef enum {
    GS_MENU,
    GS_GAME,
    GS_PAUSE
} game_status_e;

typedef struct {
    int count;
    int index;
    mob_t *mobs;
} mob_convoy_t;

extern const int convoy_count[];

typedef struct global_time_s
{
    sfClock *clock;
    double game_speed;
}g_time_t;

typedef struct window_s
{
    sfRenderWindow *r_window;
    sfVector2u org_size;
    double resize_x;
    double resize_y;
    double window_x;
    double window_y;
    double org_window_x;
    double org_window_y;
}window_t;

typedef struct cursor_s
{
    sfSprite *sprite_cursor;
    sfVector2i pos_cursor_onWindow;
    sfVector2f pos_cursor_onMap;
    int sensi_move_map;
    int act_mouse;
}cursor_t;

typedef struct music_s
{
    int actual_music;
    //sfMusic *'nom de musique'
}music_t;

typedef struct sound_s
{
    int actual_sound;
    //sfMusic *'nom de son'
}sound_t;

typedef struct audio_s
{
    music_t *music;
    sound_t *sound;
}audio_t;

typedef struct setting_s
{
    window_t *window;
    cursor_t *cursor;
    audio_t *audio;
    g_time_t *time;
    sfEvent event;
}setting_t;

typedef struct map_data_s
{
    sfTexture *texture_map;
    sfSprite *sprite_map;
    sfVector2u size_map;
    sfVector2i center_map;
    sfVector2i t_map;
    sfVector2i t_diff_map;
    sfVector2f move_center_map;
    sfView *view;
}m_data_t;

typedef struct global_data_s
{
    game_status_e game_status;
    t_data_t *t_data;
    m_data_t *m_data;
    setting_t *setting;
    mob_convoy_t *convoy;
}data_t;

#endif