#include "philo.h"

static void	pick_fork(t_round_table *chair);
static void	return_fork(t_round_table *chair);

void	*philo_brain(void *arg)
{
	t_environment	*env;
	t_round_table	*chair;
	static int		current = 0;
	int				i;
	pthread_mutex_t	queue;

	pthread_mutex_init(&queue, NULL);
	pthread_mutex_lock(&queue);
	env = (t_environment *)arg;
	chair = (*env->table);
	i = -1;
	while (++i != current)
		chair = chair->right;
	current++;
	pthread_mutex_unlock(&queue);
	pick_fork(chair);
	usleep(env->s_par.time_to_eat);
	printf("philo %i has finished eating\n", chair->philo.id);
	return_fork(chair);
	return (NULL);
}

static void	pick_fork(t_round_table *chair)
{
	pthread_mutex_lock(&chair->fork);
	printf("philo %i picked fork in front\n", chair->philo.id);
	pthread_mutex_lock(&chair->left->fork);
	printf("philo %i picked fork to the left\n", chair->philo.id);
}

static void	return_fork(t_round_table *chair)
{
	pthread_mutex_unlock(&chair->fork);
	printf("philo %i returned fork in front\n", chair->philo.id);
	pthread_mutex_unlock(&chair->left->fork);
	printf("philo %i returned fork to the left\n", chair->philo.id);
}
