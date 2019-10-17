/*
** EPITECH PROJECT, 2017
** my_screensaver
** File description:
** zoom_mande.c
*/

#include "my_screensaver.h"

void fractal3_2(var_t *var)
{
	while(var->n < var->Max_it) {
		var->Z_re2 = var->Z_re * var->Z_re;
		var->Z_im2 = var->Z_im * var->Z_im;
		if(var->Z_re2 + var->Z_im2 > 4)
			break;
		var->Z_im = 2 * var->Z_re * var->Z_im + var->c_im;
		var->Z_re = var->Z_re2 - var->Z_im2 + var->c_re;
		var->n++;
	}
}

void fractal3(var_t *var, unsigned int y, window_t *window)
{
	for(unsigned int x = 0; x < 1920; ++x) {
		var->c_re = var->MinRe + x * var->Re_factor;
		var->Z_re = var->c_re;
		var->Z_im = var->c_im;
		var->n = 0;
		fractal3_2(var);
		if (var->n < var->Max_it / 2 - 1) {
			my_put_pixel_fractal2(window->framebuffer, x, y, var);
		} else if (var->n >= var->Max_it / 2 && var->n < var->Max_it) {
			my_put_pixel_fractal(window->framebuffer, x, y, var);
		} else
			my_put_pixel_black(window->framebuffer, x, y);
		}
}

void move_fractal3(var_t *var, int_t *tools)
{
	if (tools->interrupt == 0) {
		var->MinIm += 0.001;
		var->MaxRe -= 0.002;
		var->MinRe += 0.002;
		var->MaxIm = var->MinIm + (var->MaxRe - var->MinRe) * 1080/1920;
		tools->counter--;
	} else {
		var->MinIm -= 0.001;
		var->MaxRe += 0.002;
		var->MinRe -= 0.002;
		var->MaxIm = var->MinIm + (var->MaxRe - var->MinRe) * 1080/1920;
		tools->counter++;
	}
	if (tools->counter == 0)
		tools->interrupt = 1;
	else if (tools->counter == 40) {
		tools->interrupt = 0;
	}
}

int fractal_screen3(var_t *var)
{
	window_t *window = windows_create();
	int_t *tools = init_tools();

	if (!window)
		return (84);
	while (sfRenderWindow_isOpen(window->window)) {
		analyse_event(window);
		for (unsigned int y = 0; y < 1080; ++y) {
			var->c_im = var->MaxIm - y * var->Im_factor;
			fractal3(var, y, window);
		}
		move_fractal3(var, tools);
		disp_window(window);
	}
	destroy_window(window);
	free (var);
	return (0);
}

int zoom_mande(void)
{
	var_t *var = init_var_3();
	return (fractal_screen3(var));
}
