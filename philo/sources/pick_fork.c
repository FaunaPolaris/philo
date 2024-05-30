#include "philo.h"

void	lefthand_philo_pick_fork(t_round_table *chair, pthread_mutex_t mouth)
{
	pthread_mutex_lock(&chair->fork);
	pthread_mutex_lock(&mouth);
	printf("philo %i picked fork in front\n", chair->philo.id);
	pthread_mutex_unlock(&mouth);
	pthread_mutex_lock(&chair->left->fork);
	pthread_mutex_lock(&mouth);
	printf("philo %i picked fork to the left\n", chair->philo.id);
	pthread_mutex_unlock(&mouth);
}

void	lefthand_philo_return_fork(t_round_table *chair, pthread_mutex_t mouth)
{
	pthread_mutex_unlock(&chair->fork);
	pthread_mutex_lock(&mouth);
	printf("philo %i returned fork in front\n", chair->philo.id);
	pthread_mutex_unlock(&mouth);
	pthread_mutex_unlock(&chair->left->fork);
	pthread_mutex_lock(&mouth);
	printf("philo %i returned fork to the left\n", chair->philo.id);
	pthread_mutex_unlock(&mouth);
}

void	righthand_philo_pick_fork(t_round_table *chair, pthread_mutex_t mouth)
{
	pthread_mutex_lock(&chair->right->fork);
	pthread_mutex_lock(&mouth);
	printf("philo %i picked fork to the right\n", chair->philo.id);
	pthread_mutex_unlock(&mouth);
	pthread_mutex_lock(&chair->fork);
	pthread_mutex_lock(&mouth);
	printf("philo %i picked fork in front\n", chair->philo.id);
	pthread_mutex_unlock(&mouth);
}

void	righthand_philo_return_fork(t_round_table *chair, pthread_mutex_t mouth)
{
	pthread_mutex_unlock(&chair->fork);
	pthread_mutex_lock(&mouth);
	printf("philo %i returned fork in front\n", chair->philo.id);
	pthread_mutex_unlock(&mouth);
	pthread_mutex_unlock(&chair->right->fork);
	pthread_mutex_lock(&mouth);
	printf("philo %i returned fork to the right\n", chair->philo.id);
	pthread_mutex_unlock(&mouth);
}
