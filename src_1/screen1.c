/*
** EPITECH PROJECT, 2017
** my_screensaver
** File description:
** screen_1.c
*/

#include "my_screensaver.h"

void fractal1_2(var_t *var)
{
	while(var->n < var->Max_it) {
		var->Z_re2 = var->Z_re * var->Z_re;
		var->Z_im2 = var->Z_im * var->Z_im;
		if(var->Z_re2 + var->Z_im2 > 4)
			break;
		var->Z_im = 2 * var->Z_re * var->Z_im - var->b;
		var->Z_re = var->Z_re2 - var->Z_im2 + var->a;
		var->n++;
	}
}

void fractal1(var_t *var, unsigned int y, window_t *window)
{
	for(unsigned int x = 0; x < 1920; ++x) {
		var->c_re = var->MinRe + x * var->Re_factor;
		var->Z_re = var->c_re;
		var->Z_im = var->c_im;
		var->n = 0;
		fractal1_2(var);
		if (var->n < var->Max_it / 2 - 1) {
			my_put_pixel_fractal2(window->framebuffer, x, y, var);
		} else if (var->n >= var->Max_it / 2 && var->n < var->Max_it) {
			my_put_pixel_fractal(window->framebuffer, x, y, var);
		} else
			my_put_pixel_black(window->framebuffer, x, y);
		}
}

int move_fractal1(var_t *var, int d)
{
	if (var->Max_it == 100)
		d = 1;
	else if (var->Max_it == 10)
		d = 0;
	if (d == 1)
		var->Max_it--;
	else if (d == 0) {
		var->Max_it++;
	}
	return (d);
}

int screen_1(var_t *var)
{
	window_t *window = windows_create();
	int d = 0;

	if (!window)
		return (84);
	while (sfRenderWindow_isOpen(window->window)) {
		analyse_event(window);
		for (unsigned int y = 0; y < 1080; ++y) {
			var->c_im = var->MaxIm - y * var->Im_factor;
			fractal1(var, y, window);
		}
		d = move_fractal1(var, d);
		disp_window(window);
	}
	destroy_window(window);
	free (var);
	return (0);
}
