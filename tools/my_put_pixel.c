/*
** EPITECH PROJECT, 2017
** my_screensaver
** File description:
** my_put_pixel.c
*/

#include "my_screensaver.h"

void my_put_pixel(framebuffer *framebuffer, int x, int y)
{
	unsigned int index = y * framebuffer->width * 4 + x * 4;
	framebuffer->pixels[index] = 255;
	framebuffer->pixels[index + 1] = 0;
	framebuffer->pixels[index + 2] = 0;
	framebuffer->pixels[index + 3] = 255;
}

void my_put_pixel_black(framebuffer *framebuffer, int x, int y)
{
	unsigned int index = y * framebuffer->width * 4 + x * 4;
	framebuffer->pixels[index] = 0;
	framebuffer->pixels[index + 1] = 0;
	framebuffer->pixels[index + 2] = 0;
	framebuffer->pixels[index + 3] = 255;
}

void my_put_pixel_fractal(framebuffer *framebuffer, int x, int y, var_t *var)
{
	unsigned int index = y * framebuffer->width * 4 + x * 4;
	framebuffer->pixels[index] = var->n * 205 / var->Max_it;
	framebuffer->pixels[index + 1] = 55;
	framebuffer->pixels[index + 2] = 0;
	framebuffer->pixels[index + 3] = 255;
}

void my_put_pixel_fractal2(framebuffer *framebuffer, int x, int y, var_t *var)
{
	unsigned int index = y * framebuffer->width * 4 + x * 4;
	framebuffer->pixels[index] = var->n * 238 / var->Max_it;
	framebuffer->pixels[index + 1] = 0;
	framebuffer->pixels[index + 2] = 0;
	framebuffer->pixels[index + 3] = 255;
}
