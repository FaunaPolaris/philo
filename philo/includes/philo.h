#ifndef PHILO_H
# define PHILO_H

# define TRUE 1
# define FALSE 0

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef struct s_simulation_params
{
	int	number_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
}	t_simulation_params;

typedef struct s_round_table
{
	int						philo;
	int						fork;
	struct s_round_table	*left;
	struct s_round_table	*right;
}	t_round_table;

typedef struct s_environment
{
	t_round_table		**table;
	t_simulation_params	s_par;
}	t_environment;

void	*mem_calloc(int n, int size);
void	environment_init(t_environment *env, char **argv);
void	put_philo(t_environment env);

#endif
