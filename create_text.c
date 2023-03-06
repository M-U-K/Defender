/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** create_text.c
*/

#include "text.h"

void set_text_properties\
(text_t *text, unsigned int size\
, sfColor color, sfUint32 style)
{
    sfText_setCharacterSize(text->text, size);
    sfText_setColor(text->text, color);
    sfText_setStyle(text->text, style);
}

void set_text_status\
(text_t *text, sfFont *font\
, sfVector2f pos, const char *str)
{
    text->states = malloc(sizeof(sfRenderStates));
    if (text->states == NULL)
        return;
    text->states->transform = sfTransform_Identity;
    sfTransform_translate(&(text->states->transform), pos.x, pos.y);
    text->states->blendMode = sfBlendAlpha;
    text->states->texture = NULL;
    text->states->shader = NULL;
    text->text = sfText_create();
    text->str = string_dup(str);
    sfText_setFont(text->text, font);
    sfText_setString(text->text, text->str);
}

text_t *create_new_text(char *name, tag_e *tag)
{
    text_t *new = malloc(sizeof(text_t));

    if (new == NULL)
        return (print_error("Error: Can't create a text.\n"), NULL);
    new->name = string_dup(name);
    new->tag = tag;
    new->next = NULL;
    return (new);
}