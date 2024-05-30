#include "philo.h"

static void	prefrontal_cortex(t_environment *env, t_round_table *chair);

void	*philo_brain(void *arg)
{
	t_environment	*env;
	t_round_table	*chair;
	static int		current = 0;
	int				i;
	pthread_mutex_t	parietal_lobe;

	pthread_mutex_init(&parietal_lobe, NULL);
	pthread_mutex_lock(&parietal_lobe);
	env = (t_environment *)arg;
	chair = (*env->table);
	i = -1;
	while (++i != current)
		chair = chair->right;
	current++;
	pthread_mutex_unlock(&parietal_lobe);
	while (1)
		prefrontal_cortex(env, chair);
	return (NULL);
}

static void	prefrontal_cortex(t_environment *env, t_round_table *chair)
{
	pthread_mutex_t	mouth;

	pthread_mutex_init(&mouth, NULL);
	if (chair->philo.id % 2 == 0)
		lefthand_philo_pick_fork(chair);
	else
		righthand_philo_pick_fork(chair);
	usleep(env->s_par.time_to_eat * 1000);
	pthread_mutex_lock(&mouth);
	printf("philo %i has finished eating\n", chair->philo.id);
	pthread_mutex_unlock(&mouth);
	chair->philo.ate++;
	if (chair->philo.id % 2 == 0)
		lefthand_philo_return_fork(chair);
	else
		righthand_philo_return_fork(chair);
	usleep(env->s_par.time_to_sleep * 1000);
	pthread_mutex_lock(&mouth);
	printf("philo %i has finished sleeping\n", chair->philo.id);
	pthread_mutex_unlock(&mouth);
}
