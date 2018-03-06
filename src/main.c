/*
** EPITECH PROJECT, 2018
** philosopher
** File description:
** corefile - main
*/

# include "philo.h"

bool	get_arguments(size_t ac, char **av, size_t nbr_p, size_t nbr_e)
{
}

int	main(int ac, char **av)
{
	size_t	nb;
	size_t	max;

	RCFStartup(ac, av);
	init_philo(nb, max);
	RCFCleanup();
	return (0);
}
