/*
** EPITECH PROJECT, 2017
** my_screensaver
** File description:
** info.c
*/

#include "my_screensaver.h"

void info_help(void)
{
	my_putstr("USAGE: ./my_screensaver [OPTIONS] <ID_number>\n\nThese are");
	my_putstr(" my_screensaver commands used in various situations:\n");
	my_putstr("Get information about the program or the screensaver\n");
	my_putstr("\nOPTIONS\n-");
	my_putstr("d\tprint the description of all the animations and quit.\n");
	my_putstr("-h\tprint the usage and quit.\n");
	my_putstr("\nUSER INTERACTIONS\nNONE\n");
}

void info_d(void)
{
	my_putstr("\n\tDescription of animations\n");
	my_putstr("ID 1: display a random fractal of the Julia's set\n");
	my_putstr("ID 2: display a fractal animation\n");
	my_putstr("ID 3: display the Mandelbrot set a make it move !\n");
}

void info_h(void)
{
	my_putstr("usage: ./my_screensaver [OPTIONS] <ID_number>\n\nThese are");
	my_putstr(" my_screensaver commands used in various situations:\n\n");
	my_putstr("Get information about the program or the screensaver\n-");
	my_putstr("d\tprint the description of all the animations and quit.\n");
}

int display_info(char *str)
{
	int a = 0;

	if (str[1] == 'd' && str[2] == '\0') {
		info_d();
		a++;
	} else if (str[1] == '-' && str[2] == 'h' && str[6] == '\0') {
		info_help();
		a++;
	}
	if (str[1] == 'h' && str[2] == '\0') {
		info_h();
		a++;
	}
	if (a == 0)
		return(error(str));
	else
		return (0);
}
