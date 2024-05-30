#include "philo.h"

void	lefthand_philo_pick_fork(t_round_table *chair)
{
	pthread_mutex_lock(&chair->fork);
	printf("philo %i picked fork in front\n", chair->philo.id);
	pthread_mutex_lock(&chair->left->fork);
	printf("philo %i picked fork to the left\n", chair->philo.id);
}

void	lefthand_philo_return_fork(t_round_table *chair)
{
	pthread_mutex_unlock(&chair->fork);
	printf("philo %i returned fork in front\n", chair->philo.id);
	pthread_mutex_unlock(&chair->left->fork);
	printf("philo %i returned fork to the left\n", chair->philo.id);
}

void	righthand_philo_pick_fork(t_round_table *chair)
{
	pthread_mutex_lock(&chair->right->fork);
	printf("philo %i picked fork to the right\n", chair->philo.id);
	pthread_mutex_lock(&chair->fork);
	printf("philo %i picked fork in front\n", chair->philo.id);
}

void	righthand_philo_return_fork(t_round_table *chair)
{
	pthread_mutex_unlock(&chair->fork);
	printf("philo %i returned fork in front\n", chair->philo.id);
	pthread_mutex_unlock(&chair->right->fork);
	printf("philo %i returned fork to the right\n", chair->philo.id);
}
