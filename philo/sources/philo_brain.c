#include "philo.h"

static void	prefrontal_cortex(t_environment *env, t_round_table *chair);

void	*philo_brain(void *arg)
{
	t_environment	*env;
	t_round_table	*chair;
	static int		current = 0;
	int				i;
	pthread_mutex_t	parietal_lobe;

	env = (t_environment *)arg;
	while (!env->start_time)
		;
	pthread_mutex_init(&parietal_lobe, NULL);
	pthread_mutex_lock(&parietal_lobe);
	chair = (*env->table);
	i = -1;
	while (++i != current)
		chair = chair->right;
	current++;
	chair->philo.last_meal = env->start_time;
	pthread_mutex_unlock(&parietal_lobe);
	while (1)
		prefrontal_cortex(env, chair);
}

static void	prefrontal_cortex(t_environment *env, t_round_table *chair)
{
	struct timeval	tv;

	if (chair->philo.id % 2 == 0)
		lefthand_philo_pick_fork(chair, &env->mouth);
	else
		righthand_philo_pick_fork(chair, &env->mouth);
	say_state_change("is eating", chair->philo.id, &env->mouth);
	gettimeofday(&tv, NULL);
	chair->philo.last_meal = tv.tv_sec * 1000 + (int)(tv.tv_usec * .001);
	usleep(env->s_par.time_to_eat * 1000);
	chair->philo.ate++;
	if (chair->philo.id % 2 == 0)
		lefthand_philo_return_fork(chair, &env->mouth);
	else
		righthand_philo_return_fork(chair, &env->mouth);
	say_state_change("is sleeping", chair->philo.id, &env->mouth);
	usleep(env->s_par.time_to_sleep * 1000);
	say_state_change("is thinking", chair->philo.id, &env->mouth);
}

