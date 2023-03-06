/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** main.c
*/

#include "defender.h"

int gest_error(int ac, char **av)
{
    (void)ac;
    (void)av;
    return (0);
}

int help(void)
{
    return (0);
}

int main(int ac, char **av)
{
    srand(time(NULL));
    if (ac == 2)
        if (cmp_string(av[1], "-h") != 0)
            help();
    if (gest_error(ac, av))
        return (84);
    if (ac == 1)
        start();
    return (0);
}