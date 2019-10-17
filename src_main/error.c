/*
** EPITECH PROJECT, 2017
** my_screensaver
** File description:
** error.c
*/

#include "my_screensaver.h"

int error(char *str)
{
	write(2, "./my_screensaver: '", 19);
	my_putstr(str);
	write(2, "' is not a my_screensaver command. ", 35);
	write(2, "See 'my_screensaver --help'\n", 29);
	return (84);
}



void wrong_arg(void)
{
	my_putstr("Wrong arguments\n");
	my_putstr("See 'my_screensaver --help' for more informations\n");
}
