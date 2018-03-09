/*
** EPITECH PROJECT, 2018
** philosopher
** File description:
** corefile - main
*/

# include "philo.h"

bool	get_arguments(size_t ac, char **av, size_t *nbr_p, size_t *nbr_e)
{
	size_t	i = 1;
	int	p = 0;
	int	e = 0;
	
	while (i < ac) {
		if (!strcmp(av[i], "-p") && av[i + 1])
			p = atoi(av[i + 1]);
		else if (!strcmp(av[i], "-e") && av[i + 1])
			e = atoi(av[i + 1]);
		else
			return (false);
		i += 2;
	}
	if (p < 2 || e < 1)
		return (false);
	*nbr_p = p;
	*nbr_e = e;
	return (true);
}

int	main(int ac, char **av)
{
	size_t	nb;
	size_t	max;

	if (!get_arguments(&nb, &max, av, ac)) {
		write(1, USAGE, 64);
		return (84);
	}
	RCFStartup(ac, av);
	init_philo(nb, max);
	RCFCleanup();
	return (0);
}
