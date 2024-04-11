#include "philo.h"

static int	pick_fork(t_round_table *chair);
static void	return_fork(t_round_table *chair);

void	*philo_brain(void *arg)
{
	t_environment	*env;
	t_round_table	*chair;
	static int		current = 0;
	int				has_eaten = 0;

	printf("Hello from thread\n");
	env = (t_environment *)arg;
	chair = (*env->table);
	while (chair->philo.id != current)
		chair->philo = chair->right->philo;
	current++;
	while (!has_eaten)
	{
		if (pick_fork(chair))
		{
			printf("philo %i picked forks and is eating\n", chair->philo.id);
			usleep(env->s_par.time_to_eat);
			has_eaten = 1;
		}
		return_fork(chair);
	}
	return (NULL);
}

static int	pick_fork(t_round_table *chair)
{
	if (chair->fork && chair->left->fork)
	{
		chair->left->fork = 0;
		chair->philo.left_hand = 1;
		chair->fork = 0;
		chair->philo.right_hand = 1;
		return (TRUE);
	}
	else if (chair->fork && chair->right->fork)
	{
		chair->right->fork = 0;
		chair->philo.right_hand = 1;
		chair->fork = 0;
		chair->philo.left_hand = 1;
		return (TRUE);
	}
	return (FALSE);
}

static void	return_fork(t_round_table *chair)
{
	if (chair->philo.left_hand)
	{
		chair->left->fork = 1;
		chair->philo.left_hand = 0;
		chair->fork = 1;
		chair->philo.right_hand = 0;
	}
	else if (chair->philo.right_hand)
	{
		chair->right->fork = 1;
		chair->philo.right_hand = 0;
		chair->fork = 1;
		chair->philo.left_hand = 0;
	}
	printf("forks returned\n");
}
