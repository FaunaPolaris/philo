#include "philo.h"

void	lefthand_philo_pick_fork(t_round_table *chair, pthread_mutex_t *mouth)
{
	pthread_mutex_lock(&chair->fork);
	say_state_change("has taken a fork", chair->philo.id, mouth);
	pthread_mutex_lock(&chair->left->fork);
	say_state_change("has taken a fork", chair->philo.id, mouth);
}

void	lefthand_philo_return_fork(t_round_table *chair, pthread_mutex_t *mouth)
{
	pthread_mutex_unlock(&chair->fork);
	say_state_change("has taken a fork", chair->philo.id, mouth);
	pthread_mutex_unlock(&chair->left->fork);
	say_state_change("has taken a fork", chair->philo.id, mouth);
}

void	righthand_philo_pick_fork(t_round_table *chair, pthread_mutex_t *mouth)
{
	pthread_mutex_lock(&chair->right->fork);
	say_state_change("has taken a fork", chair->philo.id, mouth);
	pthread_mutex_lock(&chair->fork);
	say_state_change("has taken a fork", chair->philo.id, mouth);
}

void	righthand_philo_return_fork(t_round_table *chair,
		pthread_mutex_t *mouth)
{
	pthread_mutex_unlock(&chair->right->fork);
	say_state_change("has taken a fork", chair->philo.id, mouth);
	pthread_mutex_unlock(&chair->fork);
	say_state_change("has taken a fork", chair->philo.id, mouth);
}
