/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** node.c
*/

#include "node.h"

void add_text_in_node(node_t *node, text_t *text)
{
    text->next = node->texts_list;
    node->texts_list = text;
    sfTransform_combine(&(text->states->transform), &(node->states->transform));
}