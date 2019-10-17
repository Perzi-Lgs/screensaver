/*
** EPITECH PROJECT, 2017
** my_screensaver
** File description:
** main.c
*/

#include "my_screensaver.h"

int main (int ac, char **av)
{
	if (ac > 2 || ac == 1) {
		wrong_arg();
		return (84);
	}
	for (int i = 1; i < ac; i++) {
		if (av[i][0] == '-')
			return(display_info(av[1]));
		else if (!(av[1][0] > '0' && av[1][0] <= '4'))
			return(display_info(av[1]));
		else
			select_screen(av[1]);
	}
	return (0);
}
