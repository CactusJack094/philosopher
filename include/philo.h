/*
** EPITECH PROJECT, 2018
** philosopher
** File description:
** header - philo
*/

#ifndef PHILO_H_
# define PHILO_H_

# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <unistd.h>
# include "extern.h"

# define USAGE "./philo -p nbr_p -e nbr_e" //il manque le reste


typedef	__SIZE_TYPE__	size_t;
typedef	enum	{false, true}	bool;

enum	e_state
{
	EAT,
	THINK,
	REST
};

typedef	struct	s_philo
{
	size_t	id;
	pthread_t	thread;
	pthread_mutex_t	mutex;
	size_t	rice;
	struct	s_philo	*next;
}t_philo;

void	eat(t_philo *);
void	think(t_philo *);
void	*action(void *);


bool	get_arguments(size_t , char **, size_t *, size_t *);
bool	init_philo(size_t nb, size_t max);

#endif /* !PHILO_H_ */
