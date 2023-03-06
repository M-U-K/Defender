/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** init_texture_tower
*/

#include "defender.h"

void init_texture_tower1(texture_tower_t *new)
{
    new->t_baliste_N = sfTexture_createFromFile("te\
xture/tower/towerBaliste.N.png", NULL);
    new->t_baliste_S = sfTexture_createFromFile("te\
xture/tower/towerBaliste.S.png", NULL);
    new->t_baliste_E = sfTexture_createFromFile("te\
xture/tower/towerBaliste.E.png", NULL);
    new->t_baliste_W = sfTexture_createFromFile("te\
xture/tower/towerBaliste.W.png", NULL);
    new->t_canon_N = sfTexture_createFromFile("text\
ure/tower/towerCanon.N.png", NULL);
    new->t_canon_S = sfTexture_createFromFile("text\
ure/tower/towerCanon.S.png", NULL);
    new->t_canon_E = sfTexture_createFromFile("text\
ure/tower/towerCanon.E.png", NULL);
    new->t_canon_W = sfTexture_createFromFile("text\
ure/tower/towerCanon.W.png", NULL);
    new->t_lazer_N = sfTexture_createFromFile("text\
ure/tower/towerLazer.N.png", NULL);
    new->t_lazer_S = sfTexture_createFromFile("text\
ure/tower/towerLazer.S.png", NULL);
}

void init_texture_tower2(texture_tower_t *new)
{
    new->t_lazer_E = sfTexture_createFromFile("text\
ure/tower/towerLazer.E.png", NULL);
    new->t_lazer_W = sfTexture_createFromFile("text\
ure/tower/towerLazer.W.png", NULL);
    new->t_crystal_N = sfTexture_createFromFile("te\
xture/tower/towerCrystal.N.png", NULL);
    new->t_crystal_S = sfTexture_createFromFile("te\
xture/tower/towerCrystal.S.png", NULL);
    new->t_crystal_E = sfTexture_createFromFile("te\
xture/tower/towerCrystal.E.png", NULL);
    new->t_crystal_W = sfTexture_createFromFile("te\
xture/tower/towerCrystal.W.png", NULL);
    new->lazer = sfTexture_createFromFile("texture/\
tools/lazer_ammo.png", NULL);
    new->canonball = sfTexture_createFromFile("text\
ure/tools/canonball.png", NULL);
    new->arrow = sfTexture_createFromFile("texture/\
tools/arrow.png", NULL);
    new->fire = sfTexture_createFromFile("texture/\
tools/fire.png", NULL);
}

texture_tower_t *init_texture_tower(void)
{
    texture_tower_t *new = malloc(sizeof(texture_tower_t));
    new->tower_base = sfTexture_createFromFile("tex\
ture/tower/towerBaseVoid.png", NULL);
    new->tower_build1 = sfTexture_createFromFile("t\
exture/tower/towerBuild1.png", NULL);
    new->tower_build2 = sfTexture_createFromFile("t\
exture/tower/towerBuild2.png", NULL);
    new->loading = sfTexture_createFromFile("textur\
e/tools/life.png", NULL);
    new->choice_baliste = sfTexture_createFromFile(\
"texture/tools/baliste.png", NULL);
    new->choice_canon = sfTexture_createFromFile("t\
exture/tools/canon.png", NULL);
    new->choice_lazer = sfTexture_createFromFile("t\
exture/tools/lazer.png", NULL);
    new->choice_crystal = sfTexture_createFromFile(\
"texture/tools/crystal.png", NULL);
    init_texture_tower1(new);
    init_texture_tower2(new);
    return (new);
}

image_tower_t *init_image_tower(void)
{
    image_tower_t *new = malloc(sizeof(image_tower_t));
    new->tower_base = sfImage_createFromFile("texture/tower/towerBase.png");
    new->tower_build1 = sfImage_createFromFile("texture/tower/towerBuild1.png");
    new->tower_build2 = sfImage_createFromFile("texture/tower/towerBuild2.png");
    return (new);
}

proj_t *init_proj(tab_tower_t *data)
{
    proj_t *new = malloc(sizeof(proj_t));
    new->sprite = sfSprite_create();
    new->speed = 1;
    new->past_time = 0;
    new->actual_time = 0;
    new->diff_time = 0;
    new->diff_time2 = 0;
    new->diff_time_speed = 0;
    new->pos = data->pos;
    new->pos_save = new->pos;
    new->act = 0;
    return (new);
}