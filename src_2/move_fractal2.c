/*
** EPITECH PROJECT, 2017
** my_screensaver
** File description:
** move_fractal.c
*/

#include "my_screensaver.h"

var_t *init_var_2()
{
	var_t *var = malloc(sizeof(var_t));

	var->Max_it = 50;
	var->MinRe = -2.5249;
	var->MaxRe = 2.5078;
	var->MinIm = -1.452;
	var->MaxIm = var->MinIm + (var->MaxRe - var->MinRe) * 1080/1920;
	var->Re_factor = (var->MaxRe - var->MinRe) / (1920-1);
	var->Im_factor = (var->MaxIm - var->MinIm) / (1080-1);
	var->n = 0;
	var->a = 0;
	var->b = -1;
	var->c = 0;
	var->d = 0;
	return (var);
}
