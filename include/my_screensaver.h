/*
** EPITECH PROJECT, 2017
** my_screensaver
** File description:
** my_screensaver.h
*/

#include <unistd.h>
#include <SFML/System>
#include <SFML/Graphics.h>
#include <time.h>
#include <stdlib.h>
//#include "libmy.a"

struct interrupt
{
	int interrupt;
	int counter;
};
typedef struct interrupt int_t;

struct framebuffer {
	unsigned int width;
	unsigned int height;
	sfUint8 *pixels;
};
typedef struct framebuffer framebuffer;

struct window {
	sfVideoMode mode;
	sfRenderWindow* window;
	sfEvent event;
	sfTexture* texture;
	sfSprite* sprite;
	framebuffer *framebuffer;
};
typedef struct window window_t;

struct var_fractal
{
	unsigned Max_it;
	double MinRe;
	double MaxRe;
	double MinIm;
	double MaxIm;
	double Re_factor;
	double Im_factor;
	unsigned int n;
	double c_im;
	double c_re;
	double Z_re;
	double Z_im;
	double Z_re2;
	double Z_im2;
	double a;
	double b;
	int c;
	int d;
};
typedef struct var_fractal var_t;

#ifndef _MY_H
#define _MY_H

void my_putchar(char c);
int error(char *str);
void wrong_arg(void);
void info_help(void);
void info_d(void);
void info_t(void);
int display_info(char *str);
void select_screen(char *str);
int my_putstr(char const *str);
void fractal1_2(var_t *var);
void fractal1(var_t *var, unsigned int y, window_t *window);
int screen_1(var_t *var);
void my_put_pixel(framebuffer *framebuffer, int x, int y);
void my_put_pixel_black(framebuffer *framebuffer, int x, int y);
void my_put_pixel_fractal(framebuffer *framebuffer, int x, int y, var_t *var);
void my_put_pixel_fractal2(framebuffer *framebuffer, int x, int y, var_t *var);
framebuffer *framebuffer_create(unsigned int width, unsigned int height);
void framebuffer_destroy(framebuffer *frame);
void analyse_event(window_t *window);
void disp_window(window_t *window);
int destroy_window(window_t *window);
int random_fractal(void);
int move_fractal1(var_t *var, int d);
int fract_move(void);
int zoom_mande(void);
var_t *init_var();
var_t *init_var_2();
var_t *init_var_3();
int_t *init_tools(void);
window_t *windows_create();
void my_put_pixel_rouge(framebuffer *framebuffer, int x, int y);
void my_put_pixel_bleu(framebuffer *framebuffer, int x, int y);
void my_put_pixel_jaune(framebuffer *framebuffer, int x, int y);
void my_put_pixel_vert(framebuffer *framebuffer, int x, int y);

#endif
