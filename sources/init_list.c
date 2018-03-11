/*
** EPITECH PROJECT, 2018
** philosopher
** File description:
** init_list
*/

#include "my.h"
#include <stdlib.h>

t_philosoph	*add_end(t_philosoph *philos, int nb_eat)
{
	t_philosoph	*new_phil = malloc(sizeof(t_philosoph));

	new_phil->chopstick = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
	new_phil->number_of_lunchs = nb_eat;
	new_phil->next = NULL;
	if (philos != NULL) {
		t_philosoph	*tmp = philos;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_phil;
		return (philos);
	}
	return (new_phil);
}

t_philosoph	*init_list(t_philosoph *philos, int nb_phil, int nb_eat)
{
	int	i = 0;
	while (i < nb_phil) {
		philos = add_end(philos, nb_eat);
		i++;
	}
	t_philosoph	*save = philos;
	while (save->next != NULL)
		save = save->next;
	save->next = philos;
	return (philos);
}
