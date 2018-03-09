/*
** EPITECH PROJECT, 2018
** philosopher
** File description:
** start_programm
*/

#include "my.h"
#include "extern.h"
#include <unistd.h>

void philo_eat(t_philosoph *philo)
{
	pthread_mutex_lock(&philo->next->chopstick);
	lphilo_take_chopstick(&philo->next->chopstick);
	lphilo_eat();
	usleep(100);
	lphilo_release_chopstick(&philo->next->chopstick);
	lphilo_release_chopstick(&philo->chopstick);
	pthread_mutex_unlock(&philo->next->chopstick);
	philo->number_of_lunchs = philo->number_of_lunchs - 1;
}

void philo_think(t_philosoph *philo)
{
	pthread_mutex_lock(&philo->chopstick);
	lphilo_take_chopstick(&philo->chopstick);
	lphilo_think();
	usleep(100);
	pthread_mutex_unlock(&philo->chopstick);
}

void *philo_actions(void *arg)
{
	t_philosoph *philos = arg;

	for ( ; philos->number_of_lunchs > 0 ; ) {
		philo_think(philos);
		philo_eat(philos);
		lphilo_sleep();
	}
	pthread_exit(NULL);
}

void start_programm(int nb_phil, int nb_eat)
{
	t_philosoph *philos = NULL;
	pthread_t thread[nb_phil];

	philos = init_list(philos, nb_phil, nb_eat);
	for (int i = 0 ; i < nb_phil ; i++) {
		pthread_create(&thread[i], NULL, philo_actions, philos);
		philos = philos->next;
	}
	for (int i = 0 ; i < nb_phil ; i++)
		pthread_join(thread[i], NULL);
}
