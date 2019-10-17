/*
** EPITECH PROJECT, 2017
** my_screensaver
** File description:
** zoom_mande.c
*/

#include "my_screensaver.h"

var_t *init_var_3()
{
	var_t *var = malloc(sizeof(var_t));

	var->Max_it = 90;
	var->MinRe = -2.0;
	var->MaxRe = 1.0;
	var->MinIm = -1.2;
	var->MaxIm = var->MinIm + (var->MaxRe - var->MinRe) * 1080/1920;
	var->Re_factor = (var->MaxRe - var->MinRe) / (1920-1);
	var->Im_factor = (var->MaxIm - var->MinIm) / (1080-1);
	var->n = 0;
	return (var);
}

int_t *init_tools(void)
{
	int_t *tools = malloc(sizeof(int_t));

	tools->interrupt = 0;
	tools->counter = 1;
	return (tools);
}
