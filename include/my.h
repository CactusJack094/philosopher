/*
** EPITECH PROJECT, 2018
** philosopher
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <pthread.h>

typedef struct s_philosoph
{
	pthread_mutex_t chopstick;
	int number_of_lunchs;
	struct s_philosoph *next;
} t_philosoph;

int get_phil(int, char**);
int get_eat(int, char**);

void start_programm(int, int);
void *philo_actions(void*);
void philo_eat(t_philosoph *);
void philo_think(t_philosoph *);
void philo_sleep(t_philosoph *);

t_philosoph *add_phil(t_philosoph*, int);
t_philosoph *init_list(t_philosoph*, int, int);
void display_list(t_philosoph*);

#endif
