/*
** EPITECH PROJECT, 2020
** Delivery
** File description:
** set_pos_tower
*/

#include "defender.h"

void set_pos_tower1(tab_tower_t **new, int i)
{
    if (new[i]->id == 0)
        new[i]->pos = (sfVector2f) {2175, 800};
    if (new[i]->id == 1)
        new[i]->pos = (sfVector2f) {2563, 860};
    if (new[i]->id == 2)
        new[i]->pos = (sfVector2f) {2430, 1119};
    if (new[i]->id == 3)
        new[i]->pos = (sfVector2f) {2496, 1338};
    if (new[i]->id == 4)
        new[i]->pos = (sfVector2f) {2237, 1467};
    if (new[i]->id == 5)
        new[i]->pos = (sfVector2f) {2367, 1725};
    if (new[i]->id == 6)
        new[i]->pos = (sfVector2f) {1915, 1630};
    if (new[i]->id == 7)
        new[i]->pos = (sfVector2f) {1980, 1920};
    if (new[i]->id == 8)
        new[i]->pos = (sfVector2f) {1660, 1770};
    if (new[i]->id == 9)
        new[i]->pos = (sfVector2f) {1207, 1802};
}

void set_pos_tower2(tab_tower_t **new, int i)
{
    if (new[i]->id == 10)
        new[i]->pos = (sfVector2f) {1145, 1580};
    if (new[i]->id == 11)
        new[i]->pos = (sfVector2f) {630, 1705};
    if (new[i]->id == 12)
        new[i]->pos = (sfVector2f) {372, 1515};
    if (new[i]->id == 13)
        new[i]->pos = (sfVector2f) {307, 1220};
    if (new[i]->id == 14)
        new[i]->pos = (sfVector2f) {502, 1000};
    if (new[i]->id == 15)
        new[i]->pos = (sfVector2f) {305, 772};
    if (new[i]->id == 16)
        new[i]->pos = (sfVector2f) {822, 900};
    if (new[i]->id == 17)
        new[i]->pos = (sfVector2f) {1530, 930};
    if (new[i]->id == 18)
        new[i]->pos = (sfVector2f) {1335, 705};
    if (new[i]->id == 19)
        new[i]->pos = (sfVector2f) {1790, 803};
}

void set_pos_tower(tab_tower_t **new, int i)
{
    set_pos_tower1(new, i);
    set_pos_tower2(new, i);
    new[i]->pos.x += 33;
    new[i]->pos.y += 34;
}
