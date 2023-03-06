/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** init_convoy.c
*/

#include "defender.h"

const sfVector2f path1[] = {
    {2563, 860},
    {2523, 945},
    {2280, 820},
    {2140, 880},
    {2080, 850},
    {1890, 945},
    {1570, 790},
    {1380, 885},
    {1550, 980},
    {1425, 1045},
    {1050, 860},
    {860, 950},
    {600, 830},
    {350, 955},
    {515, 1050},
    {480, 1090},
    {580, 1150},
    {415, 1240},
    {540, 1310},
    {350, 1400},
    {520, 1500},
    {490, 1550},
    {700, 1650},
    {700, 1710},
    {850, 1790},
    {720, 1860}
};

const sfVector2f path2[] = {
    {2563, 860},
    {2523, 945},
    {2790, 1075},
    {2580, 1160},
    {2400, 1080},
    {2280, 1140},
    {2660, 1330},
    {2400, 1460},
    {2510, 1510},
    {2480, 1560},
    {2720, 1680},
    {2520, 1780},
    {2280, 1650},
    {2020, 1780},
    {2270, 1910},
    {2130, 1975},
    {1910, 1850},
    {1620, 1985},
    {1370, 1860},
    {1485, 1790},
    {1310, 1695},
    {980, 1850},
    {850, 1790},
    {720, 1860}
};

const int convoy_count[] = {
    6,
    12,
    20,
    30
};

void create_mob2(mob_t *mob, int index, float wait)
{
    if (index == 0) {
        for (int ctr = 0; ctr < 25; ctr += 1)
            create_new_point(mob->points_list, path1[ctr], wait, 0.05);
        create_new_point(mob->points_list, path1[25], wait, 0.05);
    }
    else {
        for (int ctr = 0; ctr < 23; ctr += 1)
            create_new_point(mob->points_list, path2[ctr], wait, 0.05);
        create_new_point(mob->points_list, path2[23], wait, 0.05);
    }
}

mob_t *create_mob(mob_t *next, sfTexture *txt, int index, float wait)
{
    mob_t *mob = malloc(sizeof(mob_t));

    mob->spr = sfSprite_create();
    sfSprite_setTexture(mob->spr, txt, sfTrue);
    mob->statut = MOBS_NONE;
    mob->vit = 2000;
    mob->anim = create_animation_struct((anim_t){true, true, \
0, 0.04, 0, 120, 2400, NULL});
    mob->txt = create_texture_struct((sfVector2i){120, 120}, txt, \
(sfVector2i){0, 480}, (sfVector2f){0.5, 0.5});
    sfSprite_setOrigin(mob->spr, (sfVector2f){60, 60});
    mob->transform = sfTransformable_create();
    sfTransformable_setPosition(mob->transform, (sfVector2f){0, 0});
    sfSprite_setPosition(mob->spr, (sfVector2f){2700, 860});
    mob->points_list = create_a_points_list(-1);
    create_mob2(mob, index, wait);
    mob->next = next;
    return (mob);
}

mob_t *create_convoy(sfTexture *txt, int index, int count)
{
    mob_t *first = NULL;
    float wait = 0;

    for (int ctr = 0; ctr < count; ctr += 1) {
        first = create_mob(first, txt, index, wait);
        wait += 2;
    }
    return (first);
}

mob_convoy_t *init_convoy(int index)
{
    mob_convoy_t *convoy = malloc(sizeof(mob_convoy_t));
    sfTexture *txt = sfTexture_createFromFile("Soldier.png", NULL);
    int random = rand() % 2;

    convoy->index = index;
    convoy->count = convoy_count[index - 1];
    if (random == 1)
        convoy->mobs = create_convoy(txt, 1, convoy_count[0]);
    else
        convoy->mobs = create_convoy(txt, 0, convoy_count[0]);
    return (convoy);
}