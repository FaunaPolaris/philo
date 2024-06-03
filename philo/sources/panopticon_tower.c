#include "philo.h"

int	panopticon_tower(t_environment *env)
{
	int				i;
	int				all_ate;
	t_round_table	*chair;
	struct timeval	tv;

	while (!env->panopticon_start)
		;
	chair = *env->table;
	all_ate = 1;
	if (env->s_par.times_to_eat == -1)
		all_ate = 0;
	i = -1;
	while (++i < env->s_par.number_of_philo)
	{
		if (!chair->philo.alive)
			return (0);
		gettimeofday(&tv, NULL);
		if (tv.tv_sec * 1000 + (int)(tv.tv_usec * .001)
				- chair->philo.last_meal > env->s_par.time_to_die)
		{	
			printf("current time: %li\n", tv.tv_sec * 1000 + (int)(tv.tv_usec * .001));
			printf("last meal   : %li\n", chair->philo.last_meal);
			printf("time since  : %li\n", tv.tv_sec * 1000 + (int)(tv.tv_usec * .001) - chair->philo.last_meal);
			say_state_change("died", chair->philo.id, &env->mouth);
			return (0);
		}
		if (env->s_par.times_to_eat != -1 &&
				chair->philo.ate < env->s_par.times_to_eat)
			all_ate = 0;
		chair = chair->left;
	}
	if (all_ate)
	{
		printf("all ate");
		return (0);
	}
	return (1);
}
