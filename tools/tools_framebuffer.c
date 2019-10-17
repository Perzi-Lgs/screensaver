/*
** EPITECH PROJECT, 2017
** my_screensaver
** File description:
** tools_framebuffer.c
*/

#include "my_screensaver.h"

framebuffer *framebuffer_create(unsigned int width, unsigned int height)
{
	framebuffer *frame = malloc(sizeof(*frame));

	frame->pixels = malloc(width * height * 32 / 8);
	frame->height = height;
	frame->width = width;
	return (frame);
}

void framebuffer_destroy(framebuffer *framebuffer)
{
	free(framebuffer->pixels);
	free(framebuffer);
}
