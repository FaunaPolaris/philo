#include "philo.h"

int	panopticon_tower(t_environment *env)
{
	int				i;
	int				all_ate;
	t_round_table	*chair;

	chair = *env->table;
	all_ate = 1;
	i = -1;
	while (++i < env->s_par.number_of_philo)
	{
		if (!chair->philo.alive)
			return (0);
		if (env->s_par.times_to_eat != -1 &&
				chair->philo.ate < env->s_par.times_to_eat)
			all_ate = 0;
		chair = chair->left;
	}
	if (all_ate)
		return (0);
	return (1);
}
