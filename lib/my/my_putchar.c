/*
** EPITECH PROJECT, 2017
** my_screensaver
** File description:
** main.c
*/

#include <unistd.h>

void my_putchar(char c)
{
	write(1, &c, 1);
}
