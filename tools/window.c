/*
** EPITECH PROJECT, 2017
** my_screensaver
** File description:
** winow.c
*/

#include "my_screensaver.h"

sfVideoMode get_mode(int w, int h, int bpp)
{
	sfVideoMode mode = { w, h, bpp };

	return (mode);
}

window_t *windows_create(void)
{
	window_t *window = malloc(sizeof(window_t));

	window->mode = get_mode(1920, 1080, 32);
	window->window = sfRenderWindow_create(window->mode, "screensaver",
		sfResize | sfClose, NULL);
	window->framebuffer = framebuffer_create(1920, 1080);
	window->texture = sfTexture_create(1920, 1080);
	window->sprite = sfSprite_create();
	sfRenderWindow_setFramerateLimit(window->window, 30);
	return (window);
}

void analyse_event(window_t *window)
{
	while (sfRenderWindow_pollEvent(window->window, &window->event)) {
		if (window->event.type == sfEvtClosed)
			sfRenderWindow_close(window->window);
	}
}

void disp_window(window_t *window)
{
	sfRenderWindow_clear(window->window, sfBlack);
	sfTexture_updateFromPixels(window->texture, window->framebuffer->pixels,
		1920, 1080, 0, 0);
	sfSprite_setTexture(window->sprite, window->texture, sfTrue);
	sfRenderWindow_drawSprite(window->window, window->sprite, NULL);
	sfRenderWindow_display(window->window);
}

int destroy_window(window_t *window)
{
	framebuffer_destroy(window->framebuffer);
	sfTexture_destroy(window->texture);
	sfSprite_destroy(window->sprite);
	sfRenderWindow_destroy(window->window);
	free (window);
	return (0);
}
