/*
** EPITECH PROJECT, 2018
** philosopher
** File description:
** core file - action
*/

# include "philo.h"

size_t	id = 0;

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex);
	pthread_mutex_lock(&philo->next->mutex);
	lphilo_take_chopstick(&philo->mutex);
	lphilo_take_chopstick(&philo->next->mutex);
	lphilo_eat();
	lphilo_release_chopstick(&philo->mutex);
	lphilo_release_chopstick(&philo->mutex);
	pthread_mutex_unlock(&philo->mutex);
	pthread_mutex_unlock(&philo->next->mutex);
	--philo->rice;
}

void	think(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex);
	lphilo_take_chopstick(&philo->mutex);
	lphilo_think();
	lphilo_release_chopstick(&philo->mutex);
	pthread_mutex_unlock(&philo->mutex);
}

void	*action(void *data)
{
	t_philo	*philo = data;

	while (philo->rice) {
		if (philo->id % 2 == id)
			continue;
		think(philo);
		eat(philo);
		lphilo_sleep();
	}
	++id;
	return (NULL);
}

bool	init_philo(size_t nb, size_t max)
{
	t_philo	*philo = malloc(sizeof(t_philo) * nb);
	size_t	i = 0;

	if (!philo)
		return (false);
	while (i < nb) {
		philo[i].id = i;
		philo[i].rice = max;
		if (pthread_mutex_init(&philo[i].mutex, NULL) != 0)
			return (false);
		/* if (pthread_create(&philo[i].thread, NULL, */
		/* &action, NULL)!= 0) */
		/* 	return (false); */
		/* if (pthread_join(&philo[i++].thread, NULL) != 0) */
		/* 	return (false); */
		philo[i].next = &philo[(i + 1 % nb)];
		++i;
	}
	free(philo);
	return (true);
}
