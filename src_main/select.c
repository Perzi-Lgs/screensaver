/*
** EPITECH PROJECT, 2017
** my_screensaver
** File description:
** select.c
*/

#include "my_screensaver.h"

void select_screen(char *str)
{
	int (*fct_ptr[4])(void) = { random_fractal, fract_move, zoom_mande };

	fct_ptr[str[0] - '1']();
}
