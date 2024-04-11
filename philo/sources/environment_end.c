#include "philo.h"

void	environment_end(t_environment *env)
{
	int				i;
	t_round_table	*temp;
	t_round_table	*next;
	
	i = -1;
	temp = *env->table;
	while (++i < env->s_par.number_of_philo)
	{
		next = temp->right;
		free(temp);
		temp = next;
	}
	free(env->table);
}
