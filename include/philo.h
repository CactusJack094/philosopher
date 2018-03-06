/*
** EPITECH PROJECT, 2018
** philosopher
** File description:
** header - philo
*/

#ifndef PHILO_H_
# define PHILO_H_

# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include "extern.h"

# define USAGE "./philo -p nbr_p -e nbr_e"

# define R_CUSTOM(x, y) if (x) {return (y);}

typedef	__SIZE_TYPE__	size_t;
typedef	enum	{false, true}	bool;

enum	state
{
	NOT,
	EAT,
	THINK,
	REST
};

typedef	struct	s_philo
{
	size_t	id;
	pthread_t	thread;
	pthread_mutex__t	mutex;
	size_t	rice;
	struct	s_philo	*next;
}t_philo;

bool	init_philo(size_t nb, size_t max);

#endif /* PHILO_H_ */
