/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** fct
*/


#ifndef FCT_H
#define FCT_H
#include "defender.h"

int gest_error(int ac, char **av);
int help(void);
void disp(data_t *data);

//init_data.c
window_t *init_window(void);
setting_t *init_setting(void);
data_t *init_global_data(void);
g_time_t *init_time(void);

//init_map.c
m_data_t *init_map(data_t *data);

//init_tower.c
proj_t *init_proj(tab_tower_t *data);
tab_tower_t **init_tab_tower(t_data_t *data);
t_data_t *init_tower(void);
texture_tower_t *init_texture_tower(void);
image_tower_t *init_image_tower(void);
tools_tower_t *init_tools_tower(void);

//init_convoy.c
mob_convoy_t *init_convoy(int index);

//update_mob.c
int mob_update(mob_t *mob, sfClock *clock, bool *left_click);

//event_map.c
void event_button_pressed(data_t *data);
void event_resized(data_t *data);
void move_cursor(data_t *data);

//event_tower.c
void click_tower(data_t *data, int i);
void choice_tower(data_t *data, int i);

// start.c
int start(void);

//click_tower.c
void click_tower(data_t *data, int i);
void set_pos_tower(tab_tower_t **new, int i);

//gest_tower.c
void loading_tower(data_t *data);
void loading_tower1(data_t *data, double perc, int i);
void loading_tower2(data_t *data, double perc, int i);
void loading_tower3(data_t *data, double perc, int i);


//disp_tower.c
void disp_tower(data_t *data);

//tower.c A TRIER
void disp_tower_fire(data_t *data);
int range_tower(data_t *data, int i, sfVector2f pos);
void change_tower_angle(data_t *data, int i);
void change_angle(data_t *data, int i, sfVector2f pos);
sfVector2f move(sfVector2f pos, sfVector2f target, float cel);
void anim_proj(data_t *data, int i, sfVector2f pos);
void anim_proj_dot(data_t *data, int i, sfVector2f pos);
int hit_tower(data_t *data, sfVector2f pos);

// animation.c
game_time_t *init_game_time(void);
texture_t *create_texture_struct(sfVector2i tile_size, \
sfTexture *txt, sfVector2i tile_pos, sfVector2f scale);
anim_t *create_animation_struct(anim_t ref);
void texture_time_gestion(anim_t *anim, sfClock *clock, texture_t *txt);

//disp_tower_fire.c
void disp_tower_fire(data_t *data);
int range_tower(data_t *data, int i, sfVector2f pos);
void change_angle1(data_t *data, int i);
void change_angle2(data_t *data, int i);
void change_angle3_2(data_t *data, int i);

//change_angle.c
void change_angle3(data_t *data, int i);
void change_angle4(data_t *data, int i);
void change_angle5(data_t *data, int i);
void change_angle6(data_t *data, int i);
void change_tower_angle(data_t *data, int i);

//move.c
sfVector2f move(sfVector2f pos, sfVector2f target, float cel);
void change_angle(data_t *data, int i, sfVector2f pos);
void set_up_anim_proj3(data_t *data, int i, sfVector2f pos, sfVector2f tmp);
void set_up_anim_proj2(data_t *data, int i, sfVector2f pos, sfVector2f tmp);
void set_up_anim_proj1(data_t *data, int i, sfVector2f pos, sfVector2f tmp);

//anim_proj.c
void anim_proj2(data_t *data, int i, sfVector2f pos, sfVector2f tmp);
void anim_proj(data_t *data, int i, sfVector2f pos);
void anime_proj_dot2(data_t *data, int i, sfVector2f pos);
void anim_proj_dot(data_t *data, int i, sfVector2f pos);
void anime_proj3(data_t *data, int i, sfVector2f pos, sfVector2f tmp);

#endif
