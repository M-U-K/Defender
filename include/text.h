/*
** EPITECH PROJECT, 2019
** Test
** File description:
** text.h
*/

#ifndef TEXT_H
#define TEXT_H

#include "global_struct.h"

#define FONT_ID_LEN 3

typedef enum {
    FONT1,
    FONT2,
    FONT3,
} font_id_e;

typedef struct {
    font_id_e id;
    char const *path;
} font_prefab_t;

extern const font_prefab_t fonts_prefab[];

sfFont **initialize_fonts(void);

typedef struct text_s {
    char *name;
    tag_e *tag;
    bool is_active;
    char *str;
    sfText *text;
    sfRenderStates *states;
    struct text_s *next;
} text_t;

text_t *create_new_text(char *name, tag_e *tag);
void set_text_status\
(text_t *text, sfFont *font\
, sfVector2f pos, const char *str);
void set_text_properties\
(text_t *text, unsigned int size\
, sfColor color, sfUint32 style);

#endif