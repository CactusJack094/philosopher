/*
** EPITECH PROJECT, 2018
** philosopher
** File description:
** core file - main
*/

#include "my.h"
#include "extern.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	get_phil(int ac, char **av)
{
	int	i = 0;

	while (i != ac) {
		if (strcmp(av[i], "-p") == 0) {
			if (av[i + 1] != NULL)
				return (atoi(av[i + 1]));
			else
				return (-1);
		}
		i++;
	}
	return (-1);
}

int	get_eat(int ac, char **av)
{
	int	i = 0;

	while (i != ac) {
		if (strcmp(av[i], "-e") == 0) {
			if (av[i + 1] != NULL)
				return (atoi(av[i + 1]));
			else
				return (-1);
		}
		i++;
	}
	return (-1);
}

int	main(int ac, char **av)
{
	int	nb_phil = get_phil(ac, av);
	int	nb_eat = get_eat(ac, av);

	if (nb_phil <= 0 || nb_eat < 0) {
		printf("Wrong parameters\n");
		return (84);
	}
	RCFStartup(ac, av);
	start_programm(nb_phil, nb_eat);
	RCFCleanup();
	return (0);
}
