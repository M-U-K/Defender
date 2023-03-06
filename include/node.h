/*
** EPITECH PROJECT, 2019
** Test
** File description:
** canvas.h
*/

#ifndef NODE_H
#define NODE_H

#include "csfml.h"
#include "text.h"
#include "global_struct.h"

typedef struct node_s {
    sfCircleShape *point;

    char *name;
    bool is_active;
    sfRenderStates *states;

// Add chained list

    text_t *texts_list;

// ----------------

    struct node_s *next;
} node_t;

node_t *create_node(node_t *next, char *name, tag_e *tags, sfVector2f pos);

void translate_node(node_t *node, float x, float y);
void print_node(node_t *node, sfRenderWindow *rwindow);
void display_node_list(node_t *first_node);

void add_text_in_node(node_t *node, text_t *text);

#endif