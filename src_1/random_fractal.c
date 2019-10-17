/*
** EPITECH PROJECT, 2017
** my_screensaver
** File description:
** random_fractal.c
*/

#include "my_screensaver.h"

var_t *init_var()
{
	var_t *var = malloc(sizeof(var_t));

	var->Max_it = 10;
	var->MinRe = -2.5109;
	var->MaxRe = 2.5778;
	var->MinIm = -1.402;
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

int random_fractal(void)
{
	srand(time(NULL));
	var_t *var = init_var();
	double a[15] = { -0.101, -0.63, 0.35, -0.76, -2, 0.3, 0.285, -0.038088,
		1, -0.8, -0.8 };
	double b[15] = { 0.956, 0.67, 0.05, 0.12, 0, 0.5, 0.01, 0.97, 0.0,
		0.6, 0.2 };
	int inc = rand() % 11;

	var->a = a[inc];
	var->b = b[inc];
	return (screen_1(var));
}
